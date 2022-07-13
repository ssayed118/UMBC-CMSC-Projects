"""
File: hw2_part4.py
Author: Sumaa Sayed
Date: 2/8/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to enter in a year, and determine if it is a leap year, or not.
"""

if __name__ == "__main__":
# asking the user what year they would like to check
    year = int(input('Which year do you want to know if it is a leap year? '))

    # if the year is divisible by 4 or 400, and not 100 then its a leap year
    if year % 4 == 0 and year % 100 != 0:
        print("This is a leap year")
        
    elif year % 400 == 0:
        print("This is a leap year")

    # if the year is less than 1
    elif year < 1:
        print("The year is less than 1 AD/CE, we aren't going back in time.")

    # for any year that is not a leap year
    else:
        print("This is not a leap year")
