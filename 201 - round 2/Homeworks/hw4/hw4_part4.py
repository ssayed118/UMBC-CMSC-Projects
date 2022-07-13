"""
File: hw4_part4.py
Author: Sumaa Sayed
Date: 2/24/20
Section: 16
Email: ssayed1@ umbc.edu
Description: This program will print a checkerboard, depending on the size that the user inputs.
"""

if __name__ == "__main__":

    # asking the user what size
    size_board = int(input('What size checkerboard do you want to draw? '))

    #i = row , j = column
    for i in range(size_board):
        for j in range(size_board):

            # if the column and row are "even" then print a black square
            if i % 2 == 0 and j % 2 == 0:
                print('\u25a0', end="")

            # column is even and row is odd, print white
            elif i % 2 == 0 and j % 2 == 1:
                print('\u25a1', end="")

            # column is odd, row is even, print white
            elif i % 2 == 1 and j % 2 == 0:
                print('\u25a1', end="")

            # column is odd, row is odd, print black
            else:
                print('\u25a0', end="")        

        #printing the complete board
        print()
