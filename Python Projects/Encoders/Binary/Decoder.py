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
            exit("Input not binary: Killing script")
    return(True)
    

        
# this will count how many digits are in the binary
def binQuantity(bin):
    count = 0
    
    for x in str(bin):
        count = count + 1
    return count
    




print(isBinary("1010510"))


if __name__ == "__main__":
    print('')
    print('')
    print('       ----- Start -----')
    print("To end the script, please input anything not binary")
    print('       -----------------')
    def stuff():
        print('')
        print('')
        print('')
        
        binary = input("Please provide binary to decode ")
        binary = binary.strip()
        print('')
        print('')
        
        
        # tell you math about it
        print(f"The number has {binQuantity(binary)} bits")
        
        
        print('')
        print('')
        print('')
        
        # shows said math
        count = ""
        for x in range(binQuantity(binary)):
            print(f"Bit {x} is {binary[x]} which equals {int(binary[x])*2**x}")
            if count != "":
                count = f"{count} + {int(binary[x])*2**x}"
            else:
                count = f"{int(binary[x])*2**x}"
        print(count)
        
        print('')
        print('')
        print('')
        
        
        #Shows solution
        print("The number is:")
        print(binaryDecoder(binary))
        
        print('')
        print('')
        print('')
        print("       ----- NEXT -----")
        stuff()
stuff()