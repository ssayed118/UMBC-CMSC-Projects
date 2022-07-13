"""
File: hw3_part5.py
Author: Sumaa Sayed
Date: 2/14/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input a year and then display which animal corresponds with that year.
"""

if __name__ == "__main__":
    
    # list of animals
    zodiacs = ["Rat", "Ox", "Tiger", "Rabbit", "Dragon", "Snake", "Horse", "Goat", "Monkey", "Rooster", "Dog", "Pig"]

    #asking the user what year
    year = int(input('What is the year that you want to convert? '))

    # using % 12 to get the index for the corresponding animal
    animal = ((year - 4) % 12)
    print(zodiacs[animal])
