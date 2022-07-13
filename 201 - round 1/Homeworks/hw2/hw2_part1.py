"""
File: hw2_part1.py
Author: Sumaa Sayed
Date: 9/18/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input the type of fish they would like, and based off of that response, the program will respond accordingly. 
"""

if __name__ == '__main__':
    # asks what type of fish the user wants and provide a response based on the answers to the questions
    type_of_fish = str(input('Enter the type of fish you want: '))

    if type_of_fish == "carnivorous":
        print("Do you have smaller fish already?")
        # asks if the user already has smaller fish and provides a response based on the answer
        ans_one = str(input('Enter your answer: '))
        if ans_one == "no":
            print("Great! Enjoy!")
        elif ans_one == "yes":
            print("This is a bad idea! It'll eat your little ones!")

    elif type_of_fish == "salt water":
        print("Wow, you're a fancy fish parent!")
        
    elif type_of_fish  == "community":
        print("How many fish of that type do you alrady own?")
        # asks the user the number of fish they already own
        ans_two = input('Enter the amount you already own: ')
        if ans_two < "3":
            print("You should get more than one!")
        elif ans_two > "3":
            print("Yay, more friends!")
    else:
        print("I don't think that's a type of fish. Maybe you're looking for a lizard?")
