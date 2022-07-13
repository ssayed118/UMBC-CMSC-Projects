"""                                                                            
File:    hw6_part2.py                                                          
Author:  Sumaa Sayed                                                           
Date:    11/10/2019                                                            
Section: 16                                                                    
E-mail:  ssayed1@umbc.edu                                                     
Description: This program will allow the user to input 2 sets of words, and then will recursively mix/weave them.                                             """

def zip_lists(words, words_2):
    """
    Creates a new list that alternates the values in list one and two.  The
    two lists must be of the same length.
    :param list_one: a list of values
    :param list_two: a list of values
    :return: a new list where list_one and list_two values alternate
    """
    # list for the 2 sets of inputs/lists
    switch_list = []
    
    # if no words are inputted, then return an empty list
    if len(words) == 0 and len(words_2) == 0:
        return []

    # for any other condition, the words will append to a list 
    else:
        switch_list = [words[0], words_2[0]]
        switch_list.extend(zip_lists(words[1:], words_2[1:]))
        return switch_list

if __name__ == "__main__":
    # staring with empty lists and asking for inputs
    words = []
    words_2 = []
    a = 0
    word_input = input('Enter words, STOP to stop.: ')

    # if the input is not STOP then the program will continue to add the words to a list (and ask for input)
    while word_input != "STOP":
        words.append(word_input)
        a += 1
        word_input = input('Enter words, STOP to stop.: ')

    # once the user types STOP then the program will move onto the second list of words    
    if word_input == "STOP":
        print("OK. Now enter", a, "other words")

        # the second time the program asks for inputs, it will ask for the lenght of the prevoius lists' inputs (hopefully this makes sense)
        for i in range(a):
            print("word" + str(i)+": ", end="")
            word2_input = input(" ")
            words_2.append(word2_input)
            
    # prints the lists, weaved together
    print(zip_lists(words, words_2))
