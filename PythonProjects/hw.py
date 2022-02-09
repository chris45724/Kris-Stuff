print("We will be adding all numbers below the input")


number = int(input("Please input a number: "))
print(f'My prediction is {(number)}')
val = int(0)

words = "Equation is: 0"

for x in range(number):
    val = x + val
    
    
    if x == 0:
        words = words
    else:
        words = words+" + "+str(x)
    
    print(words)
    print(val)