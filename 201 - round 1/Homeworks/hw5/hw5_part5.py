""" 
File: hw5_part5.py
Author: Sumaa Sayed
Date: 10/14/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program asks the user for the number of words they would like to reverse, and then ask the user that many times, then reverse the words.
"""

if __name__ == '__main__':
    # so this code doesn't work perfectly, and i don't think i wrote the loop correctly either so i'm just submitting what i have...

    # asking the user to input a number
    back_words = input('How many words would you like to turn backwards: ')

    #this chunk of code reverses the letters in the string
    def back_words(s):
        s1 = " "
        for c in s:
            s1 = c +s1
        return s1
    counter = 0

    # asking the user for words
    input_str = input('Please enter string #' +str(counter)+ ': ')
    
#for i in range(back_words) != "0":
#input_str = input('Please enter string #' +str(counter)+ ': ')
#  input_words = []
# input_words.append(input_str)
# ^this is code that kinda sorta would work but the letters wouldn't reverse, or it would print out really funky

    # for each word that was inputted by the user, the program will print out a sentence with the original word and the word reversed
    for word in input_str:
        input_str = input('Please enter string #' +str(counter)+ ': ')
        print("The string", word, "reversed is", back_words(input_str))
