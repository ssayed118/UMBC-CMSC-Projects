"""
File: almost_palindrome.py
Author: Sumaa Sayed
Date: 4/17/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will search through a string and the number of errors, and return True or False.
"""

def almost_palindrome(the_string, num_errors):
    #setting a counter
    error = 0

    #base case    
    if len(the_string) <= 1:
        #if the counter is less than or equal to the num_errors, it's true
        if error >= num_errors:
            return False

        #else, it's false
        else:
            return True
        
    #recursive case
    else:
        #shrinking the_string until it reaches the base case
        if the_string[0] == the_string[-1]:
            return almost_palindrome(the_string[1: -1], num_errors)

        else:
            #adding 1 to the counter 
            error += 1
            return almost_palindrome(the_string[1: -1], num_errors)


if __name__ == "__main__":
    
# the_string = str(input('Enter a string: '))
 #the_string = "".join(the_string.split()).lower()   
  #  num_errors = int(input('guess how many errors: '))
    #print(almost_palindrome(the_string, num_errors))

