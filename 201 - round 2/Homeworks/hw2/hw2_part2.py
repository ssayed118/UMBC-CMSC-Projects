"""
File: hw2_part2.py
Author: Sumaa Sayed
Date: 2/8/20 
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to choose a number, and possibly gain access to Gnostic truths depending on the swithes they turn on.
"""

if __name__ == "__main__":
    #getting the user to choose a number
    number = int(input('What is the position of the knob? (Enter 1-6) '))

    #if the number is between 0 and 6, the program will continue to ask the user what swicthes they want to turn on and then reveal a truth
    if number > 0 and number < 6:

        #if the number is odd
        if number % 2 == 1:
            switch_a = input('Is switch-A on or off? (on/off) ')
            switch_b = input('Is switch-B on or off? (on/off) ')

            if switch_a == "off" or switch_b == "off":
                print("You have gained access to the secret Gnostic Truths, and have gained infinite enlightenment.")

            elif switch_a == "on" and switch_b == "on":
                print("You have gained access to the lesser answers, and you are deceived.")

            else:
                print("You have failed to access the deepest secrets of the universe, try again.")
                
        #if the number is even
        elif number % 2 == 0:
            switch_a = input('Is switch-A on or off? (on/off) ')
            switch_b = input('Is switch-B on or off? (on/off) ')
            print("You have failed to access the deepest secrets of the universe, try again.")
            
    #if the user picks a number that is not between 0 and 6, then they get an error message
    else:
        switch_a = input('Is switch-A on or off? (on/off) ')
        switch_b = input('Is switch-B on or off? (on/off) ')
        print("That is not a vaild knob position!")
        
    
