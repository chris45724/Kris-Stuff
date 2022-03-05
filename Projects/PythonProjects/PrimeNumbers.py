import os
import time





def primeNumber(num):
    isPrime = True
    for x in range(num):
        try:
            if( (num % x) == 0 and ((x < num) and (x > 1)) ):
                isPrime = False
        except ZeroDivisionError:
            pass
            
    return isPrime








def main():
    
    Starter = int(input("What number would you like to start at: "))
    Cycles = int(input("How many cycles would you like to run for?: "))
    
    log = input("Would you like to print data to console?\nPrinting data to console slow\n[y]es [n]o: ")
    timing = input("Would you like to save calculation time to file?\n[y]es [n]o: ")
    
    outputFile = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "Prime_Numbers.txt"), "w")
    outputFile.write(f'All prime numbers between {Starter} and {Starter+Cycles}\nPython version\n') 
    
    startTime = int(time.time())
    
    if(log == 'y'):
        for x in range(Cycles):
            if primeNumber(x + Starter):
                print(f'{x + Starter}   | Calculated in {int(time.time())-startTime}')
                outputFile.write(f'{x + Starter}   | Calculated in {int(time.time())-startTime}\n')
    elif((log == 'n' and timing == 'y')):
        print("---running---")
        for x in range(Cycles):
            if primeNumber(x + Starter):
                outputFile.write(f'{x + Starter}   | Calculated in {int(time.time())-startTime}\n')
    else:
        print("---running---")
        for x in range(Cycles):
            if primeNumber(x + Starter):
                print(x + Starter)
                outputFile.write(f'{x+Starter}\n')
                    
            
    print("---Finished---")

if __name__ == '__main__':
    main()
    #print(wholeQuotient(100))
    