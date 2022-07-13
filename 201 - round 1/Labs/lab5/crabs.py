"""
File: crabs.py
Author: Sumaa Sayed
Date: 10/9/2019
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input weights of crabs and then it will categorize them into light or heavy weight crabs.
"""

if __name__ == "__main__":
    light_weight = []
    heavy_weight = []
    crab_weights = []
    
    weight = int(input('Enter crab weight, (STOP to end): '))
    while weight != "STOP":
        crab_weights.append(float(weight))
        weight = input('Enter crab weight, (STOP to end): ')
        
        
    light_or_heavy = input('Do you want to keep light or heavy crabs?: ')
    while light_or_heavy != "light" and light_or_heavy != "heavy":
        print("You must enter light or heavy")
        light_or_heavy = input('Do you want to keep light or hevay crabs? :')
        
    determines = int(input('What weight determines whether a crab is light?: '))
    for i in range(len(crab_weights)):
        if light_or_heavy == "light":
            if crab_weights[i] < determines:
                light_weight.append(crab_weights[i])
            else:
                heavy_weight.append(crab_weights[i])
        elif light_or_heavy == "heavy":
            if crab_weights[i] > determines:
                heavy_weight.append(crab_weights[i])
            else:
                light_weight.append(crab_weights[i])
    if light_or_heavy == "light":
        print("You are keeping the crabs with weights", light_weight)
        print("You are not keeping the crabs with weights", heavy_weight)
    else:
        print("You are keeping the crab with weights", heavy_weight)
        print("You are not keeping the crab with weights", light_weight)
