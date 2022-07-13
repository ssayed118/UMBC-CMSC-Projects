"""
File: hw6_part3.py
Author: Sumaa Sayed
Date: 4/10/20
Section: 16
Description: This program will take in a stirng and replace some charcaters with greek letters.
"""

def replace_characters(the_string):
    """
    This function will replace specifc letter in the string.
    :param the_string: the string that will be changed
    """
    
    #using an empty string to grab the right letters
    e_str = " "
    i = 0

    #looping through the_string to replace the characters
    while i < len(the_string):

        #if the string has "ph" in it, then it'll change to phi
#the i <= len(string)-2 is to make sure the program doesn't go past the length 
        if i <= len(the_string) - 2 and the_string[i] == "p" and the_string[i + 1] == "h":
            e_str += '\u03d5'
            i += 2

        #if the string has "th" in it, change to theta
        if i <= len(the_string) - 2 and the_string[i] == "t" and the_string[i + 1] == "h":
            e_str += '\u03b8'
            i += 2

        #if it has "ch" in it
        if i <= len(the_string) - 2 and the_string[i] == "c" and the_string[i + 1] == "h":
            e_str += '\u03c7'
            i += 2

        #if it doesn't have those specific parings then keep the letter
        else:
            e_str += the_string[i]
            i += 1
    
    return e_str

if __name__ == "__main__":
    
    #asking for the string and printing the replaced version out
    the_string = input('What string do you want to process? ')
    the_string = the_string.lower()
    print(replace_characters(the_string))

#sometimes my code would work, and sometimes it wouldn't so in case it stops working, try taking out the "i <= len(the_string) -2, bc that was something i added last minute and it worked better, but my code also worked without it... not sure why
