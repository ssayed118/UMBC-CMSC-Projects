"""
File: hw1_part1.py
Author: Sumaa Sayed
Date: 2/2/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will print out statements, using pre-set variables.
"""

if __name__ == "__main__":

    #variables
    favorite_movie = "Inception"
    digits_of_pi = 3.1415926
    num_dogs = 0
    num_cats = 2
    num_other_pets = 0

    # this vairable adds up the total amount of pets 
    total_pets = num_dogs + num_cats + num_other_pets
    
    #print statements
    print("My favorite move is", favorite_movie)
    print("I know pi up to", digits_of_pi)
    print("I have", num_dogs, "dogs", num_cats, "cats and", num_other_pets, "other pets.")
    print("I have", total_pets, "total pets.")
