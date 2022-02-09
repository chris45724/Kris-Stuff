

import itertools











if __name__ == '__main__':
    num = int(input("How many items are in the list: "))
    a = []
    for x in range(num):
        a.append(chr(x+65))
    print(a)
    
    input("Press any key to continue")
    
    for L in range(0, len(a)+1):
        for x in itertools.combinations(a, L):
            print(x)
    
    
    pass




