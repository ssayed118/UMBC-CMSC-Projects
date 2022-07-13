"""
File: find_a_square.py
Author: Sumaa Sayed
Date: 4/17/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a 2d list, and look for a square.
"""

def find_a_square(the_grid, height, width):
    """
    This function will take in a grid, and check for squares.
    :param the_grid: 2d list that the program will sift through
    :param height: first index of the_grid
    :param width: second index of the_grid
    :return: either coordinates for the square or an empty list (no square)
    """
    #the -1 is to prevent index errors, and making sure it stays in range
    for i in range(height - 1):
        for j in range(width - 1):
            if the_grid[i][j] == "*" and the_grid[i+1][j] == "*" and the_grid[i+1][j+1] == "*":
                return [i, j]
    return [ ]

if __name__ == "__main__":
#    the_grid = [['', '', '', '', '', ''], ['', "*", "*", "*", '', "*"], ['', '', "*", "*", '', ''], ['', '', "*", '', "*", ''], ['', '', '', '', '', ''], ['', "*", '', '', '', '']]

    the_grid = [['', '', ''], ['', '', ''], ['', "*", '']]
    #made this for my own testing purposes but it should return []

#the_grid = input('enter a grid: ') // not sure how this program will run so putting this here incase there's some file or something

    for height in range(len(the_grid)):
        for width in range(len(the_grid)):
            print(the_grid[height][width], end="  ")
        print()
        #i know it doesn't say to print the_grid, but it helps visualize the problem so keeping it in, also sets the height and width parameters

    print(find_a_square(the_grid, height, width))
    
