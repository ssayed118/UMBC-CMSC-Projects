"""
File: hw4_part4.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input various weights of mushrooms, and then will categorize them by their weight. 
"""
if __name__ == '__main__':
    # these lists (below) will store the users input of the weight
    list_weight = []
    large_mushroom = []
    small_mushroom = []
    medium_mushroom = []
    weight = input('Enter a mushroom weight, or STOP to end.: ')
    while weight != "STOP":
    # when the weight isn't STOP, the program will continue to loop and store the weights that are put in by the user
       if int(weight) == 0:
            print("Weights must be greater than zero!")
       if int(weight) > 1000:
       # when the weights are above 1000, the number will save in the large_mushroom list
            large_mushroom.append(weight)
            list_weight.append(weight)
       elif int(weight) <= 100:
       # when weight is less that 100, the number will save in small_mushroom
            small_mushroom.append(weight)
            list_weight.append(weight)
       else:
       # when the weight is between 100 and 1000, then the number will save in medium_mushroom
            medium_mushroom.append(weight)
            list_weight.append(weight)
       weight = input('Enter a mushroom weight, or STOP to end.: ')
    if weight == "STOP":
        # when the user types in "STOP", the program will print out the list of numbers, and categorize them by their weight
        print("The weights you entered were", list_weight)    
        print("There were", len(small_mushroom), "small mushrooms,", len(medium_mushroom), "medium and", len(large_mushroom), "larges.")
