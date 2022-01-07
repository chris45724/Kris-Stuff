def binaryDecoder():
    pass


def isnumber(num): # we check that the input is a number
    if num.isnumeric() == True: 
        num == int(num) # if it's a number we save it as an int
        return num # pass num

    else:
        exit('please provide a whole number next time!') # if it's not a whole number we cant save it as an int, so we cry






if __name__ == "__main__":
    binaryDecoder() #here be program