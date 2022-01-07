def binarybot(num): #so it begins!! 
    num = int(num)  # making sure num is an intiger !
    bits = bitcounter(num) # asking the bitcounter how many bits are needed to display the binary
    print("there will be",bits + 1,"bits") # telling you how many total bits are needed for the number
    hold = num # setting hold to num becasue we will be doing math on hold.
    power = bits # same as above but for the bits
    binary = "" # making the binary string
    for x in range(bits + 1): #how many loops we need to do our math for. +1 becasue 2^0 is a thing
        if hold - 2**power >= 0: #if we can subtract 2^ power we do it else see else
            hold = hold - 2**power 
            print("1",'bit',power) #print where we are in the terminal
            binary = binary + "1" # adding 1 to the end of the binary string
            power = power - 1 # doing the math for the next power 2^6 --> 2^5

        else: #if we cant subtract we at 0 to the end of the binary string
            print("0",'bit',power)
            binary = str(binary) + "0" 
            power = power - 1 # more math
    print('') # this makes the output more readable
    print('')
    print('The binary is') 
    print(binary) # this is where we print the binary
    print('')
    print('') # we end here



def isnumber(num): # we check that the input is a number
    if num.isnumeric() == True: 
        num == int(num) # if it's a number we save it as an int
        return num # pass num

    else:
        exit('please provide a whole number next time!') # if it's not a whole number we cant save it as an int, so we cry


def bitcounter(num): #this will provide the amount of bits needed to display the number. unless the number is one than it adds an extra 0 because im lazy
    bitcheck = num / 2 # this is a very lazy way to get the needed bits
    bits = 0     # setting bits to zero becasue we start counting there
    hold = 0    # this is where we do math
    powers = 0   # same as above... should get deleted and replaced with hold
    while bits <= bitcheck: # while our bits are less than or equal to the requierd bits we add one to them
        hold = hold + 1     
        powers = hold     # i could just print hold, but it's too late, and i dont want bugs
        bits = 2**hold    
    return powers # returns powers. see ^^^


#debug land
def main(): #this is the script
    print('') #looks nice
    print('')
    test = input("Provide a number to turn to binary ") #asks user for a number
    print('')
    print('')
    test = isnumber(test) # asks isnumber if num is a number
    binarybot(test) # we do the stuff here



if __name__ == "__main__":
    main() #here be program