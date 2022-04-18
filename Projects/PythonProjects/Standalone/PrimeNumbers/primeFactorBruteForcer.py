import random
import os
import time


#This find all possible whole quotents of the input number
#This is how we brute force the numbers
def wholeQuotient(num):
    values = list() # making an empty list
    for x in range(num):
        try:
            if(num % x) == 0:
                values.append(int(x))
        except ZeroDivisionError:
            pass
           
    return values


#This checks if a function is a prime number
#This is used for the prime number generator
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

#This will generate prime numbers
#cycles is how many numbers you want to run for, and startNum is what number you wish to start at. It defaults to 0
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

#A lazy method to write and print a file
def printerWriter(data):
    file = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "BruteForceDemo.txt"), "a")
    print(data)
    file.write(f'{data}\n')
    file.close()

if __name__ == '__main__': 
    loops = 10 # how many times you want to run the brute forcer
    preGenerate = True # When true, this genrates prime numbers only once. If false, it will generate every loop
    start = 100000 # what number do you want to start generating prime numbers at?
    cycle = 10000 # how many cycles do you want to generate prime numbers for? e.g. you will have a list of primes from start to start+cycles
    if preGenerate:
        primeNums = list(primeGenerator(cycle,start))  
    
    outFile = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "BruteForceDemo.txt"), "w")
    
    for x in range(10):
        printerWriter(f'\n\nStarting loop {x+1}')

        
        if preGenerate == False: # This is where the false statement for primenumbers to be generated happens
            primeNums = list(primeGenerator(cycle,start))
        printerWriter(f'There are {len(primeNums)} prime numbers in our list')
        num = random.randint(0, len(primeNums)-1) #selecting a random prime number from the list
        num2 = random.randint(0, len(primeNums)-1) #selecting a second random prime number from the list
        printerWriter(f'The first prime number is: {primeNums[num]}')
        printerWriter(f'The second prime number is: {primeNums[num2]}')
        codedNum = primeNums[num]*primeNums[num2]
        printerWriter(f'The product of the prime numbers is: {codedNum}')
        startTime = time.time()
        printerWriter("Starting reverse calculation")
        printerWriter(f'Brute forced: {wholeQuotient(codedNum)}') 
        printerWriter(f'Time taken {round((time.time()-startTime), 2)} seconds')
        
    printerWriter("\n---Finished---")
    outFile.close()
    