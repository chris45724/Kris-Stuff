#Problem #1
#Package retails for $99,

numberpurchased = float(input("How many packages were purchased? "))
originalvalue = 99
prediscountamount = numberpurchased * originalvalue

if numberpurchased < 10:
    percent = 0.0
    discountamount = ("No discount on original price")
elif numberpurchased < 20:
    percent = .10
    percentage = float((numberpurchased * originalvalue) * percent)
    discountamount = float((numberpurchased * originalvalue) - percentage)
elif numberpurchased < 50:
    percent = .20
    percentage = float((numberpurchased * originalvalue) * percent)
    discountamount = float((numberpurchased * originalvalue) - percentage)
elif numberpurchased < 100:
    percent = .30
    percentage = float((numberpurchased * originalvalue) * percent)
    discountamount = float((numberpurchased * originalvalue) - percentage)
elif numberpurchased > 100:
    percent = .40
    percentage = float((numberpurchased * originalvalue) * percent)
    discountamount = float((numberpurchased * originalvalue) - percentage)
print("Percent discount is ", percent * 100, ", total after discount is ", discountamount)