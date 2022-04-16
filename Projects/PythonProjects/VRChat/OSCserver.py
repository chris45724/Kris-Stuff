from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer
from pynput.keyboard import Key, Controller
import os
from pythonosc.udp_client import SimpleUDPClient
hr = 0

def clear():
    os.system('cls' if os.name == 'nt' else 'clear')
    

keyboard = Controller()
def hrSender(hr):
    ip = "127.0.0.1"
    port = 9000
    client = SimpleUDPClient(ip, port)  # Create client
    temphr = hr
    hundreds = 0
    tens = 0
    ones = 0
    while temphr >= 100:
        #print(f'sub 100: {temphr-100}')
        temphr = temphr - 100
        hundreds += 1
    
    while temphr >= 10:
        #print(f'sub 10: {temphr-10}')
        temphr = temphr - 10
        tens += 1
    ones = temphr
    print(f'Heartrate:\n| Hundreds: {hundreds}\n| Tens: {tens}\n| Ones: {ones}')
    client.send_message('/avatar/parameters/onesHR',ones)
    client.send_message('/avatar/parameters/tensHR',tens)
    client.send_message('/avatar/parameters/hundredsHR',hundreds)

def vrcSender(location, data):
    ip = "127.0.0.1"
    port = 9001
    client = SimpleUDPClient(ip, port)
    client.send_message(f'/avatar/parameters/{location}', data)





def print_handler(address, *args):
    #print(f"{address}: {args}")
    pass

def heartRate(address, *args):
    global hr
    badRead = True
    if int(args[0]) > 0:
        hr = args[0]
        badRead = False
        hrSender(int(hr))
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




if __name__ == '__main__':
    
    # set up dispacher
    dispatcher = Dispatcher()
    clear()   

    #dispacher tree
    dispatcher.map("/Kris/HeartRate",heartRate)
    dispatcher.map("/avatar/change", avatarChange)
    dispatcher.map("/something/*", print_handler)
    dispatcher.map("/avatar/parameters/MuteSelf", discordMute)
    #dispatcher.set_default_handler(default_handler)

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
        keyboard.release(Key.pause)
        print("""
    ###########################
    #         STOPPING        #
    #         SERVER          #
    ###########################        
            """)
        pass

    #testhw = 330
    #print(f'Test Heart rate {testhw}')

    #hrSender(testhw)



    #server.serve_forever()  # Blocks forever