

#This will check the input to see if it's an int type
#This will return a true or false statement

def isInt(num):
    try:
        type(int(num)) == type(5)
        return True
    except ValueError:
        return False

#This will check the input to see if it's an Float type
#The type must be exclusively a float type or it will return false
#This will return a true or false statement

def isFloat(num):
    try:
        type(float(num)) == type(0.1)
        if float(num) % 1 == 0:
            return False
        else:
            return True
    except ValueError:
        return False


#This will check the input to see if it's a number | Int and/or Float types
#This will return a true or false statementpe

def isNumber(num):
   if isFloat(num) == True or isInt(num) == True:
       return True
   else:
       return False
       



if __name__ == "__main__":

    x = ""

    print("\n\nWe will check if the input is an int type data")
    x = input('What is the data? ')
    print("\n")
    print(f'The data is an int : {isInt(x)}')
    print(f'The data is a float : {isFloat(x)}')
    print(f'The data is a number : {isNumber(x)}')
    print("\n")
    
    pass