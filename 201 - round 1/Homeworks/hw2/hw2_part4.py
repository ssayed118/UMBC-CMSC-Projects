"""
File: hw2_part4.py
Author: Sumaa Sayed
Date: 9/19/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input the date and it will respnd with the day of the week. 
"""

if __name__ == '__main__':
    # asks the user to input a date and will respond with the corresponding  day of the week
    day_of_week = float(input('Enter a date: '))
    print("What day of September 2019 are we in?", day_of_week)

    # if the user inputs a number besides 1 thorugh 30, they will receive a response 
    if day_of_week <= 0 or day_of_week > 30:
        print("That's not a valid day.")

    elif day_of_week % 7 == 1:
        print("It's Sunday")
    elif day_of_week % 7 == 2:
        print("It's Monday")
    elif day_of_week % 7 == 3:
        print("It's Tuesday")
    elif day_of_week % 7 == 4:
        print("It's Wednesday")
    elif day_of_week % 7 == 5:
        print("It's Thursday")
    elif day_of_week % 7 == 6:
        print("It's Friday")
    elif day_of_week % 7 == 0:
        print("It's Saturday")
   
    # if the user inputs something besides numbers 1 through 30, then they will receive a response
    else:
        print("That's not a valid day.")