


def lazy():
    word1 = "Move Forward"
    word2 = "Turn Right"
    order = []
    count = 0
    
    while 1 == 1:
        count = count + 1
        print('')
        print('')
        print(order)
        print('')
        print('')
        button = str(input(f"Press 1 for {word1}, Press 2 For {word2} "))
        print(button)
        if button == "1":
            hold = input('Distance? ')
            hold = f"{word1} {hold}"
            order.append(f"{count}:{hold}")
        elif button == "2":
            order.append(f"{count}:{word2}")
        else:
            print('error')

        
    
def lazy2():
    word1 = "Move Forward"
    word2 = "Turn Left"
    order = []
    count = 0
    
    while 1 == 1:
        count = count + 1
        print('')
        print('')
        print(order)
        print('')
        print('')
        hold = input('Distance? ')
        hold = f"{word1} {hold}"
        order.append(f"{count}:{hold}")
        count = count + 1
        order.append(f"{count}:{word2}")
        
def arrayMath(number):
    number = float(number)
    hold = (((number**2)-(2*number))/((number**2)-(4)))
    return(hold)



while True:
    x=input("Math ")
    print(arrayMath(x))