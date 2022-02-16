#Find the largest number

numbers = [10,4,56,34,78,22,45,33]

largest_number = numbers[0]

for num in numbers:
    if num > largest_number:
        largest_number = num
    print("New large number", largest_number)
print("Largest value in list is", largest_number)

#Find sum of numbers

numbers = [10,4,56,34,78,22,45,33]

total = 0
count = 0
for num in numbers:
    total += num # total = total + num
    count += 1
    
print(f'the total is {total} and count is {count}')
print(f'the average is {total/count}')

# while loops
# how many years to earn 1mil at 8% interest
#start with 1000


interest_rate = float(input("Enter an interest rate .0? "))
current_value = float(input("Enter a current value > 0:"))
while interest_rate < 0 or current_value < 0:
    print("Please enter positive values for rate and current value")
    interest_rate = float(input("Enter an interest rate .0? "))
    current_value = float(input("Enter a current value > 0:"))

year = 0
print('Year','\t',"Current Value")
while current_value < 1000000 :
    #current_value = current_value *  interest_rate
    current_value *= (1 + interest_rate)
    year += 1
    print(year, '\t', format(current_value,".2f"))


