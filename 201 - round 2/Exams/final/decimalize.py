"""
File: decimalize.py
Author: Sumaa Sayed
Date: 5/14/2020
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a binary number, and convert to decimal
"""

def binary_to_decimal(binary_number):
    """
    This function will take in a binary number and return the decimal integer.
    :param binary_number: 
    """
    
    #setting counters
    count = 0
    num = 1
    
    power = len(binary_number) - 1
    
    for i in range(power, - 1, - 1):
        
        #if the number is 1 then add to count
        if binary_number[i]  == "1":
            count += num

        #otherwise, multiply by 2
        num = num * 2
            
    return count

if __name__ == "__main__":
    print(binary_to_decimal('11001111'))
    #207
    print(binary_to_decimal('00000011'))
    #3
    print(binary_to_decimal('100000000011'))
    #2051
    print(binary_to_decimal('1'))
    #1
