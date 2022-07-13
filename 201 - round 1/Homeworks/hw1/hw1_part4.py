"""
File: hw1_part4.py
Author: Sumaa Sayed
Date: 9/13/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows for the user to enter the amount of money they spend on airplane related things, annually. 
"""

if __name__ == '__main__':
    annual_inspections = float(input('Enter the amount of annual inspections: '))
    cost_of_fuel = float(input('Enter the cost of fuel: '))
    cost_of_hangar_fees = float(input('Enter the cost of hangar fees: '))
    cost_of_propeller_fluid = float(input('Enter the cost of propellar fluid: '))
    total_cost = annual_inspections + cost_of_fuel + cost_of_hangar_fees + cost_of_propeller_fluid
    
    print("What was the cost of the annual inspections?", annual_inspections)
    print("What was the cost of the fuel?", cost_of_fuel)
    print("What was the cost of the hangar fees?", cost_of_hangar_fees)
    print("What was the cost of the propellat fluid?", cost_of_propeller_fluid)
    print("The total annual cost of the aircraft is", total_cost)