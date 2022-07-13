"""
File: hw2_part2.py
Author: Sumaa Sayed
Date: 9/18/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input a number, choose a function, then the program will complete the function and display the answer, similar to a calculator.
"""

if __name__ == '__main__':
    # asks the user to input a number and will allow the user to pick whether they would like to find if the number is even, square the number or multiply the number by another number
    integer_1 = float(input('Enter an integer: '))
    print("Would you like to know if this number is even, square it, or multiply it with another number?")
    answer = str(input('Enter your answer: '))

    # will sqaure the number that the user entered
    if answer == "square":
        print("The square of this number is:", integer_1**2)

    elif answer == "even":
        # will figure out if the number is even or odd
        if integer_1 % 2 == 0:
            print("It is even!")
        else:
            print("It is odd!")

    elif answer == "multiply":
        # asks the user to input a number to be multiplied with the original number they entered
        o_num = float(input('Enter a number to be multiplied with the original number: '))
        print("What is the other number?", o_num)
        print(integer_1, "times", o_num, "is", (integer_1)*(o_num))
        
        # if the user inputs something other than a number, they will get a response
    else:
            print("I don't know what you're talking about.")