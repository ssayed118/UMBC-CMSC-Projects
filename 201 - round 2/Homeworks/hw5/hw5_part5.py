"""
File: hw5_part5.py
Author: Sumaa Sayed
Date: 3/6/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a file, and say if each item in the file is a palindrome.
"""

def check_palindrome(word):
    
    #function to check each string to see if its a palindrome
    enter_str = word
    reverse = ""
    altered_str = reverse.join(enter_str).lower()
    
    for i in range(1, len(altered_str) + 1):
        reverse += altered_str[len(altered_str) - i]
        
    if altered_str == reverse:
        print(altered_str, "is a palindrome")
    
    else:
        print(altered_str, "is not a palindrome")
    
def load_words():
    #opening + reading the file
    use_file = input('What file should we check for palindromes? ')
    use_file = open(use_file, "r")
    palindrome_list = use_file.readlines()

    # for items in the list/file, taking them and stripping out the \n
    for j in range(len(palindrome_list)):
        palindrome_list[j] = palindrome_list[j].strip('\n')

    #returning the list to use in the other function
    return palindrome_list
    
if __name__ == "__main__":

    #function to open the file and output strings
    var = load_words()

#for each word in the list, running them through the check_palindrome function
    for word in var:
        var_2 = check_palindrome(word)
