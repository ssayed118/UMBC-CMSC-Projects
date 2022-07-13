"""                                                                            
File:    hw6_part3.py                                                          
Author:  Sumaa Sayed                                                           
Date:    11/10/2019                                                            
Section: 16                                                                    
E-mail:  ssayed1@umbc.edu                                                      
Description: This program allows the user in input a string, and then hidden message inside the original string, and then it replaces the hidden messge with a new message.
"""
def replace_hidden_message(encrypted_message, hidden_message, new_hidden_message):
    """
    Replaces the hidden_message hidden in input_string with new_hidden_message
    :param encrypted_message: a message with something hidden in it
    :param hidden_message: the old hidden message
    :param new_hidden_message: the new hidden message that will replace it
    :return: encrypted_message where the first occurrence of hidden_message is replaced with new_hidden_message
    """
    # if the lenghts of the hidden and new hidden messages aren't the same then the user will get an error message
    if len(hidden_message) != len(new_hidden_message):
        print("The new message must be the same length. Good day.")
        return ""

    # if any of the inputs lengths are 0, then the user will get an error messsage
    if len(encrypted_message) == 0 or len(hidden_message) == 0 or len(new_hidden_message) == 0:
        return encrypted_message

    # if the index of encrypted message matches the hidden message, then all 3 inputs get spliced and the new message if printed
    if encrypted_message[0] == hidden_message[0]:
        return new_hidden_message[0] + replace_hidden_message(encrypted_message[1:], hidden_message[1:], new_hidden_message[1:])

    # for other conditions, the program will try to match the index/characters to print out the new message
    else:
        return encrypted_message[0] + replace_hidden_message(encrypted_message[1:], hidden_message, new_hidden_message)
    
if __name__ == "__main__":
    # asking the user for the 3 different inputs
    encrypted_message = str(input('Give me a string with a hidden message: '))
    hidden_message = str(input('Give me the hidden message: '))          
    new_hidden_message = str(input('What do you want the new hidden message to be? '))

    #calling the function to print the message
    print(replace_hidden_message(encrypted_message, hidden_message, new_hidden_message))
    
