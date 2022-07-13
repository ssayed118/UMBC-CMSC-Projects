"""
File:    hw6_part1.py
Author:  Sumaa Sayed
Date:    11/10/2019
Section: 16
E-mail:  ssayed1@umbc.edu
Description: This program will allow the user to input any 2 positive integers, and then divide them recursively.
"""
def integer_division(input_1, input_2):
    # if the dividend, is smaller than the divisor then the answer will be 0
    if input_1 < input_2:
        return 0
    
    # for any other inputs, the program will subtract until input_1 is smaller than input_2
    else:
        input_1 -= input_2
        return integer_division(input_1, input_2) + 1 
    
if __name__ == "__main__":
    
    # asking for inputs
    input_1 = int(input('Enter a number: '))
    input_2 = int(input('Enter another number: '))

    #printing the answer, after dividing
    answer = integer_division(input_1, input_2)
    print(answer)
