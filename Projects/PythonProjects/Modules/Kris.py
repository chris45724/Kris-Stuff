'''
TO IMPORT FROM HERE

import sys
sys.path.append('Projects\PythonProjects\Modules')
import kris || from kris import ____


'''

'''
DEMO Doc

def demo(a,b=3)
"""
    [Summary]
    
    ### Paramaters:
    1: a : str
        - [description]
    2: *b : int, (default 5)
        - [description]
    
    ### Returns:
        - Any
            - [description]
    Raises
    -----
    - ValueError
        - [description]   
"""
'''







import socket
import os
import sys

class NegativeValue(Exception):
    """The function was expecting a positive value, but received a negative one instead"""
    pass
#This will check the input to see if it's an int type
#This will return a true or false statement

def isInt(input):
    """
    ### Paramaters:
    input : Any
        - will evaluate input to see if it is an int
        
    ### Returns:
        - Bool
            - Returns True if float, 
            - Returns False if any other class 
    """
    try:
        type(int(input)) == type(int(5))
        if float(input) % 1 == 0:
            return True
        else:
            return False
    except ValueError:
        return False

#This will check the input to see if it's an Float type
#The type must be exclusively a float type or it will return false
#This will return a true or false statement

def isFloat(num):
    """
    ### Paramaters:
    input : Any
        - will evaluate input to see if it is a float
        
    ### Returns:
        - Bool
            - Returns True if float, 
            - Returns False if any other class 
    """
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
#"""Test"""
def isNumber(num):
    """
    ### Paramaters:
    input : Any
        - will evaluate input to see if it's a number (int/float)
        
    ### Returns:
        - Bool
            - Returns True if int / float, 
            - Returns False if any other class 
    """
    if isFloat(num) == True or isInt(num) == True:
      return True
    else:
       return False
   
   
# This function returns a list of all the factors excluding 1 and the number
# The numbers returned are in list format!
def wholeQuotient(num: int):
    """
    Evaluates a number to find all possible quotents
    ### Paramaters:
    num : Int
        - This is the number you want to evaluate
    
    ### Returns:
        - List : Int
            - A list of Int's will be returned containing all possible quotents excluding the number itself
            - Will only return a list containing 1 if the number is prime
    Raises
    -----
    - ValueError
        - This function can only accept integers  
"""
    values = list()
    
    for x in range(num):
        try:
            if(num % x) == 0:
                values.append(int(x))
        except ZeroDivisionError:
            pass
    return values
       
def clear():
    """
    Clears the console
    """
    os.system('cls' if os.name == 'nt' else 'clear')

# this is to find the greatest common factor of the numbers

def commonFactor(num1 : int,num2 : int):
    """
    Will evaluate 2 intigers to find their common factors
    This may include both num1 or num2
    
    ### Paramaters:
    1: num1 : int
        - The first number you want to find common factors of
        
    2: num2 : int
        - The second number you want to find common factors of
    
    ### Returns:
        - List : int
            - Returns a list of ints containing common factors
            - Will return a list only containing 1 if they have no common factors
            - Returns negative numbers if negative numbers were provided
    Raises
    -----
    - ValueError
        - This function can only accept integers  
    """
    gcf = list() # Greatest common factors
    negative = False
    if (num1 < 0):
        num1 = -num1
        negative = True
    if (num2 < 0):
        num2 = -num2
        negative = True
    
    if isNumber(num1) == True:
        temp = num1
        num1 = wholeQuotient(num1)
        num1.append(temp)
    
    if isNumber(num2) == True:
        temp = num2
        num2 = wholeQuotient(num2)
        num2.append(temp)
        
    for x in list(num1):
        for i in list(num2):
            if x == i:
                gcf.append(x)
    if negative:
        temp = []
        for x in gcf:
            temp.append(-x)
        for x in gcf:
            temp.append(x)
        gcf = temp
        
    

    
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
def isPrimeNumber(num:int):
    """
    Evaluates a number and returns whether it's prime or not 
    
    ### Paramaters:
    1: num : int
        - This is the number you would like to evaluate
    
    ### Returns:
        - Bool
            - True: The number was prime
            - False: The number was not prime
    Raises
    -----
    - ValueError
        - The function only accepts integers
    """
    if (num<=0):
        return False
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
def primeGenerator(finalNum : int ,startNum=0):
    """
    Generates a list of prime numbers
    
    ### Paramaters:
    1: finalNum : int
        - This determins the last number to be checked for being prime
        
    2: *startNum : int, (default 0)
        - This is the number you will start generating primes at
    
    ### Returns:
        - List : int
            - Returns a list of all prime numbers between cycles and startNum
    Raises
    -----
    - NegativeValue
        - startNum must be smaller than finalNum
    - ValueError
        - This function can only accept integers
    """
    finalNum +=1
    if(finalNum <= startNum):
        raise NegativeValue
    listOfPrimes = []
    for i in range((finalNum - startNum)):
        if isPrimeNumber(i+startNum):
            listOfPrimes.append(i+startNum)
    try:
        listOfPrimes.remove(0) # zero must be removed as it passes the zero devision error without being set to false
    except ValueError:
        pass
    return listOfPrimes

# This will return all numbers that can add to be num
# The numbers returned are in list format!
def allSums(num : int):
    """
    Will return all 2 number sums for specified number
    
    ### Paramaters:
    1: num : int
        - the number you want to find all 2 number sums for
    
    ### Returns:
        - list : str
            - returns a list of strings with each string containing 2 number seprated by a comma and space
            e.g. ['2, 1', '1, 2', '0, 3']
    Raises
    -----
    - ValueError
        - This function can only accept integers
    """
    num = int(num)
    
    sums = list()
    sublist = list()
    
    for x in range(num):
        sublist = {(num-(x+1)),(x+1)}
        #sums.append(f"{num-(x+1)},{x+1}")
        sums.append(f'{(num-(x+1))}, {(x+1)}')
        
    return sums
        
def localFile(fileName : str):
    """
    takes a file name, and returns the local directory as a string
    
    ### Paramaters:
    1: fileName : str
        - the file name you want to add the local directory to
    
    ### Returns:
        - str
            - directory/fileName as a string
    """
    return (os.path.join(os.path.dirname(os.path.realpath(__file__)), fileName))


def lFile(fileName : str):
    """
    alias to localFile
    
    takes a file name, and returns the local directory as a string
    
    ### Paramaters:
    1: fileName : str
        - the file name you want to add the local directory to
    
    ### Returns:
        - str
            - directory/fileName as a string
    """
    return localFile(fileName)


def getIP():
    """
    Returns the local ip address of the local computer
    """
    s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    s.settimeout(0)
    try:
        # doesn't even have to be reachable
        s.connect(('10.255.255.255', 1))
        IP = s.getsockname()[0]
    except Exception:
        IP = '127.0.0.1'
    finally:
        s.close()
    return IP


def getName():
    """
    Returns the name of the local computer
    """
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    name = socket.gethostname()
    s.close()
    return name

'''
def bubbleSort(numbers: list):
    pass
'''




if __name__ == "__main__":
    
    print(wholeQuotient(1681))
    
    pass