"""
File:    scramble.py
Author:  Sumaa Sayed
Date:    11/20/2019
Section: 16
E-mail:  ssayed1@umbc.edu
Description:
  DESCRIPTION OF WHAT THE PROGRAM DOES
"""
def permute(current_scramble, letters_left):
    """
    Prints all the possible permutations of the characters in a string
    :param current_scramble: The scrambled word thus far
    :param letters_left: The letters left to be scrambled
    :return: None (the word is printed, not returned)
    """
    # BASE CASE: 
    if len(letters_left) == 0:
        print(current_scramble)  

    # RECURSIVE CASE:
    else:
        for i in range(len(letters_left)):
            letter = letters_left[i]
          #  remove_letter = letters_left[i].remove
            # create a copy of the string without that letter
            # (this code removes the FIRST instance of the letter)
            # (for example: if string was "2010", now it's "210")
            new_letters_left = letters_left[:i] + letters_left[i + 1:]

            # add the letter we removed from letters_left
          #  letters_left = remove_letter[i].append
            # to the current scrambled word, call it new_scramble
            new_scramble = current_scramble + letter   # <----- UPDATE this 0 to something better

            # RECURSIVE CALL: use the new variables for this call
            permute(new_scramble, new_letters_left)


if __name__ == '__main__':
    print("Welcome to the Scrambler!")
    word = input("Please enter a string to scramble: ")

    # call the recursive function here
    # permute() takes in current_scramble, letters_left
    permute("", word) 
    print("Thank you for using the Scrambler!\n")
