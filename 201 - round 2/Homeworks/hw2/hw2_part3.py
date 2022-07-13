""" 
File: hw2_part3.py
Author: Sumaa Sayed
Date: 2/8/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to answer question and receive a Star Wars character.
"""

if __name__ == "__main__":
    # asking if the character has legs or wheels
    leg_wheel = input('Do you have legs or wheels? ')

    #if the character has legs
    if leg_wheel == "legs":

        #fur
        fur = input('Do you have a lot of fur? ')
        if fur == "yes":
            print("You are Chewbacca!")
            
        elif fur == "no":
            
            # job
            job = input('What is your job? (moisture farmer, Princess of Alderaan, Sith Lord, smuggler) ')
            
            if job == "moisture farmer":
                print("You are Luke Skywalker!")
                
            elif job == "smuggler":
                
                # if they won the card game
                card_game = input('Did you win or lose the card game? (won, lost) ')
                if card_game == "won":
                    print("You are Han Solo!")
                    
                elif card_game == "lost":
                    print("You are Lando Calrissian!")
                    
                else:
                    print("I dunno, are you a gonk droid?")
                    
            elif job == "Sith Lord":
                force_power = input('What is your favorite force power? ')
                if force_power == "lightning":
                    print("You are Emperor Palpatine!")
                    
                else:
                    print("You are Darth Vader")
                    
            elif job == "Princess of Alderaan":
                print("You are Princess Leia")
                
            else:
                print("I dunno, are you a gonk droid?")
                    
        else:
            print("I dunno, are you a gonk droid?")
            
    # if the character has wheels        
    elif leg_wheel == "wheels":
        print("You are R2-D2")

    # if the user inputs anything else, then they get this message
    else:
        print("I dunno, are you a gonk droid?")
