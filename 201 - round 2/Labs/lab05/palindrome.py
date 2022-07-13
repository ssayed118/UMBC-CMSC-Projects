"""
File: palindrome.py
Author: Sumaa Sayed
Date: 3/9/20
Section: 16
Email: ssayed1@umbc.edu
Description: 
"""

if __name__ == "__main__":
    enter_str = str(input('Enter a string: '))
    reverse_str = ""
    altered_str = "".join(enter_str.split()).lower()
    var = altered_str

    i = len(var) - 1
    
    while i  >= 0:
#    for i in range(1, len(altered_str) + 1):
        reverse_str = reverse_str + var[i]
        i = i - 1

    if altered_str == reverse_str:
        print(altered_str, "is a palindrome")
        
    else:
        print(altered_str, "is not a palindrome")
