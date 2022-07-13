""" 
File: major.py
Author: Sumaa Sayed
Date: 9/18/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input their major, and find out what grade they need to receive for CMSC201 to count for credit. An if-else block will be used to compare strings.
"""

if __name__ == '__main__':
    major_input = str(input('Enter your major: '))
    print("What is your major?", major_input)
    if major_input == "CMSC" or major_input == "CMPE":
         print("You need to earn at least a B for CMSC 201 to count.")
    else:
         print("You need to earn at least a C for CMSC 201 to count.")
