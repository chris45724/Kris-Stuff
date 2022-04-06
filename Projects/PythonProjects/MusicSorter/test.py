import eyed3
import os
import shutil
import re





Test = "Test12345 asdf?()=-"
#print(f'Song title: {song.tag.title}')
#print(out)

x = re.sub(r'[^a-zA-Z0-9+\(+\)+\s+\-]',"",f'{Test}')
expression = r'[^a-zA-Z0-9\(\)\s\-]'
print(x)
#print(f"\n{re.sub(expression,'',x)}\n")
