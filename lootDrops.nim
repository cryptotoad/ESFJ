import random
include UserSystem

proc generateLootDrop(user: string, rare: bool): int =
  if rare:
    let rank = randomInt(1, 4)
    let rows = db.getAllRows(sql"select id from items where rank <= ?", rank)

    let randomItem = rows[randomInt(0, rows.high)][0]
    result = parseInt(randomItem)
    return 
  else:
    let rank = 1
    let rows = db.getAllRows(sql"select id from items where rank = ?", rank)

    let randomItem = rows[randomInt(0, rows.high)][0]
    result = parseInt(randomItem)
    return 

proc addUserLoot(user: string, item: int): bool =
  db.exec(sql"""
  update users_loot set upvotes = upvotes + 1 where upper(name) = ?;
  """,  toUpper(name))
  result = true