from ipaddress import ip_address
from Kris import *


if __name__ == '__main__':
    #print(f'local IP is {getIP()}')
    run = True
    x = (1/9)
    k = 2
    y = 1
    print(f"When does {x**y}*k = integer")
    while ((round(((x**k)*y),9))%1 != 0):
        y = y + 1
    
    print(f"Y = {y}")
    #print((5)%1)
    #print((round(((x**k)*972),9)))
        
    
    
    
    
