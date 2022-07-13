"""
File: hw3_part2.py
Author: Sumaa Sayed
Date: 2/14/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will open a file, and calculate the expected value.
"""
if __name__ == "__main__":

    #opening the file
    v_p_file = input('What is the value_probability file? ')
    use_file =  open(v_p_file, "r")
    read_file = use_file.readlines()

    #setting a value to run through each pair of values in the file
    expectation = 0
    
    for line in read_file:
        #splitting the file into 2d lists to multiply and add each pair of values
        val_list = line.split()
        multiply = float(val_list[0]) * float(val_list[1])
        expectation += multiply
        
    print("The expected value is ", expectation)
