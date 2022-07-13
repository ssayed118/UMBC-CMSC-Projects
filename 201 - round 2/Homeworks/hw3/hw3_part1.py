"""
File: hw3_part1.py
Author: Sumaa Sayed
Date: 2/14/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will read a file, and count how many words have the substrings "dom", "ship", and "hood" in them.
"""

if __name__ == "__main__":
    #opening the file
    use_file = input('What file do you want to count? ')
    use_file = open(use_file, "r")
    word_list = use_file.readlines()
    
    #counters for each string
    counter_d = 0
    counter_h = 0
    counter_s = 0

    #for every word in the list, add 1 for each time a substring is in it
    for word in word_list:
        
        if "dom" in word:
            counter_d += 1

        elif "hood" in word:
            counter_h += 1

        elif "ship" in word:
            counter_s += 1


    print("The number of -hood words is", counter_h)
    print("The number of -ship words is", counter_s)
    print("The number of -dom words is", counter_d)
