"""
File: hw5_part3.py
Author: Sumaa Sayed
Date: 10/14/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input the height, and symbol to print out a triangle.
"""

if __name__ == '__main__':
    # asks the user for the height
    height = int(input('What is the height of the triangle?: '))

    # asks the user for the symbol
    symbol = input('What is the symbol for the triangle?: ')

    # printing the triangle
    for i in range(height):
        print((symbol) * (i + 1)) 
