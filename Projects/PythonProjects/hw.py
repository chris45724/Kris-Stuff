


def largestNumber(x):
    num = int(x[0])
    for i in x:
        if i > num:
            num = i
    return num

def smallestNumber(x):
    num = int(x[0])
    for i in x:
        if i < num:
            num = i
    return num


def counter(inList):
    count = 1
    outlist = []
    
    maxValue = largestNumber(inList)
    for x in range(maxValue):
        outlist.append("0")
    
    for x in inList:
        for y in inList:
            if x == y:
                count = count + 1
        outlist[x] = count
        count = 0
                
    return outlist


def main():

    list1 = [1,2,3,4,5,4,3,2,1]

    list3 = []    

    
        
    print(counter(list1))
    
    
    
    

    #print(maxValue)


main()