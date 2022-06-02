from Kris import *
from Encoders import *




clear()
data = input("Please input a string to encode: ")


encodedData = arrowEncode(data)

print(f'\nEncoded:\n  {encodedData}\n\nTest Decode:\n   {arrowDecode(encodedData)}')
