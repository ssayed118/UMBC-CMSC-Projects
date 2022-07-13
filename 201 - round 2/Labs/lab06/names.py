"""
File:         names.py
Author:       Sumaa Sayed
Date:         3/23/2020
Section:      16
E-mail:       ssayed1@umbc.edu
Description:  This program will take in a list of names and then print the number of  letters in the list of names.
"""

def sum_list(numbers):
    """
    Sums a list of integers
    :param numbers: a list of integers
    :return: the sum of the integers in numbers
    """
    total_num = 0
    for number in numbers:
        total_num += number
    return total_num

def get_string_lengths(strings):
    """
    Given a list of strings, return a list of integers representing
    the lengths of the input strings
    :param strings: a list of strings
    :return: a list of integers representing the lengths of the input strings
    """
    my_list = []
    for string in strings:
        my_list.append(len(string))
    return my_list

def get_names():
    """
    Asks the user for a list of names
    :return: a list of strings for the names the user entered
    """
    names_int = input('Enter a name, STOP to stop: ')
    list_names = []
    while names_int != "STOP":
        list_names.append(names_int)
        names_int = input('Enter a name, STOP to stop: ')

    return list_names
        
if __name__ == '__main__':
    kitties = [
        "Jules",
        "Stubby",
        "Tybalt",
        "Scooter",
        "KC",
        "Garfield",
        "Bucky"
    ]

    # print the sum of the lengths of the strings in kitties
    print("There are", sum_list(get_string_lengths(kitties)), "letters in kitties.")

    puppers = [
        "Charlie",
        "Chuck",
        "Chuckadero",
        "Char",
        "Charmander",
        "Charles, Lord of Hearts, King of Snuggles"
    ]
    
    # prints the sum of the lengths of the strings in puppers
    print("There are", sum_list(get_string_lengths(puppers)), "letters in puppers.")

    # gets names from the user and reports how many letters are in all the names
    print("There are", sum_list(get_string_lengths(get_names())), "lettters in all the names.")
