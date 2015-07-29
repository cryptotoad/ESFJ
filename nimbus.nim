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
include UserSystem

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
        
        #!v
        if ircmsg[3] == ":!v":
          send(sock, "PRIVMSG " & ircmsg[2] & " :" & about() & "\r\n")
          
        #!roll
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
              
        #!upvote
        if ircmsg[3] == ":!upvote":
          if ircmsg.high >= 4 and isLoggedIn(nick) and toUpper(ircmsg[4]) != toUpper(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :You have upvoted " & ircmsg[4] & " Bringing them to " & $upvote(ircmsg[4]) & " upvotes.\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :You cannot upvote unless you are logged in, you cannot upvote yourself, and you must specify a recipient!\r\n")
            
        #!downvote
        if ircmsg[3] == ":!downvote":
          if ircmsg.high >= 4 and isLoggedIn(nick) and toUpper(ircmsg[4]) != toUpper(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :You have downvoted " & ircmsg[4] & " Bringing them to " & $downvote(ircmsg[4]) & " downvotes.\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :You cannot downvote unless you are logged in, you cannot downvote yourself, and you must specify a recipient!\r\n")

        #!karma
        if ircmsg[3] == ":!karma":
          if ircmsg.high >= 4 and isLoggedIn(nick):
            send(sock, "PRIVMSG " & ircmsg[2] & " :" & ircmsg[4] & " has a total of " & $karma(ircmsg[4]) & " karma.\r\n")

        #!login     
        if ircmsg[3] == ":!login":
          if ircmsg.high < 4:
            send(sock, "PRIVMSG " & nick & " : Please enter a password! \r\n")
          else:
            if(loginUser(nick, ircmsg[4])):
              loggedIn.add(nick)
              send(sock, "PRIVMSG " & nick & " : You have logged in successfully! \r\n")
            else:
              send(sock, "PRIVMSG " & nick & " : Invalid password! \r\n")
        #!register          
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

        #!help        
        if ircmsg[3] == ":!help":
          send(sock, "PRIVMSG " & ircmsg[2] & " :!quote # - Retrieve quote / !addquote <quote> - adds a quote to database\r\n")
          send(sock, "PRIVMSG " & ircmsg[2] & " :!roll <1d20> - Dice roller / !help - this menu\r\n")

        #!quote
        if ircmsg[3] == ":!quote":
          if(ircmsg.high >= 4):
            try:
              send(sock, "PRIVMSG " & ircmsg[2] & " :" & getQuote(parseInt(ircmsg[4])) & "\r\n")
            except:
              send(sock, "PRIVMSG " & ircmsg[2] & " :No... Bad human...\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :" & getQuote(randomInt(1, getQuoteCount() + 1)) & "\r\n")

        #!addquote
        if ircmsg[3] == ":!addquote":
          if(ircmsg.high >= 4):
            let id = addQuote(join(ircmsg[4 .. ircmsg.high], " "))
            send(sock, "PRIVMSG " & ircmsg[2] & " :Quote #" & $id & " added!\r\n")
          else:
            send(sock, "PRIVMSG " & ircmsg[2] & " :Please enter a quote.\r\n")

        #!rawsql
        if ircmsg[3] == ":!rawsql":
          if(ircmsg.high >= 4) and isLoggedIn("Cryptotoad") and toLower(nick) == "cryptotoad":
            send(sock, "PRIVMSG " & ircmsg[2] & " :Result: " & $db.tryExec(sql(join(ircmsg[4 .. ircmsg.high], " "))) & "\r\n")



        #if contains(join(ircmsg[3 .. ircmsg.high], " "), "ESFJ"):
          #send(sock, "PRIVMSG " & ircmsg[2] & " :I am an IRC bot coded by Cryptotoad. Use !help to see commands. I love you.\r\n")

        #if contains(join(ircmsg[3 .. ircmsg.high], " "), " sad "):
          #send(sock, "PRIVMSG " & ircmsg[2] & " :Cheer up! ESFJ loves you!\r\n")

        #link detection         
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

        #text buzzwords          
        if contains(join(ircmsg[3 .. ircmsg.high], " "), "meme") or contains(join(ircmsg[3 .. ircmsg.high], " "), "newfag") or contains(join(ircmsg[3 .. ircmsg.high], " "), "triforce"):
          send(sock, "PRIVMSG " & ircmsg[2] & " : ▲\r\n")
          send(sock, "PRIVMSG " & ircmsg[2] & " :▲ ▲\r\n")

          
        

        
close(log)
close(sock)