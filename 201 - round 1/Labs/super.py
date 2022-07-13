"""
File: super.py
Author: Sumaa Sayed
Date: 9/18/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input if they are a villain or a hero, and will respond based off of the first input.
"""
if __name__ == '__main__':
    v_o_h = str(input('Enter villain or hero: ')) 
    if v_o_h == "villain":
        name = str(input('Enter your name: '))
        print(name, "sounds pretty evil!")
    elif v_o_h == "hero":
           num_saved = int(input('Enter how many people you have saved: '))
           if num_saved <= 10:
               print("Go on more patrols!")
           elif num_saved > 10 and num_saved < 100:
               print("Sounds like you're making a difference!")
           elif num_saved > 100:
               print("Wow, great job saving the city!")
