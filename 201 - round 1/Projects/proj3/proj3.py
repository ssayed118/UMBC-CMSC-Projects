"""
File:    proj3.py
Author:  Sumaa Sayed
Date:    11/29/2019
Section: 16
E-mail:  ssayed1@umbc.edu
Description: This program will allow a user to score a game, called Go.
"""
# constants:
# final pieces/colors for the board
BLACK_PIECE = "X"
WHITE_PIECE = "O"

# "blank" spot in board
PIECE = "+"

# piece that has been looked at but needs to be colored  
WAITING = "W"

#okay there's some code that is commented out, but i'm going to keep it in just in case whoever is grading this wants to test out specific pieces of the code, apologies if that makes it more annoying to grade!

# row and column (parameters) might not be defined as accurately, honestly i'm just hoping that it makes sense...?
def color_board(input_board, row, column):
    """
    This function will color the board, recursively.
    :param input_board: the board being used to play the game
    :param row: the pieces that sit on the horizontal axis of the board
    :param column: pieces that sit on the vertical axis of the board
    :return: BLACK_PIECE or WHITE_PIECE in the board
    """
    # base cases
    # if the piece is already colored then just leave it
    if input_board[row][column] == BLACK_PIECE:
        return BLACK_PIECE
    elif input_board[row][column] == WHITE_PIECE:
        return WHITE_PIECE

    #recursive cases
#HELP ~ count = 11
#11 people helped me out with this one function so honestly shout out to all the ta's and Hamilton, y'all are the real ones + thank you for being patient and dealing with me :)

    else:
        # set uncolored spots to "dummy"/waiting
        input_board[row][column] = WAITING

        # for every single case below, the case with look in a specific direction and change the piece to correct color piece (X or O)
        
        # going up
        if row-1 >= 0 and input_board[row - 1][column] != WAITING:
            input_board[row][column] = color_board(input_board, row-1, column)
            if input_board[row][column] == BLACK_PIECE:
                input_board[row][column] = "X"
            if input_board[row][column] == WHITE_PIECE:
                input_board[row][column] = "O"
        
        #going left    
        if column-1 >= 0 and input_board[row][column-1] != WAITING:
            input_board[row][column] = color_board(input_board, row, column-1)
            if input_board[row][column] == BLACK_PIECE:
                input_board[row][column] = "X"
            if input_board[row][column] == WHITE_PIECE:
                input_board[row][column] = "O"

        # going down
        #changed thingy here ~ len(input_board[column])
        # for some reason, my program had an issue with board3 and the ta that helped added in the code in the above comment, so if it's giving errors then try adding in column (sorry!)~ it was definitly a for loop issue too
        if row+1 < len(input_board) and input_board[row+1][column] != WAITING:
            input_board[row][column] = color_board(input_board, row+1, column)
            if input_board[row][column] == BLACK_PIECE:
                input_board[row][column] = "X"
            if input_board[row][column] == WHITE_PIECE:
                input_board[row][column] = "O"
                
        #going right
        if column+1 < len(input_board[row]) and input_board[row][column+1] != WAITING:
            input_board[row][column] = color_board(input_board, row, column+1) 
            if input_board[row][column] == BLACK_PIECE:
                input_board[row][column] = "X"
            if input_board[row][column] == WHITE_PIECE:
                input_board[row][column] = "O"

        # returns the final colored board 
        return input_board[row][column]

def clear_space():
    """
    This function will obtain what board will be used and break up the board into 2d lists, to make it easier to color/ run through
    :return board_2d: the board broken up into a multidimensional list
    """
    
    #asking what board will be used to score & color
    input_board = input('What is the filename? ')
    board_2d = []
    print("We are scoring this board: ")

    #opening the file
    board_file = open(input_board)
    board = board_file.readlines()
    #print(board)

    # getting the 2d list of lines to color/recurse through
    for rows in board:
        current_row = []
        for i in rows:
            if i != "\n":
                current_row.append(i)
        board_2d.append(current_row)
     #  print(current_row)

    #closing board and returning the list
    board_file.close()
    return board_2d

# this function was originally just a function to display the scores, but that seemed really dumb at the time so i made it into a function that prints the colored board
def print_board(input_board):
    """ 
    A function that prints the final colored board.
    :param input_board: board that has been colored
    :return None:
    """
    # for loop to print out the rows and columns of the colored board
    for row in range(len(input_board)):
        for col in range(len(input_board)):                 
            input_board[row][col] = color_board(input_board, row, col)
        
def counting_total(input_board, row, column):
    """
    This function will count the total amount of black and white pieces.
    :param input_board: board that will be used for the game (chosen by user)
    :param row: the pieces that sit on the horizontal axis of the board 
    :param column: pieces that sit on the vertical axis of the board
    :return None:
    """
    # counters for black pieces (num_x) and white pieces (num_o)
    num_x = 0
    num_o = 0

    # for the columns and rows in the board...
    for row in range(len(input_board)):
        for column in range(len(input_board[row])):

            # ...if its a black or white piece then add 1
            if input_board[row][column] == BLACK_PIECE:
                num_x += 1
            if input_board[row][column] == WHITE_PIECE:
                num_o += 1
                
    # printing the total scores
    print("Black scored: ", num_x)
    print("White scored: ", num_o)
    # this lowkey looks like the tabbing is "wrong" but it's not! i know because i made sure to check it!!
    
if __name__ == "__main__":
    # getting the board that will be used
    input_board = clear_space()

    #printing the "blank" board 
    for row in range(len(input_board)):
        for column in range(len(input_board[row])):
            print(input_board[row][column], end='')
        print()
        #this print HAS to be here^ or else it just prints the uncolored board in lines instead of "normal"

    print("Here is the colored board: ")

    # this function returns black or white
    color_board(input_board, row, column)

    #returns the colored board
    print_board(input_board)

    # prints the colored board
    for row in range(len(input_board)):
        for column in range(len(input_board[row])):
            print(input_board[row][column], end='')
        print()
        # this print also has to be here, or else it'll just print the lines instead of the board
        
    # prints out the scores for each color
    counting_total(input_board, row, column)

# this was the first project that i was able to finish in its entirety so 
