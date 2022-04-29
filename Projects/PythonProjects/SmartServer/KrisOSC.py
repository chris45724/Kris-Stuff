from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer
import os
from pythonosc.udp_client import SimpleUDPClient
from Kris import *


    






def print_handler(address, *args):
    print(f"{address}: {args}")
    #pass


def kieranGay(address, *args):
    print("\nHAHA You're gay lol")


def default_handler(address, *args):
    
    print(f"Not handled\nAddress: {address} Value: {args}")
    print("")
    if(args[0] == 3):
        clear()
    pass





if __name__ == '__main__':
    
    # set up dispacher
    dispatcher = Dispatcher()
    clear()   

    #dispacher tree
    #dispatcher.map("/Kris/HeartRate",heartRate)
    
    dispatcher.map("/test/kieranGay", kieranGay)
    dispatcher.set_default_handler(default_handler)

    ip = str(getIP())
    #port = int(input("Please enter a port: "))
    port = 9999

    server = BlockingOSCUDPServer((ip, port), dispatcher)
    print("""
    ###########################
    #         STARTING        #
    #          SERVER         #   
    ###########################      
    """)
    print(f'Local IP address is: {ip}\nComputer Network name is: {getName()}')
    print("\n---------- Server Output -----------")
    try:
        server.serve_forever()  # Blocks forever
        #server.serve()
    except KeyboardInterrupt:
        print("""
    ###########################
    #         STOPPING        #
    #          SERVER         #
    ###########################        
            """)
        pass
