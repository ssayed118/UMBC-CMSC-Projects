"""
File: hw5_part1.py
Author: Sumaa Sayed
Date: 3/10/20
Section: 16
Email: ssayed1@umbc.edu
Description: Moving on a grid: This program allows a player to move around on a grid until they hit the G which is the goal. After they hit the G, the program ends. They can use w, a, s, d to move.  
"""
#only commented on the play_game function because that's the one that we were suposed to code

def draw_grid(rows, columns, player_row, player_col, goal_row, goal_col):
    """
    This function will draw the grid for you. 
    :param rows: number of rows (vertical direction)
    :param cols: number of cols (horizontal direction)
    :param player_row: Which row the player is in
    :param player_col: Which col the player is in
    :param goal_row: Where the goal is (row-wise)
    :param goal_col: Where the goal is (col-wise)
    """
    for row in range(rows):
        for col in range(columns):
            if row == player_row and col == player_col:
                print('A', end='')
            elif row == goal_row and col == goal_col:
                print('G', end='')
            else:
                print('.', end='')
        print()

def get_move():
    """
    This function will get the user's move. 
    """
    wasd = input('Enter w, a, s, d: ')
    while wasd not in ['w', 'a', 's', 'd']:
        wasd = input('You have not done as asked, Enter w, a, s, d: ')
    return wasd

def play_game(rows, columns, goal_x, goal_y):
    """
    This function will play the game.
    :param rows: number of rows
    :param columns: number of columns
    :param goal_x: row position of goal
    :param goal_y: col position of goal
    """
#A starts at 0,0 and G is elsewhere so while they're not in the same spot...
    current_x = 0
    current_y = 0

# this is code that i tried for the while loop but they either wouldn't stop after hitting the goal or they would only run upto ~5 times
#    truth = (current_x == goal_x and current_y == goal_y)
#while current_x != goal_x and current_y != goal_y:
#    while truth:                                  
#    while truth == False:

#this works v but i'm not a fan of it 
    while not(current_y == goal_y and current_x == goal_x):
        
        #drawing the board and using the players move to move A around 
        draw_grid(rows, columns, current_x, current_y, goal_x, goal_y)

        #getting the user's move to move A around the board
        direction = get_move()
        
        #going up
        if direction == "w":
            if current_x != 0:
                current_x = current_x - 1

        #going left
        if direction == "a":
            if current_y != 0:
                current_y = current_y - 1
                
        #going down
        if direction == "s":
            if current_x != (columns - 1):
                current_x = current_x + 1
                
        #going right
        if direction == "d":
            if current_y != (rows - 1):
                current_y = current_y + 1

    #once A has reached G's position, the game ends
    if current_x == goal_x and current_y == goal_y:
        print("You have reached the goal.")            

if __name__ == '__main__':
    
    rows, columns, goal_x, goal_y = [int(x) for x in input('Enter rows columns goal_row goal_col as integers: ').split()]
    
    play_game(rows, columns, goal_x, goal_y)
