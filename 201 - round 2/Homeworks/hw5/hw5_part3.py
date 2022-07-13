"""
File: hw5_part3.py
Author: Sumaa Sayed
Date: 3/6/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will ask the user for a symbol, and height, then print a triangle using those values.
"""

if __name__ == "__main__":
    #asking for symbol and height
    symbol = input('Enter triangle symbol: ')
    height = int(input('Enter height: '))

    #printing the triangle
    for i in range(height):
        print(symbol * (i+1))
