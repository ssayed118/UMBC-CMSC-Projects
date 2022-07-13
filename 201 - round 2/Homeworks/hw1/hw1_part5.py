"""                                                                            
File: hw1_part5.py                                                             
Author: Sumaa Sayed                                                            
Date: 2/2/20                                                                   
Section: 16                                                                    
Email: ssayed1@umbc.edu                                                        
Description: This program will promt the user to input hot and cold temperatures to the calculate the efficiency of a Carnot cycle.           
"""

if __name__ == "__main__":

    # welcoming the user to the cycle calculator
    print("Welcome to the Carnot cycle efficiency calculator!")

    # prompting the user for the cold and hot temperatures
    cold_res_temp = float(input('Enter the cold side reservoir temperature! '))
    hot_res_temp = float(input('Enter the hot side reservoir temperature! '))

    # calculating the efficiency of the cycle, using a formula
    cycle_efficiency = 1 - (cold_res_temp / hot_res_temp)
    
    #printing out how efficient the cycle is                     
    print("The efficiency of your cycle is", cycle_efficiency)
