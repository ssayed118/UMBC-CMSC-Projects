"""
File: hw4_part5.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows a user to input a number that the program will count to, and print strings for specific conditions.
"""
if __name__ == '__main__':
    limit = int(input('What is the upper limit?: '))
    # asking the user, how faar they want the program to count/get to
    for i in range(1, limit):
        if i % 3 == 0 and i % 4 == 0:
        # for any number that's divisible by 3 and 4, the program will print out a string instead or the number
            print("This is a very special time, savor it.")
        elif i % 3 == 0:
        # for any number divisible by 3, the program will print a string
            print("One time I saw three hawks piled on a cactus.")
        elif i % 4 == 0:
        # for any number divisible by 4, the program will print a string
            print("Four? What is it good for? Absolutely nothing!")
        else:
        # for anything else, the program will just print the number
            print(i)
