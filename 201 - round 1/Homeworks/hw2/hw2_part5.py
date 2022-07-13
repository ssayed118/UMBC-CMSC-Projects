"""
File: hw2_part5.py
Name: Sumaa Sayed
Date: 9/20/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input if the plant they have eats bugs, and attempt to identify the plant based off of questions pertaining to plants, and information given. 
"""

if __name__ == '__main__':
    #asks the user if the plant they have eats bugs
    eat_bugs = str(input('Enter if your plant eats bugs: '))
    if eat_bugs == "yes":

        # if the plant eats bugs then the program will aks what it uses to eat the bugs 
        usage = str(input('Enter either pitfall trap or snap jaws: '))
        print("Does the plant use a pitfall trap or snap jaws?", usage)
        if usage == "pitfall trap":
            print("You have a Nepenthes!")
        elif usage == "snap jaws":
            print("You have a Dionaea muscipula!")

        # if the plant uses something else, then the program will respond accoridngly
        else:
            print("I don't know what that is..")

    # if the plant doesn't eat bugs then the program will continue to ask how mnay petal the plant has
    elif eat_bugs == "no":
        num_petals = int(input('How many petals does it have: '))
        if num_petals > 7:
            print("You probably have either an Asteraceae or a Helianthus annuus")

            # if the plant has more than 7 petals, the program will ask for the height of the plant
            height = int(input('Enter the height of your plant: '))
            if height > 300:
                print("You have a Helianthus annuus!")
            elif height <= 300:
                print("You have a Asteraceae!")
        elif num_petals == 3:
            print("You have an Iris!")
        elif num_petals == 5:
            print("You have an Orchidaceae!")
            
        else:
            print("I don't know what that is...")
    # if the user inputs something besides yes or no for if the plant eats bugs, then the program will respond         
    else:
        print("I don't know what that is...")