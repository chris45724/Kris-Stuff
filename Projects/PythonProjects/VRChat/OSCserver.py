from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer
from pynput.keyboard import Key, Controller

keyboard = Controller()


def print_handler(address, *args):
    #print(f"{address}: {args}")
    pass

def discordMute(address, *args):
    print(f"VRChat mute status: {args[0]}")
    if args[0] == True:
        print("Unmuting Discord")
        keyboard.release(Key.pause)
    else:
        print("Muting Discord")
        keyboard.press(Key.pause)
    print('')

def default_handler(address, *args):
    #print(f"DEFAULT {address}: {args}")
    pass


dispatcher = Dispatcher()
dispatcher.map("/something/*", print_handler)
dispatcher.map("/avatar/parameters/MuteSelf", discordMute)
dispatcher.set_default_handler(default_handler)

ip = "127.0.0.1"
port = 9001

server = BlockingOSCUDPServer((ip, port), dispatcher)
server.serve_forever()  # Blocks forever