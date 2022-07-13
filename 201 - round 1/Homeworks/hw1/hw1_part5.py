"""
File: hw1_part5.py
Author: Sumaa Sayed
Date: 9/13/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows for the user to type in their name, and title, and responds with a greeting. 
"""

if __name__ == '__main__':
    family_name = str(input('Enter your family name: '))
    first_name = str(input('Enter your first name: '))
    title = str(input('Enter your title: '))
                      
    print("What is your family name?", family_name)
    print("What is your first name?", first_name)
    print("What is your title?", title)
    print("Please rise for", first_name, "of House", family_name, ",", title, "!")
