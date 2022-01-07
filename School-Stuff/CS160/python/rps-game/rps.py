
import os # for the clear function! Maybe I should get rid of this
import random # for the random functions
import turtle



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


def roboplayer():
    list = ['rock', 'paper', 'scissors']
    return random.choice(list)
    
    


def rps(): # recycling my code becasue I'm super lazy!!

    play = True # we use this to see if they want to keep playing

    clear()

    robo = input('Play against computer? "yes"/"no" ')

    # we check to see if the player want's to play against the computer

    if robo == "yes": 
        print('ok')
    elif robo == "no":
        print('ok')
    else:
        print('Unknown anwser! Defaulting to yes')  # super simple catch to see if player put in real anwser
        robo = 'yes'



    while play == True:
        
        
        # no more clearing. We have to give feedback to the userser for playing against robo


        print('')
        print('')
        print('')
        print('')

        print("Lets play Rock Paper Scissors!!!")
        
        
        # I have to call my variables or python gets angy

        #p1pass = False
        #looplimit = 0
        #p2pass = False
        die = False

        print("Player one's choice! no peaking player two!")
        
        ###### Playerpicker p1 #######
        player1 = playerpicker()
        p1pass = valid(player1)

        
        #print(p1pass,player1) # I left this in last week... It was supposed to be for debug

        
        
        clear() # fancy scren clear
        
        print("Player twos's choice! no peaking player one!")
        
    
        # do they play a robot?
        if robo == 'yes':
            player2 = roboplayer() 
        else:
            player2 = playerpicker()
        
        
        p2pass = valid(player2)
        #print(p2pass,player2)

        ###### Playerpicker p2 #######
        
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
            print('Player 1 picked:',player1)
            print('Player 2 picked:',player2)
            
            print(winner(player1,player2))

            if robo == 'yes':
                drawer(winner(player1,player2),player1)

            print('The game is over')
            print('would you like to play again?')
            playagain = input("yes/no ")
            if playagain == 'yes':
                play = True
            else:
                play = False
        
        if die == False and player1 == player2: # we check for a tie
            print('Player 1 picked:',player1)
            print('Player 2 picked:',player2)

            print("It's a tie!")
            print('would you like to play again?')
            playagain = input("yes/no ")
            if playagain == 'yes':
                play = True
            else:
                play = False


    #print(player1,player2)


    #print("p1:",p1pass,'p2:',p2pass)


def blade_scissors(x,y): # x is direction, and y was distance. Got lazy

    turtle.speed(4)
    turtle.setheading(x)
    turtle.pd()
    turtle.forward(y)
    turtle.pu()
    turtle.backward(y)
    turtle.setheading(0)

def handle_scissors(x,y,z): # X is direction, Y is Distance, and Z is radius
    turtle.setheading(x)
    turtle.color('red')
    turtle.pd()
    turtle.backward(y)
    turtle.circle(z)
    turtle.pu()
    turtle.forward(y)
    turtle.setheading(0)


def draw_scissors():
    blade_angle = 35 # setting top blade angle
    blade_langth = 215 # setting blade 2 angle to - blade 1
    turtle.pu()
    turtle.setposition(-40, 0)
    turtle.pensize(5)
    turtle.speed(30)
    turtle.color('grey')
    blade_scissors(blade_angle,blade_langth) # got lazy. Made repeatable
    blade_scissors(-blade_angle,blade_langth)
    turtle.color('red')
    turtle.pensize(7)
    handle_scissors(blade_angle,blade_langth/3,-blade_langth/6)
    handle_scissors(-blade_angle,blade_langth/3,blade_langth/6)
    turtle.pu()
    turtle.setposition(0,0) # return to 0,0 to start another thing i guess


def draw_rock():
    bottom = 150 # defining the size. Labled bottom becasue it was going to only be the bottom side. Shapes are scalable, so i based everything off this one size. math is cool
    turtle.pensize(5)

    turtle.color('brown')
    turtle.pensize(5)
    turtle.pu()
    turtle.forward(bottom)
    turtle.pd()
    turtle.begin_fill()
    turtle.backward(bottom*2)
    turtle.setheading(60)
    turtle.forward(bottom)
    turtle.setheading(0)
    turtle.forward(bottom)
    turtle.setheading(-60)
    turtle.forward(bottom)
    turtle.end_fill()
    turtle.pu()
    turtle.setpos(0,0)
    
def draw_paper(): # i am sorry this isnt centerd. I am to tired to center it!

    size = 70 # look at rocks 'bottom'
    turtle.pensize(5)


    # draw a black box becasue we cant seet he white paper
    h=0 # h is the angle we are on for our box. A square has 360 degrees in it.


    turtle.color('black')
    turtle.pu()
    turtle.setheading(90)
    turtle.forward(-size)
    turtle.setheading(0)
    turtle.forward(-size*3)
    turtle.pd()
    turtle.begin_fill()
    while h in range(360):
        turtle.setheading(h)
        turtle.forward(size*5)
        h = h + 90
    turtle.end_fill()
    turtle.pu()
    #turtle.speed(1) used for debugging
    turtle.setheading(0)
    turtle.forward(size*2)
    turtle.setheading(90)
    turtle.forward(size)
    turtle.setheading(0)




    #paper starts here! yay!
    turtle.setheading(0)
    turtle.color('white')
    turtle.pensize(5)
    turtle.pu()
    turtle.forward(size)
    turtle.pd()
    turtle.begin_fill()
    turtle.forward(-size*2)
    turtle.setheading(60)
    turtle.forward(size*3)
    turtle.setheading(0)
    turtle.forward(size*2)
    turtle.setheading(60)
    turtle.forward(-size*3)
    turtle.end_fill()


def draw_human():

    turtle.color('black')

    turtle.pensize(4)
    size = 30

    turtle.pu() # all the stuff that makes it an h is here...
    turtle.forward(size/2)
    turtle.pd()
    turtle.forward(-size)
    turtle.setheading(90)
    turtle.forward(-size)
    turtle.forward(size*2)
    turtle.forward(-size)
    turtle.setheading(0)
    turtle.forward(size)
    turtle.setheading(90)
    turtle.forward(-size)
    turtle.forward(size*2)
    turtle.forward(-size)
    turtle.setheading(0)
    turtle.forward(-size/2)
    turtle.pu()




def draw_computer(): # draw computer... 
    turtle.color('black')

    turtle.pensize(4)
    size = 30
    #turtle.speed(1)
    turtle.pd()
    turtle.setheading(28)
    turtle.circle(size, -230)
    turtle.pu()
    turtle.forward(30)


def turttest():
    turtle.Screen()
    #draw_scissors()
    #draw_rock()
    #draw_paper()
    #draw_human()
    draw_computer()

def drawer(winner,pchoice): # we draw what the player chose, and we draw who won!
    turtle.Screen()

    if pchoice == 'rock':
        draw_rock()
        pass

    if pchoice == 'paper':
        draw_paper()

    if pchoice == 'scissors':
        draw_scissors()


    if winner == 'Player 2 Wins':

        turtle.pu()
        turtle.setheading(-90)
        turtle.forward(150)
        turtle.setheading(0)
        draw_computer()
    else:
        turtle.pu()
        turtle.setheading(-90)
        turtle.forward(150)
        turtle.setheading(0)
        draw_human()





if __name__ == "__main__":  # maybe I will import this script somewhere and want to call the rps function. It's also just good practice
    clear()
    
    #turttest()

    #end = input() # kills the script... used for debugging turtles
    #exit()
    turtle.hideturtle()
    rps()