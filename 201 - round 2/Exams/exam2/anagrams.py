"""
File: anagrams.py
Author: Sumaa Sayed
Date: 4/16/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will check 2 strings and return if they are anagrams.
"""

def anagram_buggy(first_word, second_word):
    """
    This function will check 2 strings if they are anagrams.
    :param first_word: the first word entered
    :param second_word: the second word entered
    :return: True or False, if the pair is an anagram or not
    """
    
    first_word = first_word.lower()
    second_word = second_word.lower()
    #both of the words should be the same case so i made the 2nd one lowercase

    first_word_dict = {}
    second_word_dict = {}

    #added these 2 lines because it just simplifies the problem a little
    if len(first_word) != len(second_word):
        return False

    #setting up the counters, to account for repeated letters (added the 4 lines below)
    for letter in first_word:
        for letter in second_word:
            first_word_dict[letter] = 0
            second_word_dict[letter] = 0
    
    for letter in first_word:
        if letter in first_word_dict:
            first_word_dict[letter] += 1

    for letter in second_word:
#changed second_word_dict to second_word, bc it should looping through the word
        
        if letter in second_word_dict:
            second_word_dict[letter] += 1

    for letter in first_word_dict:
        if first_word_dict[letter] != second_word_dict[letter]:
            return False
        
    return True
if __name__ == "__main__":

#    first_word = input('enter a word: ')
 #   second_word = input('enter another word: ')
 #   print(anagram_buggy(first_word, second_word))
