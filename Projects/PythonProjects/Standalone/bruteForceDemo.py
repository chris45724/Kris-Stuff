'''
This python program is a deminstration on brute forcing 'encryption' can take a long time!
modern encryption uses prime numbers for encryption because when 2 prime numbers are multiplied together, only the same 2 prime numbers can divide the resulting product into whole numbers (excluding 1 and the number itself)

By default this program will generate a file of primenumbers between 0 and 1000, but the user may specify if they would like a larger or smaller list
The smaller the prime numbers are, the quicker the bruteforce 'attack' is. It should be noted that generating large prime numbers takes time, as the only way to tell if a number is prime is to check every possible number (all number smaller)

This program is not particularly efficient or quick because this program was made for deminstration purposes

If you're feeling up to the task, you may try and write a function that will use primeNumbers.txt to 'decrypt' the product, this would allow for faster decryption. 
    You would have a list of prime numbers, and would not need to check every possible number.
    This is also why we make a file, as picking random numbers from a file is easier than regenerating a large list of prime numbers every time


Sorry for the poor comments!
'''
import os # This is used to write/read files
import time # This is used for calculating time
import random # This is used for making random numbers



# This will return a true or false statement dependent on whether the input(num) number is prime or not
def isPrimeNumber(num):
    isPrime = True
    # We preset the value to true, because it's easier to check if it's not a prime number  
    for x in range(num): 
        try: # This try statement must be here to prevent deviding by zero causing an error
            if( (num % x) == 0 and ((x < num) and (x > 1)) ):
                isPrime = False
                break
        except ZeroDivisionError:
            pass
            
    return isPrime


# This generates a list of prime numbers
# The range of prime numbers is startNum between endNum
# by default this will generate prime numbers between 0(startNum) and 1000(endNum)
def primeGenerator(endNum=1000,startNum=0):
    listOfPrimes = [] 
    for i in range(endNum - startNum): # as endNumb is where we want our file to end at, we iterate through everynumber between startNum and endNum
        if isPrimeNumber(i+startNum): # Check that the current number is prime, and if it is, save it
            listOfPrimes.append(i+startNum)
    try:
        listOfPrimes.remove(0) # try to remove zero from the list, if it is in the list (this shouldn't happen anymore)
    except ValueError:
        pass
    return listOfPrimes


# This find all whole factors of a number excluding one and the number itself. Returns a list of factors
# This is how we will brute force the numbers
# This function was not originally designed for this task, instead it was designed to find all factors of any number
# This function returns all factors of the input number (num) as a list
def factorFinder(num):
    values = list()
    for x in range(num): # making a loop that will increment x through every number smaller than our input number (num)
        if (x != 0) and (x != 1): # we check that 'x' is not 0 or 1 as we don't care about either number
            if(num % x) == 0:
                values.append(int(x))
    return values

# This will generate a file called "primeNumbers.txt", and save 'listOfNumbers' to it
# every value for 'listOfNumbers' is saved to a new line in the file
def fileGenerator(listOfNumbers):
    # os.path.join(os.path.dirname(os.path.realpath(__file__) is how you access a file in the same folder as the python script. Python usually likes saving files to where the shell is running from
    file = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "primeNumbers.txt"), "w") # This will overwrite the previous file
    for x in listOfNumbers:
      file.write(f'{x}\n') 
    file.close() # Always close files 
    
# Because I am lazy, I wanted to make a function that will read the file and return a list of prime numbers in the file
def fileReader():
    primeNumbers = list()
    try: # checks to see if the file exists before we open it
        file = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "primeNumbers.txt"), "r")
    except FileNotFoundError: # if the file does not exist, we make one
        fileGenerator(primeGenerator())  
    file = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "primeNumbers.txt"), "r")
    for x in file: # save every number in the file to a list
        primeNumbers.append(int(x))
    file.close()
    return primeNumbers




if __name__ == '__main__':
    primeNumbers = fileReader()
    loops = 10 # This controls how may loops we will do when trying to factor the product of the prime numbers
    
    regenrate = input("Would you like to make a new list of prime numbers?\n[y]es [n]o: ") #This asks the user if they would like to make a new list of prime numbers
    # The larger the prime nubers the harder they are to calculate, and the harder they are to factor (This is the basis of modern encryption!)
    while((regenrate != "y") and (regenrate != "n")):
        print("\nInvalid response\n")
        regenrate = input("Would you like to generate a new list?\n[y]es [n]o: ")
        
    if regenrate == "y": # This will get the specifcations the user wants the new prime number list to be
        startNum = "starting" # trash values so we can start inside the while loops
        endNum = "ending"
        while(type(startNum) != type(int(7))):
            startNum = input("What number would you like the list to start at: ")
            try: 
                startNum = int(startNum)
            except:
                print("\nInvalid response\n")
                
                
        while(type(endNum) != type(int(7))):
            endNum = input("What number would you like the list to end at: ")
            try: 
                endNum = int(endNum)
            except:
                print("\nInvalid response\n")
        
        print("Generating prime numbers!\nThis may take a while")        
        fileGenerator(primeGenerator(endNum,startNum))
        primeNumbers = fileReader()
        print("Prime numbers finished generation")
    
    
    print(f'\n\nThere are {len(primeNumbers)} prime numbers to chose from')
    for x in range(loops): # This is where the magic happens!
        print(f"\n\n------ Starting loop {x+1} ------\n")
        prime1 =  primeNumbers[random.randint(0, len(primeNumbers)-1)] # Prime numbers are choses randomly from the primeNumbers list
        print(f'{prime1} was chosen to be the first prime number')
        prime2 =  primeNumbers[random.randint(0, len(primeNumbers)-1)]
        print(f'{prime2} was chosen to be the second prime number')
        product = prime1 * prime2 # they are multiplied together to make our product that we will 'decrypt'
        print(f'{product} is the product of both prime numbers')
        print(f"Starting to factor {product}\nThis should return the first and second prime numbers")
        startTime = time.time() # we save the time at which we start calculating, so we can check how long it took!
        devisors = factorFinder(product) # We save calculating the factors here
        print(f'After {round(((time.time()) - startTime),3)} seconds the factors are : {devisors}\n')
        
    
    
