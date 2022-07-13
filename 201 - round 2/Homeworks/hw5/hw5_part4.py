"""
File: hw5_part4.py
Author: Sumaa Sayed
Date: 3/6/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to input numbers and then either print of the list of numbers in order, or just quit the program.
"""

if __name__ == "__main__":
    
#asking the user for input, setting a list, and setting a while loop so the user can quit the program
    input_1 = input('Add an item, print, or quit? ')
    my_list = []
    while input_1 != "quit":

        #if input is add then the program will ask for a number and append it 
        if input_1 == "add":
            number = int(input('Your number please? '))
            my_list.append(number)

            #sorting the list
            for i in range(1, len(my_list)):
                temp = my_list[i]
                j = i - 1
                flag = False
                while j >= 0 and flag != True:
                    if temp < my_list[j]:
                        my_list[j + 1] = my_list[j]
                        my_list[j] = temp
                        j -= 1

                    if my_list[j] < temp:
                        flag = True

            input_1 = input('Add an item, print, or quit? ')

        # if the input is print then the program will print the list
        if input_1 == "print":
            print(my_list)
            input_1 = input('Add an item, print, or quit? ')

# code in case that last if in the "add" section doesn't work..:
#my_list[j] = my_list[j + 1]                            
#my_list[j + 1] = temp                                  
#i -= 1                                                 
#   index = i                                          
#  my_list = my_list[:i] + [number] + my_list[i:]
