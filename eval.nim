proc eval(): auto =
 result = "hello"
when compiles(echo eval()): echo eval()
else: eval()
