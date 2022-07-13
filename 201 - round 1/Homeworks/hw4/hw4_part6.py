"""
File: hw4_part6.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: sssayed1@umbc.edu
Description: This program allows the user to input a width and a height for a "counting box".
"""

if __name__ == '__main__':
    width = int(input('Enter a width: '))
    height = int(input('Enter a height: '))
   # seting varibales for the width and height
   
    height_count = 0
    width_count = 0

    string = ""
    # for i loop to count numbers based on width and height of box
    for i in range(width * height):
        string = string + " " + str(i)
        width_count = width_count + 1
        # print new line based on the width of the box
        if width_count == width:  
            print(string) 
            string = " "
            width_count = 0
