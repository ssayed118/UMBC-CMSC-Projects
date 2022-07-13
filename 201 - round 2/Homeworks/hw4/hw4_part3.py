"""
File: hw4_part3.py
Author: Sumaa Sayed
Date: 2/28/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to play a simple version of hangman.
"""

if __name__ == "__main__":

    #asking for the word, and removing and letters that show up multiple times
    word = input('Enter word: ')
    word_list = list(word.lower())
    for letter in word_list:
        if word_list.count(letter) > 1:
            word_list.remove(letter)

    # asking the user to guess a letter
    guesses = []
    while len(word_list) != 0:
        guess = input('Guess a letter: ')
        
        if guess in guesses:
            print(guess, "has already been guessed")

        if guess in word_list:
            word_list.remove(guess)

        if len(guess) > 1:
            print("You didn't guess a single letter")
            
        if guess not in word_list:
            guesses.append(guess)
            
    # once the user guesses all of the letters, then the program tells the user
    if len(word_list) == 0: 
        print("The word was", word)
