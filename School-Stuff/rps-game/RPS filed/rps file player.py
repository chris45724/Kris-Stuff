
import os # for the clear function! Maybe I should get rid of this
import random # for the random functions



# a lot of this code was from my old rps script earlier this term!


def clear(): # clears the terminal (wont work in pycharm)
    
    os.system('cls' if os.name == 'nt' else 'clear')  #clear commandlet



def valid(choice1): #we check to see if the player choices are valid
    if choice1 == 'rock' or choice1 == 'paper' or choice1 == 'scissors':
        anwser1 = True
    else:
        anwser1 = False
    return(anwser1)


def winner(player1, player2): # checking who wins. Also does tie checking for future use
        if player1 == player2:
            return(None)
        elif player1 == 'rock' and player2 == 'paper':
            return(False)
        elif player1 == 'rock' and player2 == 'sicssors':
            return(True)
        elif player1 == 'paper' and player2 == 'scissors':
            return(False)
        elif player1 == 'paper' and player2 == 'rock':
            return(True)
        elif player1 == 'scissors' and player2 == 'rock':
            return(False)
        elif player1 == 'scissors' and player2 == 'paper':
            return(True)
        else:
            return('error')
    

def playerpicker():  # made this a function becasue... Not sure why
    looplimit = 0
    ppass = False
    while looplimit < 5 and ppass == False:  # this loops 5 times trying to get the player to make a valid choice
            player = input('Your choices are "rock" "paper" "scissors" ')
            ppass = valid(player)
            looplimit = looplimit + 1
            if ppass == False:
                print(str(looplimit) + '/5 trys')
            if looplimit == 5: # after 5 tries it will insult the player
                print('you are dumb')
            if ppass == True:
                return player


def roboplayer(): # computer decieds what it want's to play
    list = ['rock', 'paper', 'scissors'] 
    return random.choice(list)
    
    
def debugger(p1,p2):
    print('computer checking')
    print(p2)
    print('choice valid?:',valid(p2))
    print('computer checking over')
    print('player checking')
    print(p1)
    print('choice valid?:',valid(p1))
    print('player checking over')


def rps2(name,player): # more efficant rps program for use in files only
    computer = roboplayer()
    player = player.lower() # forces the player string to be lowercase
    if valid(player) == True:
        #print(winner(player,computer))
        win = winner(player,computer)  # had an error where it would return None on a win, but only when used in this section of the program. No idea why
        if win: 
            print(name,'picked',player)
            print('The computer picked',computer)
            print(name,' Wins!')
            return('won')
        elif win == False:
            print(name,'picked',player)
            print('The computer picked',computer)
            print(name,' Looses!')
            return('lost')
        else:
            print(name,'picked',player)
            print('The computer picked',computer)
            print("It's a draw!")
            return('draw')
    else:
        print('An error occured')
        print('printing debug')
        debugger(player,computer)
        return('Error')


def space(spaces): # a thing to make a lot of spaces for me easily
    for x in range(spaces):
        print('')





if __name__ == "__main__":  # maybe I will import this script somewhere and want to call the rps function. It's also just good practice
    clear()
    
    file = open("names.txt",'r') # text file opened here: I use vscode, so I told it to use the same location my program is to search for the file.
    players = file.readlines() #store the file as an array becasue I'm lazy
    #print(players)
    #print(len(players))

    gameList = []

    for x in range(len(players)): # we will run this loop for each entry into the array
        player = players[x]
        pos = player.find('-')
        print('')
        if pos >= 0:
            name = player.split('-')[0]
            choice = player.split('-')[1]
            name = name.strip()
            choice = choice.strip()
            #print(name,choice)
            score = rps2(name,choice)
            gameList.insert(x,name + ':' + choice + ' - ' + score)

        else:
            print('player', x+1 , 'is incorrectly formatted')




    space(4)
    print(gameList) # print the winners as such
    space(2)
        
        
    #rps2('test','rock')

    file.close()
