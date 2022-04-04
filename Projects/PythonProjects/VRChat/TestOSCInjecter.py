import pythonosc
import random
import time
from pythonosc import *
from pythonosc.udp_client import SimpleUDPClient




ip = "127.0.0.1"
port = 9001

client = SimpleUDPClient(ip, port)  # Create client

client.send_message("/some/address", 123)   # Send float message
client.send_message("/some/address", [1, 2., "hello"])  # Send message with int, float and string
client.send_message('/something2/test2/',True)