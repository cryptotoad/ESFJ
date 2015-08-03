import parseopt2
import strutils
import sequtils
import sockets
import osproc
import db_sqlite
import json
import marshal
import parsexml
import httpclient
import random
#Begin user system code    


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

var sock: Socket = socket()
var buffer: string = ""



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
  pass varchar(30) not null,
  loot varchar(300));
""", [])

db.exec(sql"""
create table if not exists users_loot(
  id integer primary key, 
  weapon integer, 
  armor integer, 
  shield integer, 
  bag varchar(1024))""", [])


connect(sock, server, port)

send(sock, "NICK " & nick & "\r\n")
send(sock, "USER " & nick & " " & nick & " " & nick & " :ESFJ IRC\r\n")
send(sock, "MODE " & nick & " +i\r\n")

proc intToItem(itemID: int): string =
  case itemID
  of 1:
    result = "flaming"
  else:
    result = "none"

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

proc checkBlacklist(name: string): bool =
  try:
    let res = db.getValue(sql"select id from blacklist where upper(name) = ?", toUpper(name))
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
    result = tryInsertID(db, sql"insert into users(id, name, upvotes, downvotes, rank, pass, loot) values (null, ?, 0, 0, 0, ?, '')", name, pass).int
  else:
    return -1

proc getQuoteCount(): int =
  result = parseInt(db.getValue(sql"select count(*) from quotes"))



proc loginUser(name: string, pass: string): bool =
  try:
    let row = parseInt(db.getValue(sql"select id from users where upper(name) = ? and pass = ?", toUpper(name), pass))
    if row > 0:
      result = true
    else:
      result = false
  except:
    result = false


proc logoutUser(name: string): bool =
  if isLoggedIn(name):
    for i in countup(0, loggedIn.high):
      if cmpIgnoreCase(loggedIn[i], name) == 0:
        loggedIn.delete(i, i)
        result = true
        return
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
    
proc userID(name: string): int =
  try:
    result = parseInt(db.getValue(sql"select id from users where upper(name) = ?",  toUpper(name)))
  except:
    result = -1
#End user system code