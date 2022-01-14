
test = "apple_sauce"

binary = "00110101"
start = False
hold = ""
for x in binary:
    if start == False and x == '0':
        pass
    else: 
        start = True
        hold = f"{hold}{x}"
    print(f"binary:{binary}   bina:{hold}")
    