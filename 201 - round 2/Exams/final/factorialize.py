"""
File: factorialize.py
Author: Sumaa Sayed
Date: 5/15/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will find the highest n! that divides a number.
"""

def dividing_factorial(num, current = 1):
    """
    This function will take in a number and find the highest n! that divides a     number.
    :param num: number that will be taken in, to get the highest n! for
    """

    #base case
    if current == num:
        return current

    #recursive case
    else:
        if current < num:
            if num % current == 0:
            
            #finding the n! that divdes n, and setting to a variable
                var = num // current
                num = var
                return dividing_factorial(num, current + 1)

            else:
                return current - 1
            
        #if current is bigger than num 
        else:
            return current - 1

if __name__ == "__main__":
    num = 0
    print(dividing_factorial(num, current = 1))
