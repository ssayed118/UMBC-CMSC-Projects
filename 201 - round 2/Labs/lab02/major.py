"""
File: major.py
Author: Sumaa Sayed
Date: 2/10/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input their major, and see what grade they need for 201 to count.
"""
if __name__ == "__main__":
    
    major = input('Please enter your major: ')

    if major == "CMSC" or major == "CMPE":
        print("You need to earn at least a B for CMSC 201 to count.")

    else:
        print("You need to earn at least a C for CMSC 201 to count.")
    

