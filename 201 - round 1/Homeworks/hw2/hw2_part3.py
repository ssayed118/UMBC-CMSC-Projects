"""
File: hw2_part3.py
Author: Sumaa Sayed
Date: 9/19/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input a name of two monsters, and their amount of power, and then it will tell the user which monster wins the battle. 
"""

if __name__ == '__main__':
    #asks the user the names of the two monsters and their power levels
    first_monster = input('Enter the name of the first monster: ')
    print("What is the name of the first monster?", first_monster)
    first_power = int(input('Enter the power level of the first monster: '))
    print("What is the power level of the first monster?", first_power)
    second_monster = input('Enter the name of the second monster: ')
    print("What is the name of the second monster?", second_monster)
    second_power = int(input('Enter the power level of the second monster: '))
    print("What is the power level of the second monster?", second_power)

    # compares the amount of power of both monsters
    if first_power == second_power:
             print("It's a draw!")
    if first_power > second_power:
             print(first_monster, "wins!")

    # if the power of monster one is twice as powerful than the powers of the second monster, then the program will provide a response 
    if first_power > second_power*2:
             print(first_monster, "was super efficacious!")
    if second_power > first_power:
             print(second_monster, "wins!")
             
    # if the power of monster two is twice as powerful that the powers of the first monster, then the program will provide a response
    if second_power > first_power*2:
             print(second_monster, "was super efficacious!")