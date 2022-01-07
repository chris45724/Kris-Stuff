

#This is taken from school files!
#This modified version is meant to be imported and ran in other programs: It returns less information



def binaryEncode(num): #so it begins!! 
    num = int(num)  # making sure num is an intiger !
    bits = bitcounter(num) # asking the bitcounter how many bits are needed to display the binary
    hold = num # setting hold to num becasue we will be doing math on hold.
    power = bits # same as above but for the bits
    binary = "" # making the binary string
    for x in range(bits + 1): #how many loops we need to do our math for. +1 becasue 2^0 is a thing
        if hold - 2**power >= 0: #if we can subtract 2^ power we do it else see else
            hold = hold - 2**power 
            binary = binary + "1" # adding 1 to the end of the binary string
            power = power - 1 # doing the math for the next power 2^6 --> 2^5

        else: #if we cant subtract we at 0 to the end of the binary string
            binary = str(binary) + "0" 
            power = power - 1 # more math
    return(binary) # this is where we print the binary




#this gets the value of a specfic bit at a spefic power


        

def specBit(num,spec):
    bin = binaryEncode(num)
    return(bin[spec-1])
    



# This will kill the script if an invalid input is input!
def isNumberKill(num): 
    if num.isnumeric() == True: 
        num == int(num)
        return num 

    else:
        exit("Input not a number: Killing script!")




# This checks if the input is a number

def isNumber(num): # we check that the input is a number
    if num.isnumeric() == True: 
        num == int(num) # if it's a number we save it as an int
        return True # pass num

    else:
        return(False)


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


#print(specBit(151,3)) # 10 0 10111

if __name__ == "__main__":
    
    
    print('')
    print('')
    print('       ----- Start -----')
    print("To end the script, please input a non integer")
    print('       -----------------')
    def stuff():
        
        print('')
        print('')
        #print(specBit(151,4)) # 10 0 10111
        #print(binaryEncode(151))
        
        
        print('') #looks nice
        print('')
        test = input("Provide a number to turn to binary ") #asks user for a number
        print('')
        
        
        test = isNumberKill(test) # asks isnumber if num is a number
        test = int(test)
        
        print('')
        print(f"There are {bitcounter(test) + 1} bits in this number")
        print('')
        print('')
        
        print('') # this makes the output more readable
        
        for x in range(int(bitcounter(test) + 1)):
            print(f"The bit at {x} is {specBit(test,x)}")
        print('')
        print('')
        print('')
        print('The binary is:') 
        print(binaryEncode(test)) # we do the stuff here
        print('')
        print('') # we end here
        print('')
        print("       ----- NEXT -----")
        stuff()
    stuff()

        
    
    
