
import os # for the clear function! Maybe I should get rid of this



# a lot of this code was from my old rps script earlier this term!


def clear():
    
    os.system('cls' if os.name == 'nt' else 'clear')  #clear commandlet



def valid(choice1): #we check to see if the player choices are valid
    if choice1 == 'rock' or choice1 == 'paper' or choice1 == 'scissors':
        anwser1 = True
    else:
        anwser1 = False
    return(anwser1)


def winner(player1, player2): # checking who wins. Also does tie checking for future use
        if player1 == player2:
            return("Draw")
        if player1 == 'rock' and player2 == 'paper':
            return('Player 2 Wins')
        if player1 == 'rock' and player2 == 'sicssors':
            return('Player 1 Wins')
        if player1 == 'paper' and player2 == 'scissors':
            return('Player 2 Wins')
        if player1 == 'paper' and player2 == 'rock':
            return('Player 1 Wins')
        if player1 == 'scissors' and player2 == 'rock':
            return('Player 2 Wins')
        if player1 == 'scissors' and player2 == 'paper':
            return('Player 1 Wins')
    

def playerpicker():
    looplimit = 0
    ppass = False
    while looplimit < 5 and ppass == False:  # this loops 5 times trying to get the player to make a valid choice
            player = input('Your choices are "rock" "paper" "scissors"')
            ppass = valid(player)
            looplimit = looplimit + 1
            if ppass == False:
                print(str(looplimit) + '/5 trys')
            if looplimit == 5: # after 5 tries it will insult the player
                print('you are dumb')
    


def rps(): # recycling my code becasue I'm super lazy!!

    play = True # we use this to see if they want to keep playing

    clear()


    while play == True:

        clear()
        
        
        print("Lets play Rock Paper Scissors!!!")
        
        
        # I have to call my variables or python gets angy

        #p1pass = False
        #looplimit = 0
        #p2pass = False
        #die = False

        print("Player one's choice! no peaking player two!")
        
        while looplimit < 5 and p1pass == False:  # this loops 5 times trying to get the player to make a valid choice
            player1 = input('Your choices are "rock" "paper" "scissors"')
            p1pass = valid(player1)
            looplimit = looplimit + 1
            if p1pass == False:
                print(str(looplimit) + '/5 trys')
            if looplimit == 5: # after 5 tries it will insult the player
                print('you are dumb')
        
        #print(p1pass,player1) # I left this in last week... It was supposed to be for debug

        looplimit = 0  # reseting the loop varable for the next loop
        
        clear() # fancy scren clear
        
        print("Player twos's choice! no peaking player one!")

        while looplimit < 5 and p2pass == False:
            player2 = input('Your choices are "rock" "paper" "scissors"')
            p2pass = valid(player2)
            looplimit = looplimit + 1
            if p2pass == False:
                print(str(looplimit) + '/5 trys')
            if looplimit == 5:
                print('you are dumb')
        
        clear()

        if p1pass == False:  # we insult players
            die = True  
            print('player 1 never learned to read')
        
        if p2pass == False:
            die = True
            print('player 2 never learned to read')

        if die == True:  # we end the game with no option to replay
            print('The game is over, and no one wins')
            play = False

        if die == False and player1 != player2:  # one of the few times i used a !=
            print(winner(player1,player2))
            print('The game is over')
            print('would you like to play again?')
            playagain = input("yes/no ")
            if playagain == 'yes':
                play = True
            else:
                play = False
        
        if die == False and player1 == player2: # we check for a tie
            print("It's a tie!")
            print('would you like to play again?')
            playagain = input("yes/no ")
            if playagain == 'yes':
                play = True
            else:
                play = False


    #print(player1,player2)


    #print("p1:",p1pass,'p2:',p2pass)











if __name__ == "__main__":  # maybe I will import this script somewhere and want to call the rps function. It's also just good practice
    clear()

    rps()