"""
File: super.py
Author: Sumaa Sayed
Date: 2/10/20
Section: 16
Email: ssayed1@umbc.edu
Description: 
"""

if __name__ == "__main__":
    hero_vill = input('Are you a hero or a villain? ')

    if hero_vill == "villain":
        name = input('What is your name? ')
        print(name, "sounds pretty evil!")

    elif hero_vill == "hero":
        saved = float(input('How many people have you saved? '))

        if saved <= 10:
            print("Go on more patrols!")
        elif saved > 10 and saved < 100:
            print("Sounds like you're making a difference!")
        elif saved >= 100:
            print("Wow, great job saving the city!")
