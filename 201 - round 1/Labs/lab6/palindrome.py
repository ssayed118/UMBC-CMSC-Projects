""" 
File: palindrome.py
Author: Sumaa Sayed
Date: 10/16/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input a word and then program will tell the user if its a palindrome or not.
"""

if __name__ == '__main__':
    enter_str = input('Enter a string: ')
    reversed = ""
    altered_str = "".join(enter_str.split()).lower()
    
    for i in range(1,len(altered_str)+1):
       reversed += altered_str[len(altered_str)-i]
       
    if altered_str == reversed:
         print (altered_str, "is a palidrome")
    else:
         print(altered_str, "is not a palidrome")
        
        
