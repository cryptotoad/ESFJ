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

proc getWeapon(user: string): int =
  result = parseInt(db.getValue(sql"select weapon from users_loot where id = ?", userID(user)))


proc getArmor(user: string): int =
  result = parseInt(db.getValue(sql"select armor from users_loot where id = ?", userID(user)))


proc getShield(user: string): int =
  result = parseInt(db.getValue(sql"select shield from users_loot where id = ?", userID(user)))


proc getBag(user: string): string =
  result = db.getValue(sql"select bag from users_loot where id = ?", userID(user))

proc hasItem(item: int, user: string): bool =
  result = db.tryExec(sql"select id from users_loot where id=? and bag like '%,?,%", userID(user), item)

proc removeItem(item: int, user: string): bool =
  var bag: string
  
  bag = getBag(user)

  bag = replace(bag, "," & $item & ",", ",")

  bag = replace(bag, ",,", ",")
  
  result = db.tryExec(sql"""
  update users_loot set bag = ? where id = ?;
  """,  item, userID(user))

proc itemID(item: string): int =
  result = parseInt(db.getValue(sql"select id from items where upper(name) = ?", toUpper(item)))

proc isWeapon(item: int): bool =
  result = db.tryExec(sql"select name from items where id=? and armor=null", item)

proc setWeapon(item: int, user: string) =
  discard db.tryExec(sql"""
  update users_loot set weapon = ? where id = ?;
  """,  item, userID(user))

proc setArmor(item: int, user: string) =
  discard db.tryExec(sql"""
  update users_loot set armor = ? where id = ?;
  """,  item, userID(user))
  
  
proc equipItem(item: int, user: string) =
  if hasItem(item, user):
    if removeItem(item, user):
      if isWeapon(item):
        setWeapon(item, user)
      else:
        setArmor(item, user)



proc getItemBonus(item: int): int =
  if item == 0:
    result = 0
  else:  
    result = parseInt(db.getValue(sql"select rank from items where id = ?", item))

proc getItemName(item: int): string =
  if item == 0:
    result = "fists"
  else:  
    result = db.getValue(sql"select name from items where id = ?", item)

proc getDefenseBonus(user: string): int =
  result = getItemBonus(getArmor(user)) + getItemBonus(getShield(user)) 

proc getAttackBonus(user: string): int =
  result = getItemBonus(getWeapon(user))

proc battleUsers(user1: string, user2: string): string =
  var battleOutcome: string
  var user1dam: int
  var user2dam: int

  let user1def = getDefenseBonus(user1)
  let user2def = getDefenseBonus(user2)
  
  let user1att = getAttackBonus(user1)
  let user2att = getAttackBonus(user2)

  let user1att5 = getAttackBonus(user1) + 5
  let user2att5 = getAttackBonus(user2) + 5

  let AC1 = 10 + user2def
  let AC2 = 10 + user1def

  battleOutcome = ""

  if randomInt(1,21 + user1att) > AC1:
    user1dam = randomInt(1,user1att5)
    battleOutcome = user1 & " Has hit " & user2 & " for " & $user1dam & " damage! "
  else:
    user1dam = 0

  if randomInt(1,21 + user2att) > AC2:
    user2dam = randomInt(1,user2att5)
    battleOutcome = battleOutcome & " " & user2 & " Has hit " & user1 & " for " & $user2dam & " damage! "
  else:
    user2dam = 0

  if user2dam == user1dam:
    battleOutcome = battleOutcome & "The battle has ended in a draw!"  
  elif user2dam > user1dam:
    battleOutcome = battleOutcome & " " & user2 & " is victorious and has stolen karma from the loser!"  
    discard downvote(user1)
    discard upvote(user2)
  elif user1dam > user2dam:
    battleOutcome = battleOutcome & " " & user1 & " is victorious and has stolen karma from the loser!"  
    discard downvote(user2)
    discard upvote(user1)

  result = battleOutcome


proc doesUserGetDrop(msg: string, user: string): bool =
  if checkBlacklist(user):
    return false
    
  if randomInt(1,200) == 1:
    result = true    
  else:
    result = false

proc generateLootDrop(user: string, rare: bool): int =
  var rank: int
  
  if rare:
    rank = randomInt(1, 4)
  else:
    rank = 1
    
  let rows = db.getAllRows(sql"select id from items where rank = ?", rank)

  let randomItem = rows[randomInt(0, rows.high)][0]
  result = parseInt(randomItem) 

proc addUserLoot(user: int, item: int): bool =
  result = db.tryExec(sql"""
  update users_loot set bag = bag + ? + ',' where id = ?;
  """,  item, user)


