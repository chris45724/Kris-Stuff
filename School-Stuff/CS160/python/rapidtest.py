def apples1():
    counter = 0
    apples = 0

    while(counter < 10):
        apples = apples + 2
        counter = counter + 1
        #print(counter)

    print(f"{apples} apples after {counter} cycles")

def apples2():
    apples = 0
    for x in range(20):
        apples = apples + 4
    print(apples)


def qualitybot(x,y,z):
    
    
    
    if x > 89 & y > 75:
        p1 = False
    else: 
        p1 = True
        
    if z < 98 & z > 12:
        p2 = True
    else: 
        p2 = False
    
    if p1 == True:
        if p2 == True:
            return True
        else:
            return False
    else:
        return False
    

if __name__ == "__main__":
    

    
    print(qualitybot(65,79,82))
    print(qualitybot(100,76,87))
    print(qualitybot(82,67,99))

    
    