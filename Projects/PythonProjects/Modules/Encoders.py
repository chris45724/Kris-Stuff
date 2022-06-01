from Kris import *




def trinaryEncode(data : int, power : int = 0):
    
    
    # setting up default values
    output = ""
    solution = ""
    solved = False
    num = data + 1
    #num = data
    #checking power
    if (power == 0):
        power = 0
        while(data>(3**power)):
            power = power + 1
        power = power - 1
    else:
        requiredPower = power
        while(data>((3**requiredPower)-1)):
            if (requiredPower > power):
                print("abort: value exceeded max value (Placeholder)")
                solved = True
                break
            requiredPower = requiredPower + 1
        requiredPower = requiredPower - 1
    
    
          
    
    
    #Decode happens here
    while((not solved)):
        # Checking if num is a double or single
        #2
        power3 = (3**power)
        numMin = num-power3
        if (((num)-(3**power)) > (3**power)):
            solution = solution + '2'
            num = (num)-(2*(3**power))
        
        #1
        elif((num>(3**power))):
            solution = solution + '1'
            num = (num)-(3**power)
        #0
        else:
            solution = solution + '0'
        
        power = power - 1 
        if power < 0:
            solved=True
               
        #print(num-(3**(power-1)))
            
    output = output + solution    
    #print(solution)
    
    return output    


def trinaryDecode(code : str):
    code = str(code)
    output = 0
    for position in range(int(len(code))):
        power = (int(len(code))-position) - 1
        solution = 0
        #here = code[position]
        if code[position] == '>':
                solution = solution + 2*(3**power)
        elif code[position] == '<':
                solution = solution + (3**power)
        output = output + int(solution) 
    
    return output


def customArrowEncode(data : int, power : int = 0):
    
    
    # setting up default values
    output = ""
    solution = ""
    solved = False
    num = data + 1
    
    #checking power
    if (power == 0):
        power = 0
        while(data>(3**power)):
            power = power + 1
        power = power - 1
    else:
        requiredPower = power
        while(data>((3**requiredPower)-1)):
            if (requiredPower > power):
                print("abort: value exceeded max value (Placeholder)")
                solved = True
                break
            requiredPower = requiredPower + 1
        requiredPower = requiredPower - 1
    
    
          
    
    
    #Decode happens here
    while((not solved)):
        # Checking if num is a double or single
        #2
        if (((num)-(3**power)) > (3**power)):
            solution = solution + '>'
            num = (num)-(2*(3**power))
        
        #1
        elif((num>(3**power))):
            solution = solution + '<'
            num = (num)-(3**power)
        #0
        else:
            solution = solution + '-'
        
        power = power - 1 
        if power < 0:
            solved=True
               
        #print(num-(3**(power-1)))
            
    output = output + solution    
    #print(solution)
    
    return output    


def customArrowDecode(code : str):
    output = 0
    for position in range(int(len(code))):
        power = (int(len(code))-position) - 1
        solution = 0
        #here = code[position]
        if code[position] == '>':
                solution = solution + 2*(3**power)
        elif code[position] == '<':
                solution = solution + (3**power)
        output = output + int(solution) 
    
    return output

def krisKey():
    return list(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', ' ', '.', '?', '!', '\'', '\"', '(', ')', ';', ':', '@', '-', '>', '<', '_', '/','\\' , '☃', '�'])

def krisCode(character : chr):
    character = str(character)
    key = krisKey()
    try:
        value = key.index(character)
    except ValueError:
        return ((len(key) - 1))
    return(value)
    
   
def krisDecode(character : int):
    character = int(character)
    key = krisKey()
    return(key[character]) 
    
def arrowEncode(text : str):
    output = ""
    for x in text:
        output = output + customArrowEncode(krisCode(x), 3)
    
    return output
      
def arrowDecode(text : str):
    output = ""
    letters = int(len(text)/4)
    for group in range(letters):
        letter = ""
        for x in range(4):
            letter = letter + text[(group*4)+ (x)]
        output = output + krisDecode(customArrowDecode(letter))
        
        
    #krisDecode(customArrowDecode()
    
    return output


if __name__ == '__main__':
    
    text = str(input("Please provide a string to encode: "))
    #text = 'apple'
    
   
    encodedText = arrowEncode(text)
    print(f'Encoded: {encodedText}\nDecode check: \"{arrowDecode(encodedText)}\"')
    print(f'Length of {len(encodedText)}')
    
    text = str(input('Please provide a string to decode: '))
    decodedText = arrowDecode(text)
    print(f'Decoded text:{decodedText}')
    
    
    
    
    pass