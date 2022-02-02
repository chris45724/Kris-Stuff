#Joe’s Gourmet Burgers—Vegetarian: No, Vegan: No, Gluten-Free: No
#Main Street Pizza Company—Vegetarian: Yes, Vegan: No, Gluten-Free: Yes
#Corner Café—Vegetarian: Yes, Vegan: Yes, Gluten-Free: Yes
#Mama’s Fine Italian—Vegetarian: Yes, Vegan: No, Gluten-Free: No
#The Chef’s Kitchen—Vegetarian: Yes, Vegan: Yes, Gluten-Free: Yes







JGB = True
MSP = True
CC = True
MFI = True
TCK = True



vegetarian = input("Is anyone vegetarian? ")
vegan = input("Is anyone vegan? ")
gf = input("Is anyone gluten-free? ")

if vegetarian.lower() == "yes":
    JGB = False
    
if vegan.lower() == "yes":
    JGB = True
    MSP = True
    MFI = True
    
if gf.lower() == "yes":
    JGB = True
    MFI = True
    
if JGB == True:
    print("Joe’s Gourmet Burgers")
    
if MSP == True:
    print("Main Street Pizza Company")

if CC == True:
    print("Corner Café—Vegetarian")
    
if MFI == True:
    print("Mama’s Fine Italian—Vegetarian")

if TCK == True:
    print("The Chef’s Kitchen")
