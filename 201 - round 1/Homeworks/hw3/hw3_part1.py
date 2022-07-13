"""
File: hw3_part1.py
Author: Sumaa Sayed
Date: 9/27/19
Section: 16
Email: ssayed1@umbc.edu
Descritpion: This program welcomes the user to a cheese shop, asks if they like cheese, and responds accordingly.
"""

if __name__ == '__main__':
    print("Hi! Welcome to The Deceased Macaw!")
    # the items in the lists are possoble responses to questions that the program will ask
    # pos_inputs means positive inputs like yes
    pos_inputs = ["yes", "Yes"]
    # neg_inputs means negative inputs like no
    neg_inputs = ["no", "No"]

# first question that the user will be asked
    cheese = input('Enter if you like cheese: ')
    print("Do you like cheese?", cheese)

    if cheese == neg_inputs[0] or cheese == neg_inputs[1]:
        # if the user does not like cheese, they will be given a response
        print("Well I don't know what you're doing in a cheese shop then.")

    elif cheese == pos_inputs[0] or cheese == pos_inputs[1]:
        #if the user likes cheese, they will be asked another question
        cheddar = input('Enter if you are okay with cheddar: ')
        print("Is cheddar okay?", cheddar)
        if cheddar == pos_inputs[0] or cheddar == pos_inputs[1]:
            print("Very well, here you are.")
        elif cheddar == neg_inputs[0] or cheddar == neg_inputs[1]:
            print("Oh, then I suppose we will locate another reasonably cheesy comestible.")
            
  # if the user inputs anything besides the items defined in the lists abovs, they will be given this response      
        else:
            print("I don't know what you're talking about.")
    else:
        print("I don't know what you're talking about.")