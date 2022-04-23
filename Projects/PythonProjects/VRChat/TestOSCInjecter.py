import pythonosc
import random
import time
from pythonosc import *
from pythonosc.udp_client import SimpleUDPClient




ip = "127.0.0.1"
port = 8000

client = SimpleUDPClient(ip, port)  # Create client
#send=client.send_message()


#client.send_message("/some/address", 123)   # Send float message
#client.send_message("/some/address", [1, 2., "hello"])  # Send message with int, float and string
#client.send_message('/something2/test2/',True) 
#client.send_message("/Kris/HeartRate", 25)
print("Sending")
client.send_message("/Test/Networking",25)