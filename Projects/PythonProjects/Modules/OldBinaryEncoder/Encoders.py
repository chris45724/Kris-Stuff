from Kris import *

#This is taken from school files!
#This modified version is meant to be imported and ran in other programs: It returns less information



def binaryEncode(num : int): #so it begins!! 
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


#Is number is moved to KrisModules

#def isNumber(num): # we check that the input is a number
#    if num.isnumeric() == True: 
#        num == int(num) # if it's a number we save it as an int
#        return True # pass num
#
#    else:
#        return(False)


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




#from .Encoder import specBit


# this turns binary into a number!

def binaryDecoder(bin):
    power = binQuantity(bin) - 1
    num = 0
    for x in str(bin):
        if x == str(1):

            num = num + 2**power
        #else:
            #num = num
        
        power = power - 1
    return(num)
        

def isBinary(bin):
    #length = binCounter(bin)
    
    for x in str(bin):
        if x != str(0) and x != str(1):
            return(False)
    return(True)

def isBinaryKill(bin):
    #length = binCounter(bin)
    
    for x in str(bin):
        if x != str(0) and x != str(1):
            exit(f"Input not binary: Killing script")
    return(True)
    

        
# this will count how many digits are in the binary
def binQuantity(bin):
    count = 0
    
    for x in str(bin):
        count = count + 1
    return count
    
def headZeroDeleter(binary):
    start = False
    hold = ""
    for x in binary:
        if start == False and x == '0':
            pass
        else: 
            start = True
            hold = f"{hold}{x}"
    return hold


if __name__ == '__main__':
    print(binaryEncode(8))
