import os

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')
    
'''   
7 --> Not equals
6 --> Equals
5 -->
3 --> Greater than
'''
#- m_ConditionMode: 7 -- Not equals?
#  m_ConditionEvent: tensHR -- Data evaluation
#  m_EventTreshold: 5  -- Target
    
    
    
    
def linecounter(path):
    file = open(path,'r')
    return len(file.readlines())
    
if __name__ == '__main__':
    clear()
    fileName = 'HRAC 1.txt'
    filePath = os.path.join(os.path.dirname(os.path.realpath(__file__)),fileName)
    animator = open(filePath,'r')
    output = open(os.path.join(os.path.dirname(os.path.realpath(__file__)),'controller.txt'),'w')
    lineCount = linecounter(filePath)
    print("Starting search")
    #print(animator)
    block = False
    previousLine = ""
    savedLines = []
    write = False
    for x in range(lineCount):
        line = animator.readline()
        #output.write(line)
        #print(line)
        if((str(line).startswith("---")) and (str(previousLine).startswith("---"))):
            break
        
        
        if(str(line).startswith("---")):
            print("=============== Start ===============")
            savedLines.append(f'{previousLine}')
            #savedLines.append(f'{line}')
            block = True
            write = True
        
        if(str(line).startswith("---")):
            print("=============== End ===============")
            block = False
        
        if (str(line).startswith('  - m_ConditionMode: 7')):
            write = False
        
        if (block == True):
            savedLines.append(f'{line}')
            
        
        if (write == True) and (block == False):
            for x in savedLines:
                output.write(x)
            write = False
            savedlines = []
        elif (write == False) and (block == False):
            savedlines = []
        
        
        previousLine = line
#  - m_ConditionMode:
#  - m_ConditionMode: 7