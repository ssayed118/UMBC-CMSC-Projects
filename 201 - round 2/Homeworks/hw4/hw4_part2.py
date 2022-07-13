"""
File: hw4_part2.py
Author: Sumaa Sayed
Date: 2/27/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in 2 integers, a and n, and find if there is an intger x so that a times x is 1 mod n.
"""

if __name__ == "__main__":
    #asking the user for integer a, and making sure it's postiive
    num_a = int(input('Enter a positive integer: '))
    while num_a <= 0:
        print(num_a, "wasn't a positive integer.")
        num_a = int(input('Enter a postive integer: '))

    if num_a > 0:
        #asking for n, and making sure its positive
        num_n = int(input('Enter a positive integer: '))
        while num_n <= 0:
            print(num_n, "wasn't positive")
            num_n = int(input('Enter a positive integer: '))
            
        if num_n > 0:
            flag = False
            num_x = 0
            while flag == False and num_x < num_n:
                
                #looping through the range to find the correct value for x
                equation = (num_a * num_x) % num_n
                if equation == 1:
                    flag = True
                    print(num_x, "times", num_a, "is 1 mod", num_n)
                num_x += 1
                
           #if there's no value found for x then the program lets the user know
            if not flag:
                print("Unable to find a multiplicative inverse for the pair", num_a, "&", num_n)
    
