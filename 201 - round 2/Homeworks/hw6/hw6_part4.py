"""
File: hw6_part4.py
Author: Sumaa Sayed
Date: 4/10/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a lit of strings, and a number (n) and print out the strings in lists that have n amount of items.
"""

def ruby_conseq(the_list, n):
    """
    This function will take in a list of strings and separate them, based on n.
    :param the_list: thhe list of strings that the user inputs
    :param n: how many items should be in each list
    """
    #splitting the_list and setting an empty list to append to
    strings = the_list.split()
    my_list = []

    #for the items in the splitted(?) list, they'll be spliced based off of n
    for i in range(len(strings)):
        var = strings[i : i + n]
        if len(var) == n:
            my_list.append(var)
        
    return my_list
        
if __name__ == "__main__":
    
    #asking for the strings, and n, then printing the lists out
    the_list = input('Enter a list of strings separated by spaces: ')
    n = int(input('Enter n: '))    
    print(ruby_conseq(the_list, n))
