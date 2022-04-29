'''
Prime number demonstrator 2
This will generate a list of prime numbers between x and y
This is a little more efficient than the previous one
This is how I would probably implement such a function if I needed one

This one only generates a list, so you don't get to see it as it works
Made by Chris
'''

# Uncomment this if you want to make files
import os
from Kris import *




'''
# This function will make a file and write the specified data to it

# Don't forget to uncomment "import os" at the top
# this function is pretty basic, and is set to auto overwite whatever file it finds
def fileWriter(fileName,data,mode='w'):
    workFile = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), str(fileName)), str(mode))
    workFile.write(str(data))
    workFile.close()
'''





# this only runs if the program is called "Main" as to not auto run this segment if it ever gets imported
# I don't normally have main() functions, and instead stuff the whole "main()" inside the if __name__ == "__main__":
if __name__ == "__main__":
    clear()
    print("Running")
    outputFile = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), "primeNumbers.tmp"), "w")
    cycles =  999
    cycles = int(input("Final number: "))
    primes = list(primeGenerator(cycles)) 
    print(f'There are {len(primes)} prime numbers in this list!')
    
    for x in range(len(primes)):
        outputFile.write(f'{str(primes[x])}\n')      
    outputFile.close()
         
    print("Finished") 
    #fileWriter("Prime_Numbers2.txt",primes)
    
    
    
# If you would like a challenge, see if you can write the whole list to a file as individual lines | you will want to modify fileWriter to do such