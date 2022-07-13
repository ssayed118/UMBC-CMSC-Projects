"""
File: hw3_part4.py
Author: Sumaa Sayed
Date: 2/14/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take input from a user and print out a multiplication table.
"""

if __name__ == "__main__":
    
    # asking the user how many elements they want, and setting an empty list 
    num_elements = int(input('How many elements do you want in your table? '))
    num_list = []

    # for the number of elements the user inputs, the program will ask for numbers to be used for the table
    for i in range(num_elements):        
        number = float(input('Enter a number: '))
        num_list.append(number)

    # for the values in the list, they'll be multiplied together and then printied out in a table format    
    for i in num_list:
        for j in num_list:
            value = i * j
            print(value, end="  ")
        print()
        
