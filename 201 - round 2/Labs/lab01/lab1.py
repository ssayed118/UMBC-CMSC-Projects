"""
File: lab1.py
Author: Sumaa Sayed
Date: 2/3/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will convert Farenheit to celsius.
"""
if __name__ == "__main__":
    
    temp_faren = int(input('Enter a temperature in Farenheit: '))

    celsius = ((5/9) * (temp_faren - 32))

    print("The temperature", temp_faren, "in Celsius is:", celsius)
