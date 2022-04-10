from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer
from pynput.keyboard import Key, Controller
import os

hr = 0


keyboard = Controller()

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')

def print_handler(address, *args):
    #print(f"{address}: {args}")
    pass

def heartRate(address, *args):
    global hr
    badRead = False
    if int(args[0]) > 0:
        hr = args[0]
        badRead = True
    print(f"\nHeart rate :{hr}")
    if badRead:
        print("Bad measurement\n")

def discordMute(address, *args):
    print(f"VRChat mute status: {args[0]}")
    if args[0] == True:
        print("Unmuting Discord")
        keyboard.release(Key.pause)
    else:
        print("Muting Discord")
        keyboard.press(Key.pause)
    print('')
    
def avatarChange(address, *args):
    x = args
    print(x)
    #return x

def default_handler(address, *args):
    #testfile = open('testfile.temp','w')
    print(f"DEFAULT: {address}: {args}")
    #testfile.write(f"DEFAULT {address}: {args}")
    pass

# set up dispacher
dispatcher = Dispatcher()
clear()


#dispacher tree
dispatcher.map("/avatar/parameters/HeartRate",heartRate)
dispatcher.map("/avatar/change", avatarChange)
dispatcher.map("/something/*", print_handler)
dispatcher.map("/avatar/parameters/MuteSelf", discordMute)
dispatcher.set_default_handler(default_handler)

ip = "127.0.0.1"
port = 9001

server = BlockingOSCUDPServer((ip, port), dispatcher)
print("""
###########################
#         STARTING        #
#         SERVER          #   
###########################      
""")
print("---------- Output -----------")
try:
    server.serve_forever()  # Blocks forever
    #server.serve()
except KeyboardInterrupt:
    print("""
###########################
#         STOPPING        #
#         SERVER          #
###########################        
        """)
    pass



#server.serve_forever()  # Blocks forever