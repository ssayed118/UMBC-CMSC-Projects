"""
File: initialize_names.py
Author: Sumaa Sayed
Date: 5/14/2020
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a name, and print out the initials.
"""

def get_initials(the_name):
    """
    This function will take in a name, and return the intials.
    :param the_name: a string that will be used to get initials
    """
    #setting an empty string to grab the initials
    temp = ""
    the_name = the_name.split()

    #appending the first letter
    for word in the_name:
        temp = temp + word[0]

    print("" + "." .join(temp).upper() + ".")

if __name__ == "__main__":
    #the_name = input('Enter a name: ')
    #var = get_initials(the_name)
