"""
File: proj2.py
Author: Sumaa Sayed
Date: 4/13/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will mimic a slightly modified version of Connect 4.
"""

from random import randint
class AdjoinTheSpheres:
    #constants
    PIECE_X = "x"
    PIECE_O = "o"
    BLANK = ' '
    FORBIDDEN = "*"
    
    def __init__(self):
        """
        This function is the constructor, and sets a list for the board.
        """
        self.board_list = []
              
    def main_menu(self):
        """
        This function will print the main menu, and allow the user to pick what        type of game they want to play.
        """
        #printing the main menu
        print("AdjoinTheSpheres Main Menu")
        print("\t", "1) New Game (2 Player)")
        print("\t", "2) New Game (1 Player)")
        print("\t", "3) Exit Game")

        #getting the user input for what type of game they want to play
        options_list = ["1", "2", "3"]
        option = input('Select Option from the Menu: ')
        while option not in options_list:
            print("Invalid choice, try again")
            option = input('Select Option from the Menu: ')

        #for each function, the prorgram will run the appropriate functions
        if option == "1":
            board_int = input('What game/map do you want to load? ') 
            self.print_board(board_int)
            self.make_board_list(board_int)
            self.player_moves(self.board_list)
            
        if option == "2":
            board_int = input('What game/map do you want to load? ') 
            self.print_board(board_int)
            self.make_board_list(board_int)
            self.play_computer(self.board_list)

        #this is just to exit the program
        if option == "3":
            print()
        
    def print_board(self, board_int):
        """
        This function will print the board.
        :param board_int: the board that the user chooses in the main menu
        """
        #opening the file and printing the board
        board_file = open(board_int, "r")
        board_var = board_file.readlines()
        board = board_var[2:]
        print("  ", end='')
        
        for i in range(1, len(board[0]) - 1):
            print(str(i) + "|", end='')
        line = "  "
        print(len(board[0]) - 1)
        
        for i in range((len(board[0])*2) -1):
            line += "-"
        row = 1
        
        for place in board:
            print(line)
            print(row, end=' ')
            for piece in place:
                if piece != '\n':
                    print(piece + "|", end='')
            print()
            row += 1
            
        board_file.close()

    def make_board_list(self, board_int):
        """
        This function will create the 2d list for the board to be used.
        :param board_int: the board that the user chooses in the main menu
        """
#        board_list = []
        board_file = open(board_int, "r")
        board_var = board_file.readlines()
    
        for i in range(2, len(board_var)):
            board_2d = []
            for j in board_var[i]:
                if j != '\n':
                    board_2d.append(j)
            self.board_list.append(board_2d)

        board_file.close()
        #print(self.board_list)
        return self.board_list
    
    def player_moves(self, board_list):
        """
        This function will get the move for each player.
        :param board_list: list to be used for indexing and updating the board
        """
        #getting user input + validation
        move = input('Player x What move do you want to make?  Answer as row (vertical) column (horizontal) or save game or load game: ')
        if move == "save game":
            self.save_game(board_list)
                
        if move == "load game":
            board_int = input('What game/map do you want to load? ')
            self.print_board(board_int)
            self.make_board_list(board_int)
            self.player_moves(self.board_list)

        if move != "save game" or move != "load game":
#splitting the players move to make it easier to index and placing the piece
            move = move.split()
            row_move = int(move[0])
            col_move = int(move[1])

            #using boolean to keep getting the user input
            flag = True
            turn = 0
            #counter for switching players
            while flag == True:
                
                #player x
                if turn % 2 == 0:
                    turn += 1
                    for i in range(len(board_list)):
                        for j in range(len(board_list[i])):
                            
                #checking to see if the spot is blank, then placing the piece 
                            if board_list[row_move][col_move] == self.BLANK:
                                board_list[row_move][col_move] == self.PIECE_X
                                self.print_board_again(board_list)

                #if it's not blank then the user is prompted for another move
                            else:
                                print("The move you want to make is invalid.")
                                move = input('Player x What move do you want to make?  Answer as row (vertical) column (horizontal) or save game or load game: ')

                    #function that checks is if a player has won
                    self.check_game(board_list)
                    
                    #if the function finds a winner, then the game stops
                    if self.check_game(board_list) != True:
                        flag = False
                        
                #player o // my comments are the same as the above code but for player o so i'm not gonna comment on this and the play_computer function     
                else:
                    turn += 1
                    for i in range(len(board_list)):
                        for j in range(len(board_list[i])):
                            if board_list[row_move][col_move] == self.BLANK:
                                board_list[row_move][col_move] == self.PIECE_O
                                self.print_board_again(board_list)
                                
                            else:
                                print("The move you want to make is invalid.")
                                move = input('Player o What move do you want to make? Answer as row (vertical) column (horizontal) or save game or load game: ')
                        
                    self.check_game(board_list)
                    if self.check_game(board_list) != True:
                        flag = False
                        
    def print_board_again(self, board_list):
        """
        Function to print the board
        :param baord_list: list to be used for updating board
        """
        print("  ", end='')
        for i in range(1, len(board_list[0]) - 1):
            print(str(i) + "|", end='')
        line = "  "
        print(len(board_list[0]) - 1)
        for i in range((len(board_list[0])*2) -1):
            line += "-"
        row = 1
        for place in board_list:
            print(line)
            print(row, end=' ')
            for piece in place:
                if piece != '\n':
                    print(piece + "|", end='')
            print()
            row += 1

    def check_game(self, board_list):
        """
        This function will check for a winner.
        :param board_list: list to be used for indexing and updating the board
        """
#this function isn't workign and i'm pretty sure it has to do w/ the for loops

        #counters for each player
        count_x = 0
        count_o = 0
        
        #i = row, j = col..
        #checking vertical location
        for i in range(len(board_list)):
            for j in range(len(board_list[i]) - 3):        
                if board_list[i][j] == self.PIECE_X and board_list[i+1][j] == self.PIECE_X and board_list[i+2][j] == self.PIECE_X and board_list[i+3][j] == self.PIECE_X:
                    count_x += 1
                if board_list[i][j] == self.PIECE_O and board_list[i+1][j] == self.PIECE_O and board_list[i+2][j] == self.PIECE_O and board_list[i+3][j] == self.PIECE_O:
                    count_o += 1

        #checking horizontal direction
        for i in range(len(board_list) - 3):
            for j in range(len(board_list[i])):
                if board_list[i][j] == self.PIECE_X and board_list[i][j+1] == self.PIECE_X and board_list[i][j+2] == self.PIECE_X and board_list[i][j+3] == self.PIECE_X:
                    count_x += 1
                if board_list[i][j] == self.PIECE_O and board_list[i][j+1] == self.PIECE_O and board_list[i][j+2] == self.PIECE_O and board_list[i][j+3] == self.PIECE_O:
                    count_o += 1

        #checking positive slopes 
        for i in range(len(board_list) - 3):
            for j in range(len(board_list[i]) - 3):
                if board_list[i][j] == self.PIECE_X and board_list[i+1][j+1] == self.PIECE_X and board_list[i+2][j+2] == self.PIECE_X and board_list[i+3][j+3] == self.PIECE_X:
                    count_x += 1
                if board_list[i][j] == self.PIECE_O and board_list[i+1][j+1] == self.PIECE_O and board_list[i+2][j+2] == self.PIECE_O and board_list[i+3][j+3] == self.PIECE_O:
                    count_o += 1

        #checking negative slopes
        for i in range(len(board_list) - 3):
            for j in range(3, len(board_list[i])):
                if board_list[i][j] == self.PIECE_X and board_list[i-1][j+1] == self.PIECE_X and board_list[i-2][j+2] == self.PIECE_X and board_list[i-3][j+3] == self.PIECE_X:
                    count_x += 1
                if board_list[i][j] == self.PIECE_O and board_list[i-1][j+1] == self.PIECE_O and board_list[i-2][j+2] == self.PIECE_O and board_list[i-3][j+3] == self.PIECE_O:
                    count_o += 1

        #declaring the winner (or not)
        if count_x == 0:
            return True
        if count_o == 0:
            return True
        
        else:
            if count_x >= 1:
                print("Player X wins!")

            if count_o >= 1:
                print("Player O wins!")

            elif count_x == count_o:
                print("It's a tie!")

            else:
                print("Both players have lost.")
            
    def play_computer(self, board_list):
        """
        This function will allow the user to play against a computer.
        :param board_list: list to be used for indexing and updating the board 
        """
        
#comments on player_moves function are the same so not commenting here...
        move = input('Player x What move do you want to make?  Answeras row (vertical) column (horizontal) or save game or load game: ')
        if move == "save game":
            self.save_game(board_list)

        if move == "load game":
            board_int = input('What game/map do you want to load? ')
            self.print_board(board_int)
            self.make_board_list(board_int)
            self.play_computer(self.board_list)

        if move != "save game" or move != "load game":
            move = move.split()
            row_move = int(move[0])
            col_move = int(move[1])
            flag = True
            turn = 0
            while flag == True:
                if turn % 2 == 0:
                    turn += 1
                    for i in range(len(board_list)):
                        for j in range(len(board_list[i])):
                            if board_list[row_move][col_move] == self.BLANK:
                                board_list[row_move][col_move] == self.PIECE_X
                                self.print_board_again(board_list)
                                
                            else:
                                print("The move you want to make is invalid.")
                                move = input('Player x What move do you want tomake?  Answer as row (vertical) column (horizontal) or save game or load game: ')

                        
                    self.check_game(board_list)
                    if self.check_game(board_list) != True:
                        flag = False

                #computer turn
                else:
                    #row move
                    move_1 = randint(1, len(board_list))
                    #column move
                    move_2 = randint(1, len(board_list[0]))
    
                    turn += 1
                    for i in range(len(board_list)):
                        for j in range(len(board_list[i])):
                            if board_list[row_move][col_move] == self.BLANK:
                                board_list[row_move][col_move] ==  self.PIECE_O
                                self.print_board_again(board_list)
                                
                            else:
                                print("The move you want to make is invalid.")
                                move = input('Player o What move do you want to make? Answer as row (vertical) column (horizontal) or save game or load game: ')
        
                        
                    self.check_game(board_list)
                    if self.check_game(board_list) != True:
                        flag = False
                    
    def save_game(self, board_list):
        """
        This function will allow the user to save the game.
        :param board_list: list to be used for indexing and updating the board 
        """
        my_list = []
        file_name = input('What do you want to call your file? (remember to put ".m." or ".txt" at the end) ')
        file_name = file_name.lower()
        with open(file_name, "w") as write_file:
            my_list.append(board_list + '\n')

        write_file.writelines(my_list)
        #save_game.close(file_name)
        
if __name__ == "__main__":
    #calling the Class and Main Menu function
    var = AdjoinTheSpheres()
    option = var.main_menu()
