from audioop import mul
from turtle import position
from Kris import *
import random

#x = list({5, 4, 2, 1})

x = "test"

'''
def krisEncode(text : str):
    text.lower()
    charList = list()
    for x in text:
        charList.append(ord(x))
    #print(charList)
    output = ""
    for num in charList:
        num = num + 1
        solution = ""
        solved = False
        currentPower = 5
        #while(num>(3**currentPower)):
        #    currentPower = currentPower + 1
        #currentPower = currentPower - 1
            
        while(not solved):
            
            #print(num-1)
            # Checking if num is a double or single
            if (((num)-(3**currentPower))>(3**currentPower)):
                solution = solution + '>'
                num = (num)-(2*(3**currentPower))
            elif((num>(3**currentPower))):
                solution = solution + '<'
                num = (num)-(3**currentPower)
            else:
                solution = solution + '-'
            
            if currentPower <= 0:
                solved=True
            currentPower = currentPower - 1
            
            
            #print(num-(3**(currentPower-1)))
            
        output = output + solution    
        #print(solution)
    
    return output    


def krisDecoder(code : str):
    output = ""
    if ((len(code)%6 != 0)):
        print("Issue!")
        
    print(int(len(code)/6))
    for group in range(int(len(code)/6)):
        solution = 0
        for letter in range(6):
            position = (group*6) + letter
            power = (6 - letter) - 1
            if code[position] == '>':
                solution = solution + 2*(3**power)
            elif code[position] == '<':
                solution = solution + (3**power)    
        output = output + chr(int(solution))    
    
    return output

'''


if __name__ == '__main__':
    #krisEncode("z")
    
    clear()
    x = "Is jones ever going to invite me?"
    
    #print(ord(x))
    currentPower = 0
    #while(x>(3**currentPower)):
        #currentPower = currentPower + 1
    #print(f"max currentPower is {currentPower} (position)\nThis equals {3**(currentPower-1)}")
    
    print(krisEncode(x))
    print(krisDecoder(krisEncode(x)))
    #print(f'{krisEncode("Fuck")}|{krisEncode("You")}|{krisEncode("Jones")}')