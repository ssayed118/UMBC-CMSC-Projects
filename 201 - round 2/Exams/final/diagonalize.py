"""
File: diagonalize.py
Author: Sumaa Sayed
Date: 5/17/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will look for digonals in a grid.
"""

def detect_diagonal(the_grid, row, col):
    """
    This function will look for a digonal match in the grid.
    :param the_grid: 2d list used for this function
    :param row: how far the function will run, horizontal wise
    :param col: how far the funciton will run, vertical wise
    """
    
    #checking positive slopes
    for i in range(len(the_grid[row]) - 3):
        for j in range(len(the_grid[col]) - 3):
            while the_grid[i][j] != ' ':
                
#setting a symbol for the loop to check if there are any matches in the diagonals
                symbol = the_grid[i][j]
                if the_grid[i+1][j+1] == symbol or the_grid[i+2][j+2] == symbol or the_grid[i+3][j+3]== symbol:
                    return True
                
                return False
            
    #checking negative slopes
    for i in range(len(the_grid[row]) - 3):
        for j in range(3, len(the_grid[col])):
            while the_grid[i][j] != ' ':
        
                symbol = the_grid[i][j]
                if the_grid[i-1][j-1] == symbol or the_grid[i-2][j-2] == symbol or the_grid[i-3][j-3]== symbol:
                    return True
                
                return False
        
if __name__ == "__main__":
    the_grid = [[' ', 'x', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', 'p'], ['a', ' ', ' ', 'x', ' ', ' '], [' ', '*', ' ', '', ' ', '2'], [' ', ' ', ' ', ' ', ' ', ' '], [' ', ' ', ' ', ' ', ' ', ' ']]

    the_grid = [[' ', ' ', ' ', ' ', ' ', 'b'], [' ', ' ', ' ', ' ', 'a', ' '], ['*', '*', ' ', ' ', ' ', ' '], [' ', ' ', ' ', '*', 'c', ' '], [' ', ' ', ' ', ' ', ' ', 'e'], [' ', ' ', ' ', ' ', ' ', 'e']]
                
    #print(detect_diagonal(the_grid, 3, 3))
