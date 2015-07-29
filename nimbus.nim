import parseopt2
import strutils
import sockets
import osproc
import db_sqlite
import json
import marshal
import parsexml
import httpclient
import random

type
  Profile = object
    name: string
    upvotes: int
    downvotes: int
    rank: string
    

var db = open(connection="ESFJ.db", user="postgres", password="", 
              database="nimforum")
              
db.exec(sql"""
create table if not exists quotes(
  id integer primary key,
  content varchar(1024) not null);
""", [])

db.exec(sql"""
create table if not exists users(
  id integer primary key,
  name varchar(20) not null,
  upvotes integer not null,
  downvotes integer not null,
  rank integer not null,
  pass varchar(30) not null);
""", [])



proc version(): string =
    result = "v1.0.0"

proc about(): string =
    result = "ESFJ - By Cryptotoad (" & version() & ")"


proc chansplit(raw: string): seq[string] =
    result = @[]

    for channel in split(raw, ","):
        add(result, "#" & channel)

    
proc getNick(raw: string): string =
    result = raw[1 .. (find(raw, '!') - 1)]

var server: string = "irc.freenode.net"
var loggedIn: seq[string] = @[""]
var port: Port = 6667.Port
var username: string = "FoxMcCloud"
var nick: string = "ESFJ"
var channels: seq[string] = @["#reddit-intp"]
var log: File
var islogging: bool = false
var outputting: bool = true
var profiles: seq[Profile]

var sock: Socket = socket()
var buffer: string = ""

connect(sock, server, port)

send(sock, "NICK " & nick & "\r\n")
send(sock, "USER " & nick & " " & nick & " " & nick & " :ESFJ IRC\r\n")
send(sock, "MODE " & nick & " +i\r\n")


#Begin user system code

proc isLoggedIn(name: string): bool =
  for i in countup(0, loggedIn.high):
    if cmpIgnoreCase(loggedIn[i], name) == 0:
      result = true
      return
  result = false
  
proc checkUser(name: string): bool =
  try:
    let res = db.getValue(sql"select id from users where upper(name) = ?", toUpper(name))
    if res != "":
      let row = parseInt(res)
      if row > 0:
        result = true
      else:
        result = false
  except:
    result = false
    
proc getQuote(id: int): string =
  let row = db.getRow(sql"select id, content from quotes where id = ?", id)
  if row[0] == "": #id does not exist
    return ""
  return "Quote #" & row[0] & " : " & row[1]

proc addQuote(content: string): int = #add a quote to the database, return the row ID
  result = tryInsertID(db, sql"insert into quotes(id, content) values (null, ?)", content).int

proc addUser(name: string, pass: string): int =
  if not checkUser(name):
    result = tryInsertID(db, sql"insert into users(id, name, upvotes, downvotes, rank, pass) values (null, ?, 0, 0, 0, ?)", name, pass).int
  else:
    return -1

proc getQuoteCount(): int =
  result = parseInt(db.getValue(sql"select count(*) from quotes"))



proc loginUser(name: string, pass: string): bool =
  let row = parseInt(db.getValue(sql"select id from users where upper(name) = ? and pass = ?", toUpper(name), pass))
  if row > 0:
    result = true
  else:
    result = false

proc upvote(name: string): int =
  db.exec(sql"""
  update users set upvotes = upvotes + 1 where upper(name) = ?;
  """,  toUpper(name))
  let totalVotes = db.getValue(sql"select upvotes - downvotes from users where upper(name) = ?", toUpper(name))
  if totalVotes == "":
    result = -1
  else:
    result = parseInt(totalVotes)


proc downvote(name: string): int =
  db.exec(sql"""
  update users set downvotes = downvotes + 1 where upper(name) = ?;
  """,  toUpper(name))
  let totalVotes = db.getValue(sql"select upvotes - downvotes from users where upper(name) = ?",  toUpper(name))
  if totalVotes == "":
    result = -1
  else:
    result = parseInt(totalVotes)

proc karma(name: string): int =
  try:
    result = parseInt(db.getValue(sql"select upvotes - downvotes from users where upper(name) = ?",  toUpper(name)))
  except:
    result = -1
#End user system code


while true:
    readLine(sock, buffer)

    if islogging:
        writeln(log, buffer)

    if outputting:
        echo(buffer)

    if buffer == (":" & nick & " MODE " & nick & " :+i"):
        break

for channel in channels:
    send(sock, "JOIN " & channel & "\r\n")

while true:
    readLine(sock, buffer)

    if buffer == "":
        echo("connection is closed")
        break

    if islogging:
        writeln(log, buffer)

    var ircmsg = split(buffer, " ")

    if outputting:
        echo($ircmsg)

    if ircmsg[0] == "PING":
        send(sock, "PONG " & ircmsg[1] & "\r\n")

    elif ircmsg[1] == "PRIVMSG":
        var nick: string = getNick(ircmsg[0])
        

          
        if ircmsg[3] == ":!roll":
          if ircmsg.high < 4:
            send(sock, "PRIVMSG " & ircmsg[2] & "Please enter a formula (1d20) " & "\r\n")
          else:
            var formula = ircmsg[4]
            var formula2 = split(formula, {'d'})
            try:
              var diceResult: int
              diceResult = 0
              if parseInt(formula2[0]) > 200:
                send(sock, "PRIVMSG " & ircmsg[2] & " : Don't roll that many dice! Why would you need to?!??! \r\n")
              else:
                for i in countup(1, parseInt(formula2[0])):
                  diceResult = diceResult + randomInt(1, parseInt(formula2[1]) + 1)
                send(sock, "PRIVMSG " & ircmsg[2] & " :" & nick & " rolled a " & $diceResult & "! \r\n")
            except:
              send(sock, "PRIVMSG " & ircmsg[2] & " : Please use smaller / positive / whole) numbers! \r\n")

        if ircmsg[3] == ":!upvote":
          if ircmsg.high >= 4 and isLoggedIn(nick) and toUpper(ircmsg[4]) != toUpper(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :You have upvoted " & ircmsg[4] & " Bringing them to " & $upvote(ircmsg[4]) & " upvotes.\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :You cannot upvote unless you are logged in, you cannot upvote yourself, and you must specify a recipient!\r\n")

        if ircmsg[3] == ":!downvote":
          if ircmsg.high >= 4 and isLoggedIn(nick) and toUpper(ircmsg[4]) != toUpper(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :You have downvoted " & ircmsg[4] & " Bringing them to " & $downvote(ircmsg[4]) & " downvotes.\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :You cannot downvote unless you are logged in, you cannot downvote yourself, and you must specify a recipient!\r\n")

        if ircmsg[3] == ":!karma":
          if ircmsg.high >= 4 and isLoggedIn(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :" & ircmsg[4] & " has a total of " & $karma(ircmsg[4]) & " karma.\r\n")
          
        if ircmsg[3] == ":!login":
          if ircmsg.high < 4:
            send(sock, "PRIVMSG " & nick & " : Please enter a password! \r\n")
          else:
            if(loginUser(nick, ircmsg[4])):
              loggedIn.add(nick)
              send(sock, "PRIVMSG " & nick & " : You have logged in successfully! \r\n")
            else:
              send(sock, "PRIVMSG " & nick & " : Invalid password! \r\n")
          
        if ircmsg[3] == ":!register":
          if ircmsg.high == 4:
            if adduser(nick, ircmsg[4]) > 0:
              send(sock, "PRIVMSG " & nick & " : Your pass is " & ircmsg[4] & " \r\n")
            else:
              send(sock, "PRIVMSG " & nick & " : Username is taken. \r\n")  
          else:
            let pass = randomInt(10000, 99999)
            if adduser(nick, $pass) > 0:
              send(sock, "PRIVMSG " & nick & " : Your randomly generated pass is " & $pass & " \r\n")
            else:
              send(sock, "PRIVMSG " & nick & " : Username is taken. \r\n")     
        
        if ircmsg[3] == ":!help":
          send(sock, "PRIVMSG " & ircmsg[2] & " :!quote # - Retrieve quote / !addquote <quote> - adds a quote to database\r\n")
          send(sock, "PRIVMSG " & ircmsg[2] & " :!roll <1d20> - Dice roller / !help - this menu\r\n")

        if ircmsg[3] == ":!quote":
          if(ircmsg.high >= 4):
            try:
              send(sock, "PRIVMSG " & ircmsg[2] & " :" & getQuote(parseInt(ircmsg[4])) & "\r\n")
            except:
              send(sock, "PRIVMSG " & ircmsg[2] & " :No... Bad human...\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :" & getQuote(randomInt(1, getQuoteCount() + 1)) & "\r\n")

        if ircmsg[3] == ":!addquote":
          if(ircmsg.high >= 4):
            let id = addQuote(join(ircmsg[4 .. ircmsg.high], " "))
            send(sock, "PRIVMSG " & ircmsg[2] & " :Quote #" & $id & " added!\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :Please enter a quote.\r\n")


        if ircmsg[3] == ":!rawsql":
          if(ircmsg.high >= 4) and isLoggedIn("Cryptotoad") and toLower(nick) == "cryptotoad":
            send(sock, "PRIVMSG " & ircmsg[2] & " :Result: " & $db.tryExec(sql(join(ircmsg[4 .. ircmsg.high], " "))) & "\r\n")



        #if contains(join(ircmsg[3 .. ircmsg.high], " "), "ESFJ"):
          #send(sock, "PRIVMSG " & ircmsg[2] & " :I am an IRC bot coded by Cryptotoad. Use !help to see commands. I love you.\r\n")

        #if contains(join(ircmsg[3 .. ircmsg.high], " "), " sad "):
          #send(sock, "PRIVMSG " & ircmsg[2] & " :Cheer up! ESFJ loves you!\r\n")
          
        if startsWith(ircmsg[3],  ":http") or startsWith(ircmsg[3],  ":https"):
          var linkTitle: string
          try:
            delete(ircmsg[3], 0, 0)
            echo ircmsg[3]
            linkTitle = getContent(ircmsg[3])
            echo 1
            linkTitle = split(linkTitle, "<title>")[1]
            echo 2
            linkTitle = split(linkTitle, "</title>")[0]
            echo linkTitle
            send(sock, "PRIVMSG " & ircmsg[2] & " :" & linkTitle & " - " & ircmsg[3] & " - URL Preview\r\n")
          except:
            linkTitle = "N/A"
            echo "err!"

          
        if contains(join(ircmsg[3 .. ircmsg.high], " "), "meme") or contains(join(ircmsg[3 .. ircmsg.high], " "), "newfag") or contains(join(ircmsg[3 .. ircmsg.high], " "), "triforce"):
          send(sock, "PRIVMSG " & ircmsg[2] & " : ▲\r\n")
          send(sock, "PRIVMSG " & ircmsg[2] & " :▲ ▲\r\n")

        if ircmsg[3] == ":!v":
          send(sock, "PRIVMSG " & ircmsg[2] & " :" & about() & "\r\n")
          
        

        
close(log)
close(sock)