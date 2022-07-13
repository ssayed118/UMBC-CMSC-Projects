"""
File: hw2_part5.py
Author: Sumaa Sayed
Date: 2/8/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input a year and then display which animal corresponds with that year.
"""

if __name__ == "__main__":
    # getting the input from the user
    year = int(input('What is the year that you want to convert? '))

    #for each year, the year will be divided by 12, and depedning on the remainder, the program will print out which animal the year coresponds with
    if year % 12 == 0:
        print("This is the year of the Monkey")

    elif year % 12 == 1:
        print("This is the year of the Rooster")

    elif year % 12 == 2:
        print("This is the year of the Dog")

    elif year % 12 == 3:
        print("This is the year of the Pig")

    elif year % 12 == 4:
        print("This is the year of the Rat")

    elif year % 12 == 5:
        print("This is the year of the Ox")

    elif year % 12 == 6:
        print("This is the year of the Tiger")

    elif year % 12 == 7:
        print("This is the year of the Rabbit")

    elif year % 12 == 8:
        print("This is the year of the Dragon")

    elif year % 12 == 9:
        print("This is the year of the Snake")

    elif year % 12 == 10:
        print("This is the year of the Horse")

    elif year % 12 == 11:
        print("This is the year of the Goat")
        
