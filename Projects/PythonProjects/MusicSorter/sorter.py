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



def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def songLabler(file,out,lable):
    song = eyed3.core.load(file)
    #print(f'Song title: {song.tag.title}')
    #print(out)
    print(f'Song: {song.tag.title}\nCopying file')
    shutil.copy2(file,out)
    newName = song.tag.title
    x = re.sub(r'[^a-zA-Z0-9+\(+\)+\s+\-]'," ",f'{newName}')
    print(x)
    os.rename(f'{out}\\{lable}',f'{out}\\{x}.mp3')
    print('')
    

def songSorter(file,out):
    #print(file)
    song = eyed3.core.load(file)
    #print(f'Song title: {song.tag.title}')
    #print(out)
    try:
        x = song.tag.lyrics[0].text
        print(f'{song.tag.title} Has lyrics\nCopying file')
        shutil.copy2(file,out)
        print('')
    except:
        pass
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
            if mode == 'L':
                songSorter(f'{path}\\{file}',f'{OutPath}\\')
            elif mode == 'N':
                songLabler(f'{path}\\{file}',f'{OutPath}\\',f'{file}')
            
            
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
    #mode = 'N'
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