from audioop import mul
from Kris import *
import random

#x = list({5, 4, 2, 1})



#print(len(x))

#print(commonFactor(-6,9))

#print(commonFactor([2,8]))

#print(wholeQuotient(61837))

clear()
numbers = list()
for x in range(2):
    numbers.append(random.randrange(1,100000))
print(numbers)
#print(selectionSort(numbers))

#print(commonFactor(numbers))
print(wholeQuotient(numbers[0]))