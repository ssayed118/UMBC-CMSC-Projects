# File:    hailstone.py
# Started: by Dr. Gibson
# Author:  Sumaa Sayed
# Date:    4/6/20
# Section: 16
# E-mail:  ssayed1@umbc.edu
# Description:
#   This file contains python code that implements the
#   "flight" of a hailstone, following the HOTPO rules
#   (also known as the Collatz Conjecture), recursively

# NO CONSTANTS NEEDED, THE NUMBERS USED IN flight() ARE
#    PART OF A FORMULA/MATHEMATICAL CONJECTURE

############################################################
# flight() recursively calculates the path of a hailstone
# Input:   the height of the hailstone
# Output:  a recursive call, which at the end returns 
#          the number of "steps" taken for the
#          hailstone to reach a height of 1
def flight(height):

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
        height =  height // 2
        return flight(height) + 1
    
    # if the current height is odd, multiply it by 3, then add 1
    else:
        height = (height * 3) + 1
        return flight(height) + 1

def main():

    print("Welcome to the Hailstone Simulator!")
    msg = "Please enter a height for the hailstone to start at: "
    startHeight = int(input(msg))

    # recursive call goes here
    steps = flight(startHeight)

    print("\nIt took", steps, "steps to hit the ground.")

    print("Thank you for using the Hailstone Simulator!\n")

main()

    

