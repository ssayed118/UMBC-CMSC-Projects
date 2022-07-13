"""
File: hw3_part3.py
Author: Sumaa Sayed
Date: 2/14/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will allow the user to run the program x amount of times, to add, remove or find the max of the list of names. 
"""

if __name__ == "__main__":
    
    # asking the user how man times the program will run and setting an empty list for the names
    num_steps = int(input('How many steps should we run? '))
    name_list = []

    #for the amount of times the user puts for num_steps, the program will ask that many times for a command
    for i in range(num_steps):
        command = input('Enter command: ')

        # if add is in the command, then it removes "add" and just stores the name into the list
        if "add" in command:
            command_a = command[4:]
            name_list.append(command_a)
            print(command_a, "added.")

    # if remove is in the command, then it removes "remove" from the command
        elif "remove" in command:
            command_r = command[7:]

            # if the name isn't in the list then the program lets the user know
            if command_r not in name_list:
                print("That name is not in the list!")

            #otherwise, it just removes    
            else:   
                name_list.remove(command_r)
                print(command_r, "removed.")

        # if the user enters max then the program will look at the list and...
        elif command == "max":
            maximum = name_list[0]
            for i in name_list:
                # find the name with the most letters
                if len(i) > len(maximum):
                    maximum = i

                # or it will print out the name that was lat added to list, with the specific amount of letters (not sure if this is making any sense)    
                elif len(i) == len(maximum):
                    maximum = i
       
            print("The max name is", maximum)
                      
