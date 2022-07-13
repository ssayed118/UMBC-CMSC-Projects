"""
File: hw3_part4.py
Author: Sumaa Sayed
Date: 9/27/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program takes a list of animals and clothing, that was entered in by the user, and puts the two items into a sentence.
"""
if __name__ == '__main__':
    # for this section, each animal is inputted separately by the user
    animal_1 = input('Enter an animal: ')
    print("What is the first animal?", animal_1)
    animal_2 = input('Enter an animal: ')
    print("What is the second animal?", animal_2)
    animal_3 = input('Enter an animal: ')
    print("What is the third animal?", animal_3)

    # the animal inputted are placed into a list
    animals_list = [animal_1, animal_2, animal_3]

    # this is where the user inputs the clothing items
    clothing_1 = input('Enter an item of clothing: ')
    print("What is the first piece of clothing?", clothing_1)
    clothing_2 = input('Enter an item of clothing: ')
    print("What is the second piece of clothing?", clothing_2)
    clothing_3 = input('Enter an item of clothing: ')
    print("What is the third piece of clothing?", clothing_3)

    # the items are placed into a list
    clothing_list = [clothing_1, clothing_2, clothing_3]
    
# for every animal and clothing in the lists, a statement is printed, combining the two
    for animal in animals_list:
        for clothing in clothing_list:
            print(animal, "is wearing a", clothing, "-- crazy!")