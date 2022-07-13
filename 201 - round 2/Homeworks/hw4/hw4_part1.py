"""
File: hw4_part1.py
Author: Sumaa Sayed
Date: 2/22/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows for a user to input the height of a hailstone 
and then prints out the list of heights in a print statement.
"""

if __name__ == "__main__":

    # asking for height
    height = int(input('Please enter the starting height of the hailstone: '))

    # when height isn't 0 or 1, print the current height
    while height != 1 and height != 0:
        print("Hailstone is currently at height", height)

        # when height is even, it gets divided by 2
        if height % 2 == 0:
            height = height // 2

        # when height is odd
        else:
            height = (height * 3) + 1
            
    # quit once height reaches 0 or 1        
    if height == 1 or height == 0:
        print("Hailstone stopped at", height)
