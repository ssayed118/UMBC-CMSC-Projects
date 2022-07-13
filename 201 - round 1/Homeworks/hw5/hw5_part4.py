""" 
File: hw5_part4.py
Author: Sumaa Sayed
Date: 10/14/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program adds "ol" for every word that has a consonant that is not followed by another consonant.
"""

if __name__ == '__main__':
    # created a vowel list, with vowels
    vowel_list = ["a", "e", "i", "o", "u", "y"]
    # created a consonant list, with letters that aren't vowels
    consonant_list = ["b", "c", "d", "f", "g", "h", "j", "k", "l", "m", "n", "p", "q", "r", "s", "t", "v", "w", "x"]

    # asks the user to input a sentence
    sentence = set(input('Enter a sentence: '))
    strtext2 = " "

    # for loop that reads through the sentence and adds "ol" when necessary
    for character in sentence:
        if character in vowel_list:
            strtext2 = strtext2 + character
        elif character not in vowel_list:
            strtext2 = strtext2 + character + "ol"
    print(strtext2)
    # so this code doesn't work perfectly either, the user would have to input a lowecase sentence, and it'll print the letters out of order if that makes sense

# again, here's code that would either work or print funny... kinda just leaving it here incase i figure this question out some other time            
#for i in range(len(sentence)):
#if consonant_list:
#if i == len(sentence) - 1 or consonant_list(sentence[i+1]):
#for i in vowel_list:
#if str(consonant_list) in sentence:
#if str(consonant_list[i+1]):
#strtext2 = strtext2 + sentence + "ol"
#elif str(vowel_list):
#strtext2 = strtext2 + sentence
                
#and str(vowel_list[i+1]) in sentence:
#strtext2 = strtext2 + str(consonant_list)
            
