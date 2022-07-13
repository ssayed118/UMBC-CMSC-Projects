"""
File: hw5_part2.py
Author: Sumaa Sayed
Date: 10/14/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input 2 different list of words and then weave the words, and print the new list.
"""

if __name__ == '__main__':
    # asks the user for words
    word = input('Enter words, STOP to stop.: ')
    words = []
    while word != "STOP":
        # adds those words to a list
        words.append(word)
        word = input('Enter words, STOP to stop.: ')

    # once the user inputs stop, the program will ask for more words
    if word == "STOP":
        print("OK. Now enter", len(words), "other words")

        word_2 = []
        for i in range(len(words)):
            word = input("word" + str(i)+ ": ")
            # asking for more words
            word_2.append(word)
            # adding them to the second list
            
        print("Now I will magically weave them!")
        # the two lists will be weaved but in reverse
        for i in range(len(words)):
            print(words[i])
            print(word_2[len(words) - i - 1])

