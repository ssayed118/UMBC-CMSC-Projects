"""                                                                            
File: hw6_part1.py                                                             
Author: Sumaa Sayed
Date: 4/9/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will calculate Narayana's Baby Cows, using user input and recursion.
"""

def baby_cows(n):
    """                                                                        
    This function will calculate the number of cows.
    :param n: years that the cows will be made into
    """
    #base cases
    if n < 0:
        return 0

    elif n < 4:
        return 1

    #recursive case
    else:
        return (baby_cows(n - 1) + baby_cows(n - 3))
    
if __name__ == "__main__":

    #asking for the value of n & printing the value
    n = int(input('How many years should we make cows? '))
    print(baby_cows(n))
