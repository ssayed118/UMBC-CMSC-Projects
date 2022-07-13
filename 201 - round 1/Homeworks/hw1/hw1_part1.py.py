"""
File: hw1_part1.py
Author: Sumaa Sayed
Date: 9/12/19
Section: 16
E-mail: ssayed1@umbc.edu
Description: This program allows for the user to add up the amount of peppers, onions, and tortillas that are in their pantry.  
"""

if __name__ == '__main__':
    num_peppers = 5
    num_onions = 8
    num_tortillas = 18
    #num_total = 0

    print("I have", num_peppers, "peppers in my pantry")
    print("I have", num_onions, "onions in my pantry")
    print("I have", num_tortillas, "tortillas in my pantry")

    num_total = num_peppers + num_onions + num_tortillas
    print("I have a total of", num_total, "items in my pantry")