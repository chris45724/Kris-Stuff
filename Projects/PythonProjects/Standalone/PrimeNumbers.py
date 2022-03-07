'''
Prime number demonstrator

This program will find all prime numbers between 2 values
This was attempt 1!
This goes in sequential order, so you get to see it print as it calculates

Made by Chris
'''



import os
import time




# This returns a True or False depending on if the number provided was a prime number or not
def primeNumber(num):
    isPrime = True
    # We preset the value to true, because it's easier to check if it's not a prime number  
    for x in range(num): 
        try:
            if( (num % x) == 0 and ((x < num) and (x > 1)) ):
                isPrime = False # Sets the value to false if it is divisible by any number other than 1 or the number itself
                break
        except ZeroDivisionError:
            pass
            
    return isPrime








def main():
    
    Starter = int(input("What number would you like to start at: ")) 
    Cycles = int(input("How many cycles would you like to run for?: "))
    
    log = input("Would you like to print data to console?\nPrinting data to console slow\n[y]es [n]o: ")
    # the log flag controls wether we print to the console or not
    timing = input("Would you like to save calculation time to file?\n[y]es [n]o: ")
    # this writes the time from once we started to the current time to the file: (primenumber)   | (time in seconds)
    # this was useful for determining how much faster c++ was in this case
    
    ''' 
    We write files with the numbers incase I want to check them in the future
    
    os.path.join(os.path.dirname(os.path.realpath(__file__) finds the directory of where the script is
        This is so we don't write the file at the locaton of the python shell
    '''
    outputFile = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "Prime_Numbers.txt"), "w")
    outputFile.write(f'All prime numbers between {Starter} and {Starter+Cycles}\nPython version\n') 
    
    startTime = int(time.time()) # Useing the time function to start a counter that we can to subtract from current time later
    
    
    # this if statement is to allow us control over what gets saved to the file, and if we want max speed or not
    if(log == 'y'):
        for x in range(Cycles):
            if primeNumber(x + Starter):
                # int(time.time()) is the current time, and starttime is the time in which we started counting
                print(f'{x + Starter}   | Calculated in {int(time.time())-startTime}')
                outputFile.write(f'{x + Starter}   | Calculated in {int(time.time())-startTime}\n')
    elif((log == 'n' and timing == 'y')): #  This one has no console output, but does still save time to the file
        print("---running---")
        for x in range(Cycles):
            if primeNumber(x + Starter):
                outputFile.write(f'{x + Starter}   | Calculated in {int(time.time())-startTime}\n')
    else: # this one only saves the prime numbers in a file
        print("---running---")
        for x in range(Cycles):
            if primeNumber(x + Starter):
                print(x + Starter)
                outputFile.write(f'{x+Starter}\n')
                    
    outputFile.close()       
    print("---Finished---") # if you set the number small enough for it to finish in a reasonable amount of time

if __name__ == '__main__':
    main()