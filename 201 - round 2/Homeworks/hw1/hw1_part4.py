"""                                                                           
File: hw1_part4.py                                                             
Author: Sumaa Sayed                                                            
Date: 2/2/20                                                                   
Section: 16                                                                    
Email: ssayed1@umbc.edu                                                        
Description: This program will allow the user to input five different words to create a mad-lib.           
"""

if __name__ == "__main__":

    #aksing the suer to input 3 nouns, a verb, and an adjective
    noun_1 = input('Give me a plural noun! ')
    verb = input('Give me a verb! ')
    adjective = input('Give me an adjective! ')
    noun_2 = input('Give me another noun! ')
    noun_3 = input('Give me a third plural noun! ')

    #printing out the mad-lib
    print(noun_1, "are bad at", verb + "ing", "in", adjective, noun_2 + ".", noun_3, "aren't.")
