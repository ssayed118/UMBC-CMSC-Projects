"""
File: vowel_partition.py
Author: Sumaa Sayed
Section: 16
Date: 5/16/20
Email: ssayed1@umbc.edu
Description: This program will count vowel blocks in the_string.
"""

def count_blocks(the_string):
    """
    This function will count the vowel blocks in the_string.
    :param the_string: string used to count vowel blocks
    """
    #making the_string lowercase + list for vowels
    the_string = the_string.lower()
    vowels = ["a", "e", "i", "o", "u"]

    #setting counter and a variable for the length of the_string
    vow_count = 0
    letter_index = 0
    length = len(the_string)

    #while the counter for the string is less than length
    while letter_index < length:
        if the_string[letter_index] in vowels:
            
            #adding 1 to the vowel count when there's a vowel
            vow_count += 1
            letter_index += 1

#while there's vowels next to the spot, 1 will jsut be added to letter_index
            while letter_index < length and the_string[letter_index] in vowels:
                letter_index += 1
                
        else:
            letter_index += 1

    return vow_count

#potential code i was trying out...:
#    for i in range(len(the_string)):
 #       if the_string[i] in vowels:
  #          if the_string[i - 1] in vowels:
   #             count += 1

if __name__ == "__main__":
    the_string = input('enter string: ')
    print(count_blocks(the_string))
