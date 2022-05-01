from Kris import *




if __name__ == '__main__':
    
    data = set(['0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'A', 'b', 'B', 'c', 'C', 'd', 'D', 'e', 'E', 'f', 'F', 'g', 'G', 'h', 'H', 'i', 'I', 'j', 'J', 'k', 'K', 'l', 'L', 'm', 'M', 'n', 'N', 'o', 'O', 'p', 'P', 'q', 'Q', 'r', 'R', 's', 'S', 't', 'T', 'u', 'U', 'v', 'V', 'w', 'W', 'x', 'X', 'y', 'Y', 'z', 'Z', 'space', '.', '?', '!', '\'', '\"', '(', ')', ';', ':', '@', '-', '>', '<', '□', '□', '☃', '□', '�'])
    
    
    file = open(os.path.join(os.path.dirname(os.path.realpath(__file__)), 'ArrowCheat.txt'),'r',encoding="utf-8")
    x = file.readline().strip()
    output = f"\'{x}\'"
    y = 0
    
    x = file.readline().strip()
    while(y < 80):
        output = output + f", \'{x}\'"
        x = file.readline().strip()
        y+= 1
    print(output)
    
    
    
    pass