"""
File: color_sort.py
Author: Sumaa Sayed
Date: 5/15/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a list and sort it based off of number, then color.
"""

def color_sort(the_list):
    """
    This function will sort the list.
    :param the_list: list that will be sorted
    """
    
    #list of colors, highest to lowest
    colors = ["gold", "red", "blue", "green"]

    #bubble sort (slighlty modified because we're dealing with tuples here)
    for i in range(len(the_list)):
        for j in range(len(the_list) - 1):
            if the_list[j] > the_list[j + 1]:
                temp = the_list[j]
                the_list[j] = the_list[j+1]
                the_list[j+1] = temp

    #counters for while loop
    count = 0
    color_count = 0
    
    #sorting by color (if 2 tuples have the same number, but different colors)
    for z in range(len(the_list) - 1):
        if the_list[z][0] == the_list[z+1][0]:
            count += 1
        
        #getting the program to run as long as the colors haven't been sorted
            if the_list[z][1] != the_list[z+1][1]:
                if colors.index(the_list[z][1]) > colors.index(the_list[z+1][1]):
                    while count != color_count:
                        temp = the_list[z]
                        the_list[z] = the_list[z+1]
                        the_list[z+1] = temp
                        color_count += 1
                    
    return the_list

if __name__ == "__main__":
    the_list = [(3, 'red'), (2, 'blue'), (2, 'gold'), (5, 'green'), (17, 'blue')]
    print(color_sort(the_list))

    the_list = [(27, 'red'), (10, 'red'), (21, 'red'), (46, 'red'), (13, 'red')]
    print(color_sort(the_list))

    the_list =  [(17, 'green'), (18, 'red'), (18, 'blue'), (28, 'gold')]
    print(color_sort(the_list))
