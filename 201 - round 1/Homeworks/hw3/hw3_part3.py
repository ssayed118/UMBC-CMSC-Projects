"""
File: hw3_part3.py
Author: Sumaa Sayed
Date: 9/27/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows the user to input five names, and then asks the user to input three names again, and then responds based off of their input.
"""

if __name__ == '__main__':
    # each variable below is for the first five people that the user inputs
    first_p = input('Enter the name of the first person: ')
    print("Who is the first person?", first_p)
    second_p = input('Enter the name of the second person: ')
    print("Who is the second person?", second_p)
    third_p = input('Enter the name of the third person: ')
    print("Who is the third person?", third_p)
    fourth_p = input('Enter the name of the fourth person: ')
    print("Who is the fourth person?", fourth_p)
    fifth_p = input('Enter the name of the fifth person : ')
    print("Who is the fifth person?" , fifth_p)

    # list of all five names
    people_list = [first_p, second_p, third_p, fourth_p, fifth_p]

    # part of the program where the user has to input three names
    candy = input('Enter the person who you would give your last piece of candy to: ')
    print("Which of these people would you give your last piece of candy?", candy)
    road_trip = input('Enter the person who you would go on a 12 hour road trip with: ')
    print("With which of these people would you go on a 12 hour road trip?", road_trip)
    tennis_yacht = input('Enter the name of the person who you would play tennis with on a yacht: ')
    print("With which of these people would you play tennis on a yacht?", tennis_yacht)

    # if the user inputs a name that isn't from the original list then a message should print 
    for people in people_list:
        if people not in people_list:
            print("Hey, I don't know who that is! That's cheating!")

    list_activity = [candy, road_trip, tennis_yacht]
# if a name was in the original list but didn't make it to the next list, the program should respond accordingly
    for person in people_list:
        if person not in list_activity:
            print("I feel bad for these people: ", person)  