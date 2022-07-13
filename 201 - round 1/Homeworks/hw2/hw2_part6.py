"""
File: hw2_part6.py
Author: Sumaa Sayed
Date: 9/20/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to determine if a door will open up, depending on the answers they input for each lever.
"""

if __name__ == '__main__':
    # asks the user which levers they want to pull 
    first = str(input('Pull the first lever: '))
    print("Do you pull the first lever?", first)
    
    second = str(input('Pull the second lever: '))
    print("Do you pull the second lever?", second)
    
    third = str(input('Pull the third lever: '))
    print("Do you pull the third lever?", third)

    if first == "yes" or third == "yes" and second == "no":
        print("The door opens!")
        
    # if the user decides to pull the second lever, then they will receive a response
    else:
        print("The door remians shut.")
        
