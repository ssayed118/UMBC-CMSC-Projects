"""
File:    hailstone.py
Author:  Sumaa Sayed
Date:    11/13/2019
Section: 16
E-mail:  ssayed1@umbc.edu
Description:
  DESCRIPTION OF WHAT THE PROGRAM DOES
"""
# NO CONSTANTS NEEDED, THE NUMBERS USED IN flight() ARE
#    PART OF A FORMULA/MATHEMATICAL CONJECTURE

def flight(height):
    """
    flight() recursively calculates the path of a hailstone
    :param height: the height of the hailstone
    :return: a recursive call, which at the end returns
       the number of "steps" taken for the
       hailstone to reach a height of 1
    """
    print("Height of", height)
    #### BASE CASES:
    # if height is zero or lower, print out an "invalid" message and return 0
    if height <= 0:
        print("Invalid height of", height)
        return 0
    # stops when it reachs height of 1 (the ground)
    if height == 1:
        return 0
    
    #### RECURSIVE CASES:
    # if the current height is even, divide it by 2
    if height % 2 == 0:
        height = height // 2
        return flight(height) + 1
    # if the current height is odd, multiply it by 3, then add 1

    else:
        height = (height * 3) + 1
        return flight(height) + 1
    
if __name__ == '__main__':
    print("Welcome to the Hailstone Simulator!")
    msg = "Please enter a height for the hailstone to start at: "
    start_height = int(input(msg))

    steps = flight(start_height) 

    print("\nIt took", steps, "steps to hit the ground.")

    print("Thank you for using the Hailstone Simulator!\n")
