"""
File: hw4_part1.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows for a user to input the height of a hailstone and the prints out the list of heights in a print statement.
"""

if __name__ == '__main__':
    height = int(input('Enter an integer: '))
    # height of the movement of the hailstone
    if height == 1 or height == 0:
        print("Hailstone stopped at", height)
    # quit
    
    while height != 1 and height != 0:
    # when the height is not 1 or 0, then the line below is printed
          print("Hailstone stopped at height", height)
          if height % 2 == 0:
              # is the height is even, then the heigh is divided by 2
              height = height // 2
          else:
          # if the height is odd, then the height is multiplied by 3 and 1 is added to that number
              height = (height*3) + 1
