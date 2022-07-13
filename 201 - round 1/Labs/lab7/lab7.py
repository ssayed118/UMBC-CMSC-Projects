"""
File:         names.py
Author:       Sumaa Sayed
Date:         10/22/2019
Section:      16
E-mail:       ssayed1@umbc.edu
Description:  YOUR DESCRIPTION GOES HERE AND HERE
              YOUR DESCRIPTION CONTINUED SOME MORE
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
    length_list = []
    for string in strings:
        length_list.append(len(string))
    return length_list

def get_names():
    """
    Asks the user for a list of names
    :return: a list of strings for the names the user entered
    """
    name_list = input('Enter a name, STOP to stop: ')
    list_names = []
    while name_list != "STOP":
        list_names.append(name_list)
        name_list = input('Enter a name, STOP to stop: ')

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
    print("There are", sum_list(get_string_lengths(kitties)), "letters in kitties.")
    
    puppers = [
        "Charlie",
        "Chuck",
        "Chuckadero",
        "Char",
        "Charmander",
        "Charles, Lord of Hearts, King of Snuggles"
    ]
    print("There are", sum_list(get_string_lengths(puppers)), "letters in puppers.")

    print("There are", sum_list(get_string_lengths(get_names())), "lettters in all the names.")

