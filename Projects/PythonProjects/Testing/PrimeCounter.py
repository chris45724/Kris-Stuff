from ipaddress import ip_address
from Kris import *
import pandas as pd


if __name__ == '__main__':
    clear()
    size = int(input("Enter a final number: "))
    rate = 1
    for x in range(len(str(size))):
        if((x+1)<2):
            rate=1
        elif((10**(x+1))>size):
            rate=(10**(x-1))
            break
        
    print(len(str(size)))
    
    
    primeNumbers = 0
    number = 0;
    listOPrimes = []
    listONumbers = []
    print("--- Running ---")
    for x in range(size+1):
        if(isPrimeNumber(x)):
            primeNumbers += 1
        
        if((((x)%rate) == 0)and (x!=0)):
            print(f'Until {x}, there are {primeNumbers} prime numbers')
        
        
        number = x
        listOPrimes.append(primeNumbers)
        listONumbers.append(number)
    
    
    print("\n--- Finished ---")    
    print(f'At {number}, there are {primeNumbers} prime numbers')
    
    #print(f'Checking: {len(primeGenerator(number))} prime numbers found')
    
    #d = {'Number':listONumbers,'PrimeNumbers':listOPrimes }
    #data = pd.DataFrame(data=d)
    #print(data)
    #data.to_csv(localFile("PrimeNumberQuantity.cvs"))
    
    #print(f'There are {len(primeNumbers)} prime numbers')
        
    
    
    
    
