"""
File: crabs.py
Author: Sumaa Sayed
Date: 3/2/20
Section: 16
Email: ssayed1@umbc.edu
Description: crab weights!
"""
if __name__ == "__main__":
    light_weight = []
    heavy_weight = []
    crab_weights = []

    weight = int(input('Enter crab weight, (STOP to end) '))
    while weight != "STOP":
        crab_weights.append(float(weight))
        weight = input('Enter crab weight, (STOP to end) ')

    light_heavy = input('Do you want to keep light or heavy crabs? ')
    while light_heavy != "light" and light_heavy != "heavy":
        print("You must enter light or heavy")
        light_heavy = input('Do you want to keep light or heavy crabs? ')
        
    determine = int(input('What weight determines whether a crab is light or heavy? '))

    for i in range(len(crab_weights)):
        if light_heavy == "light":
            if crab_weights[i] < determine:
                light_weight.append(crab_weights[i])
            else:
                heavy_weight.append(crab_weights[i])

        elif light_heavy == "heavy":
            if crab_weights[i] > determine:
                heavy_weight.append(crab_weights[i])
            else:
                light_weight.append(crab_weights[i])

    if light_heavy == "light":
        print("You are keeping the crabs with weights", light_weight)
        print("You are not keeping the crabs with weights", heavy_weight)

    else:
        print("You are keeping the crabs with weights", heavy_weight)
        print("You are not keeping the crabs with weights", light_weight)
