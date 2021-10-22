def binarybot(num): #so it begins!
    #isnumber(num) #may just run this prior
    bits = bitcounter(num)
    print("there will be",bits + 1,"bits") 
    hold = num
    power = bits
    #print("2 powers",2**power)
    binary = ""
    for x in range(bits + 1):
        if hold - 2**power >= 0:
            hold = hold - 2**power
            #print("hold,x",hold,x)
            binary = binary + "1"
            power = power - 1

        else:
            #print("x",x)
            binary = binary + "0"
            power = power - 1
    print(binary)



def isnumber(num): #check if the number input is a number
    if type(num) == int:
        return 1
    else:
        return 0


def bitcounter(num): #how may bits are needed for the number?
    #print(num) #debuging
    bitcheck = num / 2
    #print(bitcheck) # debugging
    bits = 0
    hold = 0
    powers = 0
    while bits <= bitcheck:
        #print(bits) #debug
        hold = hold + 1
        powers = hold
        bits = 2**hold
    #print(powers,"<-- final") # debug thingy
    return powers



#debug land
test = input("Provide a number to turn to binary ")
#print(test.isnumeric())
#isnumber(test)
binarybot(test))
#bitcounter(test)
#isnumber(test)