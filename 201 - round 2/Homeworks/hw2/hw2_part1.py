"""
File: hw2_part1.py
Author: Sumaa Sayed
Date: 2/7/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program is a calculator that does 3 operations, using input from the user.
"""

if __name__ == "__main__":    
    # prompting the user to input values for x and y, and what operation 
    int_x = float(input('Enter x: '))
    int_y = float(input('Enter y: '))
    operation = input('Enter operation (plus, power, divide): ')

    # for each operation, the program will complete the operation and print out the answer
    if operation == "plus":
        answer_1 = (int_x + int_y)
        print("x plus y is", answer_1)

    elif operation == "power":
        answer_2 = int_x ** int_y
        print("x to the power of y is", answer_2)

    elif operation == "divide":
        if int_y > 0:
            answer_3 = int_x / int_y
            print("x divided by y is", answer_3)

        # if the user inputs 0 for the y value, then they will get the statement below
        else:
            print("Woah buddy, y was zero, so I won't do that.")
            
    #if the user inputs an operation that isn't one of the 3 mentioned above, then they get a message        
    else:
        print("I don't recognize that operation.")
