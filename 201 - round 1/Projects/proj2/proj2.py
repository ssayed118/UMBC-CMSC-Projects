"""
File: design2.txt
Author: Sumaa Sayed
Date: 11/1/2019
Section: 16
E-mail: ssayed1@umbc.edu
Description: This program will simulate the pencil game, Sim.
"""
from proj2_ui import print_board
# whenever I say symbol or character, I’m talking about the character that the user inputs… apologies if that’s confusing!
# a good amount of my functions changed from my design doc so just a heads up
# once again, this code definitly is missing a lot of things..
# so my program stops after player 1 draws 2 lines... i've been working on this since like 6am today and it's jut not working out.. sorry!

def check_symbol(p1_character, p2_character):
    """
    A function that allows the players to chose their character.
    :param p1_character: character for player 1
    :param p2_character: character for player 2
    :return the symbols/character chosen
    """
    if len(p1_character) > 1:
        p1_character = input('Hello, what character would player 1 like to use?')
    if len(p2_character) > 1:
        p2_character = input('Hello, what character would player 2 like to use? ')
    while p1_character == p2_character:
        p2_character = input('Hello, what character would player 1 like to use? ')
    if len(p2_character) > 1:
        p2_character = input('Hello, what character would player 2 like to use? ')
    
def player_turn(p1_lines):
    """
    A function that allows player 1 to make a move
    :param make_move: getting the correct user to make a move
    :param p1_lines: lines for player 1
    :return None:
    """
    valid_move = False
    while not valid_move:
        p1_move = input('Enter a line for player 1: ')
        p1_move = p1_move.split()
        p1_move[0] = int(p1_move[0])
        p1_move[1] = int(p1_move[1])
        if p1_move not in p1_lines and p1_move not in p2_lines:
            valid_move = True
            p1_lines.append(p1_move)
            print_board(p1_lines, p1_character, p2_lines, p2_character)
            check_triangle(p1_lines, p2_lines)
#            player_2_turn(p2_lines)
        else:
            p1_move = input('Enter a line for player 1: ')
            
def player_2_turn(p2_lines):
   """                                                               
   A function that allows player 2 to make a move                              
   :param p2_lines: lines for player 2          
   :return None:                                                               
   """
   valid_move = False
   while not valid_move:
       p2_move = input('Enter a line for player 2: ')
       p2_move = p2_move.split()
       p2_move[0] = int(p2_move[0])
       p2_move[1] = int(p2_move[1])
       if p2_move not in p2_lines and p2_move not in p1_lines:
           valid_move = True
           p2_lines.append(p2_move)
           print_board(p1_lines, p1_character, p2_lines, p2_character)
           check_triangle(p1_lines, p2_lines)
 #          player_turn(p1_lines)
       else:
           p2_move = input('Enter a line for player 2: ')
            
def run_game(p1_character, p2_character, p1_move, p2_move):
    """
    A function that will run the game.
    :param p1_character: character for player 1
    :param p2_character: character for player 2
    :param p1_move: move that player 1 makes
    :param p2_move: move that player 2 makes
    :return None:
    """
    #p1_lines = []
    #p2_lines = []
    make_list = []
    keep_going = True
    while keep_going != True:
        p1_move = input('Enter a line for player 1: ')
        player_turn(p1_lines, p2_lines)
        check_triangle(make_list)
        print_board(p1_lines, p1_character, p2_lines, p2_character)
        p2_move = input('Enter a line for player 2: ')
        player_turn(p1_lines, p2_lines)
        check_triangle(make_list)
        print_board(p1_lines, p1_character, p2_lines, p2_character)
        keep_going = True
        
def check_triangle(p1_lines, p2_lines):
    """
    A function that checks to see if the player has made a triangle.
    :param p1_lines: lines that player 1 has drawn
    :param p2_lines: lines that player 2 has drawn
    :return None:
    """
    # honestly, not even sure if this function works right because the game stops after player 1 makes 2 lines
    make_list = [p1_lines, p2_lines]
    for i in range(len(make_list)):
       make_list[i] = make_list
       for j in range(len(make_list)):
           make_list[j] = make_list[i]
       for k in range(len(make_list)):
           make_list[k] = make_list[i]
           return False
       else:
           return True

# if input is [1 2] or [2 1]v
def checking_moves(p1_move, p2_move):
    """                                                                        
    A function that checks that if the 2 players have valid inputs
    :return None or input                                       
    """
    # okay so i know these are magic numbers, but i'm having a meltdown so i'm sorry in advance
    if p1_move[0] > 6 and p1_move[1] > 6:
        p1_move = input('Enter a line for player 1: ')
    if p1_move[0] < 1 and p1_move[1] < 1:
        p1_move = input('Enter a line for player 1: ')
    if p2_move[0] > 6 and p1_move[1] > 6: 
        p2_move = input('Enter a line for player 2: ')
    if p2_move[0] < 1 and p2_move[1] < 1:
        p2_move = input('Enter a line for player 2: ')
        
#def ending_game():

if __name__ == "__main__":
    p1_lines = []
    p2_lines = []
    p1_character = input('Hello, what character would player 1 like to use? ')
    p2_character = input('Hello, what character would player 2 like to use? ')

    check_symbol(p1_character, p2_character)
    print_board(p1_lines, p1_character, p2_lines, p2_character)
    player_turn(p1_lines)
    player_2_turn(p2_lines)
    run_game(p1_character, p2_character, p1_lines, p2_lines)
    a = 0
    index = 0
    while index != 1:
        if a == 0:
            player_turn(p1_lines)
            if check_triangle(p1_lines, p2_lines) ==  True:
                #print("Game over. Player 1 loses")
                a += 1
            else:
                print("Game over. Player 1 loses.")
                index += 1
        elif a == 1:
            player_2_turn(p2_lines)
            if check_triangle(p2_lines, p1_lines) == True:
                #print("Game over. Player 2 loses")
                #player_turn(p1_lines, p2_lines)
                a -= 1
            else:
                #player_turn(p1_lines, p2_lines)
                print("p2 loses")
                index += 1
    checking_moves(p1_move, p2_move)
#    run_game(p1_character, p2_character, p1_lines, p2_lines)
    #check_triangle(p1_lines, p2_lines)
    #run_game(p1_character, p2_character, p1_lines, p2_lines)
    #check_triangle(make_list)
