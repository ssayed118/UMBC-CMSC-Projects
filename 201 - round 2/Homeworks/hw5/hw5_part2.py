"""
File: hw5_part2.py
Author: Sumaa Sayed
Date: 3/6/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a note, and return the scale for that note.
"""

def get_scale(note):
    
    #this list is the pattern for each step in the scale
    pattern = [2, 2, 1, 2, 2, 2, 1]

    #setting a variable and finding the index of the note using a loop
    int_var = 0
    for i in range(len(the_notes)):
        if note == the_notes[i]:
            int_var = i
            
#printing the scale
    for j in pattern:
        print(the_notes[int_var], end=' ')    
        int_var = (int_var + j) % len(the_notes)
    print()
    
if __name__ == "__main__":
    
    # setting the list for the notes and getting the input
    the_notes = ['C', 'C#', 'D', 'D#', 'E', 'F', 'F#', 'G', 'G#', 'A', 'A#', 'B']
    note = input('What scale do you want or Q to quit? ')

    #input validation and qutting the program when the user enters Q
    while note != "Q":
        var = get_scale(note)
        note = input('What scale do you want or Q to quit? ')
        
    if note not in the_notes and note != "Q":
        print("That is not a note")
        note = input('What scale do you want or Q to quit? ')
        
