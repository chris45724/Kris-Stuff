import sys
import os
from Kris import *

import os





if __name__ == '__main__':
    clear()
    x = int(input("What number would you like to check: "))
    print(f'{x} ---> {((x**2)-1)}')
    x = (((2**x)-1))
    xList = wholeQuotient(x)
    if xList == [1]:
        print(f"Yes. {x} is a prime number")
    else:
        xList.remove(1)
        print(f"No. {x} is divisible by {xList}")