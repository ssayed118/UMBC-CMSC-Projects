"""
1;95;0cFile: hw4_part3.py
Author: Sumaa Sayed
Date: 10/4/2019
Section: 16
Email: ssayed1@gl.umbc.edu
Description: This program will allow the user to input a type of design they want, their height, and when they need the design. The program will then print out a string at the end with all of the information that was put in.
"""
if __name__ == '__main__':
    # greeting the user
    print("Hello!")
    # asking for the type of desgin
    design = input('What kind of design are you looking for? Valid options are classy, playful, or business: ')
    # if the design is invalid, the program will tell the user
    while design != "classy" and design != "playful" and design != "business":
        print(design, "is not a valid style.")
        # the program will ask the user again (if they put soemthing that was invalid)
        design = input('What kind of design are you looking for? Valid options are classy, playful, or business: ')
    # asking fot the height
    height = input('What is your height in inches?: ')
    while float(height) == 0:
        print("Height must be greater than 0.")
        height = input('What is your height in inches?: ')
    # asking for the day the user needs the design
    due_date = input('How many days from now do you need the design? (Our minimum wait time is one week): ')
    while float(due_date) < 7:
        print("Sorry, we need at least a week for the design.")
        due_date = input('Please enter how many days from now do you need the design.: ')
        # the print statement with all of the information that was put in
    print("Great! We will get to work on a", design, "for a", height, "inch tall human. It will be ready in", due_date, "days or less.")
                
