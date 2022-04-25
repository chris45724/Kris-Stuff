from pythonosc.dispatcher import Dispatcher
from pythonosc.osc_server import BlockingOSCUDPServer
import os
from pythonosc.udp_client import SimpleUDPClient
from Kris import *


    







    


def default_handler(address, *args):
    print(f"Not handled\nAddress: {address} Value: {args}")
    print("")
    pass




if __name__ == '__main__':
    
    # set up dispacher
    dispatcher = Dispatcher()
    clear()   

    #dispacher tree
    #dispatcher.map("/Kris/HeartRate",heartRate)
    #dispatcher.map("/address/*", function)

    dispatcher.set_default_handler(default_handler)

    ip = "127.0.0.1"
    #port = int(input("Please enter a port: "))
    port = 9999

    server = BlockingOSCUDPServer((ip, port), dispatcher)
    print("""
    ###########################
    #         STARTING        #
    #          SERVER         #   
    ###########################      
    """)
    print(f'Local IP address is: {getIP()}\nComputer Network name is: {getName()}')
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
