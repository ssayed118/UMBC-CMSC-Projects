"""
File: hw4_part5.py
Author: Sumaa Sayed
Date: 2/24/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to open a file, take the first word from each line, and then print it using a separator.
"""

if __name__ == "__main__":
    # opening the file
    use_file = input('Enter the file name to read: ')
    use_file = open(use_file, "r")
    list_word = use_file.readlines()

    #asking for separator
    input_sep = input('Tell me what separator you want to use: ')

    # getting the first word from each line and adding it to a list
    first_list = []
    for line in list_word:
        first_word = line.split()
        word_1 = first_word[0]
        first_list.append(word_1)

        #joining the words using the separator
        var = input_sep.join(first_list)       
    print(var)
