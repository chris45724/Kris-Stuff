

#This will check the input to see if it's an int type
#This will return a true or false statement

def isInt(num):
    try:
        type(int(num)) == type(int(5))
        if float(num) % 1 == 0:
            return True
        else:
            return False
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
#This will return a true or false statement's

def isNumber(num):
   if isFloat(num) == True or isInt(num) == True:
      return True
   else:
       return False
   
   
   
# This function returns a list of all the factors excluding 1 and the number
# The numbers returned are in list format!
def wholeQuotient(num):
    values = list()
    
    for x in range(num):
        try:
            if(num % x) == 0:
                values.append(int(x))
        except ZeroDivisionError:
            pass
    return values
       

# this is to find the greatest common factor of the numbers

def commonFactor(num1,num2):
    
    gcf = list() # Greatest common factors
    
    if isNumber(num1) == True:
        num1 = wholeQuotient(num1)
    
    if isNumber(num2) == True:
        num2 = wholeQuotient(num2)
        
    for x in list(num1):
        for i in list(num2):
            if x == i:
                gcf.append(x)
    
    

    
    return gcf
    
'''
# THIS IS INCOMPLETE

# this will factor a number (Intend for a polynomial)
# intended to be used on standard monomials

def factorizer(mid, last, first=1):
    
    #mid add list is all numbers that add to be mid
    
    
    lastFactors = wholeQuotient(last)
    
    mid = int(mid)
    
    for x in range(mid):
        #print(mid-(x+1))
        #print(x+1)
        
        for i in lastFactors:
            if i == (x+1):
                
                if (mid-i) == (last/i):
                    print(i)
                

        
        
    numFactors = wholeQuotient(mid)
    
    
    
    pass
'''

#This returns a true or false depending on if the number provided is prime
def isPrimeNumber(num):
    isPrime = True
    for x in range(num):
        try:
            if( (num % x) == 0 and ((x < num) and (x > 1)) ):
                isPrime = False
                break
        except ZeroDivisionError:
            pass
            
    return isPrime

#This will generate a list of primenumbers between the given values
#Returns a list of prime numbers with
def primeGenerator(cycles,startNum=0):
    listOfPrimes = []
    for i in range(cycles):
        if isPrimeNumber(i+startNum):
            listOfPrimes.append(i+startNum)
    try:
        listOfPrimes.remove(0) # zero must be removed as it passes the zero devision error without being set to false
    except ValueError:
        pass
    return listOfPrimes

# This will return all numbers that can add to be num
# The numbers returned are in list format!
def allSums(num):
    num = int(num)
    
    sums = list()
    
    for x in range(num):
        sums.append(f"{num-(x+1)} + {x+1} = {num}")
        
    return sums
        




if __name__ == "__main__":
    print("Running")
    y = int(input("Please provide a number: "))
    num = list(primeGenerator(y))
    print(f'There are {len(num)} prime numbers in this list!')
    print('\n\n',num)
    
    
    pass