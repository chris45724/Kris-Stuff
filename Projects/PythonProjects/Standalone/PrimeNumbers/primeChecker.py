from PrimeFactorDemo import isPrimeNumber as isPrime

if __name__ == '__main__':
    print('\n\n')
    number = int(input("What number would you like to check: "))
    
    if(isPrime(number)):
        print(f'\n{number} is prime!')
    else:
        print(f'\n{number} is not prime')
    print('\n')
    