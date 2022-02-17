
from pip import main
from Modules.Kris import *


def hmm(num,cycles):
    
    num = int(num)
    cycles = int(cycles)
    
    hold = num
    
    numList = list()
    numList.append(num)
    
    for x in range(cycles):
        num = num + hold
        numList.append(num)
        
    return numList
        
        
        
        
if __name__ == "__main__":
    
    def main():
        print("\n")
        x = input('we will calculate all multiplictives of this number: ')
        if isNumber(x) == True:
            y = input("to which power shall we do: ")
            print("")
            print(hmm(x,y))
            main()
        else:
            exit("lol")
            
    main()
    

    