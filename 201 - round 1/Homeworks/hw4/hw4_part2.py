"""
File: hw4_part2.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will divide two numbers, using a while loop and subtraction.
"""
if __name__ == '__main__':
    first_number = int(input('Please enter the first number: '))
    first_number_1 = first_number
    # the first number, aka the number that's being divided by (dividend)
    second_number = int(input('Please enter the second number: '))
    # second number, the divisor
    answer = 0
    
    while int(first_number) - int(second_number) >= 0:
        first_number -= second_number
        answer += 1
        
        if first_number == 0:   
            print(first_number_1, '//', second_number, "=", answer)

        
