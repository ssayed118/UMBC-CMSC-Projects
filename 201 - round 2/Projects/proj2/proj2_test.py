"""
File: proj2_test.py
Author: Sumaa Sayed
Date: 4/19/20
Section: 16
Email: ssayed1@umbc.edu
Description: Test scripts for project 2, AdjournTheSpheres.
"""

from proj2 import AdjoinTheSpheres

#I'm gonna be super honest, I have no clue if these tests are even correct, so I'm just submitting what I think is right, so if this is being looked at before the actual project is due, then yikes. sorry!

def test_main_menu():
    """
    Function to print the main menu and get user input for what type of game they would like to play
    """
    #print menu
    #result = input('Select Option from the Menu: ')
    options = ["1", "2", "3"]
    
    if options == "1":
        print("test 1 passed")
    else:
        print("test 1 failed")

    if options == "2":
         print("test 2 passed")
    else:
        print("test 2 failed")

    if options == "3":
        print("test 3 passed")
    else:
        print("test 3 failed")

    if options != options:
        print("test 4 failed")
        #use while loop to validate input
    else:
        print("test 4 passed")

    if options == options:
        print("test 5 passed")
    else:
        print("test 5 failed")

#renamed this function! 
def test_make_board_list(board_int):
    """
    This function will print the board.
    """
#    board = input('what board? ')
    if make_board_list('game_1.m') == [['', '', '', '', '', '', ''], ['', '', '', '', '', '', ''], ['', '', '', '', '', '', ''], ['', '', '', '', '', '', ''], ['', '', '', '', '', '', '']]:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if make_board_list('game_2.m') == [['x', '', 'o', '', 'x', 'x', ''],['x', '', 'o', '', '', '', ''], ['', 'o', '', '', '', '', ''], ['x', 'o', '', 'o', 'o', 'o'], ['x', '', 'x', 'x', '', '', '']]:
        print("test 2 passed")
    else:
        print("test 2 failed")

    if make_board_list('game_3.m') == [['', '', '', '', '', '', ''], ['x', '', '', '', '', '', 'o'], ['', '', '', '', '', '', ''], ['', '', '', 'x', '', '', ''], ['o', 'x', '', 'o', '', '', '']]:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if make_board_list('game_4.m') == [['x', '', '', 'o', '', 'x', 'x'], ['', '', '', '', '', '', ''], ['', '', 'o', '', '', '', ''], ['x', 'o', '', 'o', 'o', 'o'], ['x', '', 'x', 'x', '', '', '']]:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if make_board_list('game_5.m') == [['','', '', '', '', '', ''], ['', '', '', '\
', '', '', ''], ['', '', '', '', '', '', ''], ['', '', '', '', '', '', ''], ['','', '', '', '', '', 'x']]:
        print("test 5 passed")
    else:
        print("test 5 failed")
        
def test_player_moves(board_list):
    """
    This function will check user input to make sure that the postion they enterd is valid. 
    """
    #move = input('where do you wanna go? ') // gets split to move[0] & move[1]
    if len(move) == 2:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if len(move[0]) in range(board_list):
       	print("test 2 passed")
    else:
        print("test 2 passed")

    if len(move[1]) in range(board_list[0]):
        print("test 3 passed")
    else:
        print("test 3 failed")

#changed these 2 tests a little
    if board_list[move[0]][move[1]] != self.FORBIDDEN:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if board_list[move[0]][move[1]] != self.BLANK:
        print("test 5 passed")
    else:
        print("test 5 failed")

#i totally screwed up these tests when i first wrote them so this entire function was re-written
def test_check_game(board_list):
    """
    This function will check for a winner.
    """
    #use for loop to get i and j then these tests would work nicely
    if board_list[i][j] == PIECE_X and board_list[i+1][j] == PIECE_X and board_list[i+2][j] == PIECE_X and board_list[i+3][j] == PIECE_X:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if board_list[i][j] == PIECE_X and board_list[i][j+1] == PIECE_X and board_list[i][j+2] == PIECE_X and board_list[i][j+3] == PIECE_X:
        print("test 2 passed")

    else:
        print("test 2 passed")

    if board_list[i][j] == PIECE_X and board_list[i+1][j+1] == PIECE_X and board_list[i+2][j+2] == PIECE_X and board_list[i+3][j+3] == PIECE_X:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if board_list[i][j] == PIECE_X and board_list[i-1][j+1] == PIECE_X and board_list[i-2][j+2] == PIECE_X and board_list[i-3][j+3] == PIECE_X:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if board_list[i][j] == PIECE_0 and board_list[i+1][j] == PIECE_O and board_list[i+2][j] == PIECE_O and board_list[i+3][j] == PIECE_O:
        print("test 5 passed")
    else:
        print("test 5 failed")

                                   
if __name__ == "__main__":
    print(test_main_menu())
    print(test_make_board_list(board_int))
    print(test_player_moves(board_list))
    print(test_check_game(board_list))
