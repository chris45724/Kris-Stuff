import krpc
import asyncio
from Kris import *
clear() 
print("Running?")
conn = krpc.connect()
ksp = conn.krpc
game = conn.space_center

print(f'{ksp.get_status().version}')
def checker():
    pass

def mainLoop():
    print("test")
    print(ksp.current_game_scene)
    
    
    
    


if __name__ == '__main__':
    av = conn.space_center.active_vessel
    vessel = av
    testFile = open(localFile("Test.txt"),'w')
    #surface = vessel.surface_velocity_reference_frame
    ref_frame = conn.space_center.ReferenceFrame.create_hybrid(
        position=vessel.orbit.body.reference_frame,
        rotation=vessel.surface_reference_frame)
    #while True:
        #mainLoop()
    #print(av)
    #print(game.bodies)
    print(f"Mass of the craft is: {round(av.mass,2)}KG\nMax Thrust is: {round(av.available_thrust,2)}N")
    print("\n\n")
    while True:
        data = velocity(surface)
        
        print(f"{data}")
        #if(data[0] != float(0)):
        #    print(f" [0] {data[0]}")
        #if((data[1]) != float(0)):
        #   print(f" [1] {data[1]}")
        #if((data[2]) != float(0)):
        #    print(f" [2] {data[2]}")
    
    
    
    