'''
Place album in the Music Folder
It will find all songs with lyrics, and place them in the output
'''

#shutil.copy2
#os.path.join(os.path.dirname(os.path.realpath(__file__))


import eyed3
import os
import shutil
import re


# used to clear screen
def clear():
    os.system('cls' if os.name == 'nt' else 'clear')


'''
Relables music based on music metadata name
variables:
    file:
        Path to the input folder
    out:
        Path to the output folder
    label:
        file name

'''
def songLabeler(file,out,label):
    song = eyed3.core.load(file)
    #print(f'Song title: {song.tag.title}')
    #print(out)
    print(f'Song: {song.tag.title}\nCopying file')
    shutil.copy2(file,out)
    newName = song.tag.title
    x = re.sub(r'[^a-zA-Z0-9+\(+\)+\s+\-]'," ",f'{newName}')
    print(x)
    os.rename(f'{out}\\{label}',f'{out}\\{x}.mp3')
    print('')
    
'''
Sorts music based on mode
variables:
    File:
        Path to the input folder
    out:
        Path to the output folder
    mode:
        N - Renames the music according to it's metadata name (Default)
        L - Find's all the songs with lyrics in the meta data and copies them to the output

'''
def songSorter(file,out,mode = 'L'):
    #print(file)
    song = eyed3.core.load(file)
    #print(f'Song title: {song.tag.title}')
    #print(out)
    if mode == 'L':
        try:
            x = song.tag.lyrics[0].text
            print(f'{song.tag.title} Has lyrics\nCopying file')
            shutil.copy2(file,out)
            print('')
        except:
            pass
    elif mode == 'NL':
        try:
            x = song.tag.lyrics[0].text
        except:
            print(f'{song.tag.title} Has no lyrics\nCopying file')
            shutil.copy2(file,out)
            print('')
    #pass
os.rename

'''
This is the heart of the program
Loops though each file placed in the music folder
variables:
    path:
        Path to the input folder
    OutPath:
        Path to the output folder
    mode:
        N - Renames the music according to it's metadata name (Default)
        L - Find's all the songs with lyrics in the meta data and copies them to the output

'''
def albumExplorer(path,OutPath, mode = 'N'):
    print(f"Mode = {mode}")
    for file in os.listdir(path):
        print(f'\nfile name: {file}\nPath: {path}\nOutput: {OutPath}')
        if file.endswith(".mp3"):
            print("mp3\n")
            if mode == 'L' or mode == 'NL':
                songSorter(f'{path}\\{file}',f'{OutPath}\\', mode)
            elif mode == 'N':
                songLabeler(f'{path}\\{file}',f'{OutPath}\\',f'{file}')
            
            
        elif str(file).startswith('AlbumArt') or str(file).startswith('Folder'):
            print("Cover Art\n")
            shutil.copy2(f'{path}\\{file}',OutPath)
            pass
        elif os.path.isdir(f'{path}\\{file}'):
            print(f'{file} is a directory')
            os.makedirs(f'{OutPath}\\{file}')
            albumExplorer(f'{path}\\{file}',f'{OutPath}\\{file}', mode)
            print("Album\n")
        else:
            print("Unknown\n")
            shutil.copy2(f'{path}\\{file}',OutPath)
            pass



# file deletes file provided to it via path
# Returns nothing
def fileDeleter(path):
    for file in os.listdir(path):
        print(f'{file} in output file\nDeleted')
        shutil.rmtree(f'{path}\\{file}')



if __name__ == '__main__':
    clear()
    listOfFiles = []
    InPath = "Projects\\PythonProjects\\MusicSorter\\Music"
    OutPath = "Projects\\PythonProjects\\MusicSorter\\Output"
    mode = 'L'
    # Modes --> N L NL
    fileDeleter(OutPath)
    albumExplorer(InPath,OutPath,mode)
    #Projects\PythonProjects\MusicSorter\Music\A Capella Science
    print(f'Finished!')

    




#song = eyed3.core.load(os.path.join(os.path.dirname(os.path.realpath(__file__)),'Music/MilkyWay.mp3'))
#song = eyed3.core.load(os.path.join(os.path.dirname(os.path.realpath(__file__)),'Music/Building Better Worlds.mp3'))
#song.tag.lyrics
#for x in song.tag.lyrics:
#    print(x)

#print(dir(song.tag.lyrics.get))
#print(song.tag.lyrics[0].text)