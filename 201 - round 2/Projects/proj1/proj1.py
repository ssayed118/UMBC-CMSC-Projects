"""
File: proj1.py
Author: Sumaa Sayed
Date: 3/23/2020                                            
Section: 16                                                                   
Email: ssayed1@umbc.edu                                                       
Description: This program will mimic the game Oregon Trail, but UMBC style.   
"""
def load_map(map_file_name):
    """                                                                        
    This function will take in the map file and return the map to be used for      the game.                                                                  
    :param map_file_name: map text file                                        
    """
    #key is location, value is time for map_2
    #opening the map text file and declaring 2 dictionaries
# ex: {The Dorms:{Public Policy :50, Physics Building :100, The Commons :120}}
    map_file = open(map_file_name, "r")
    map_var = map_file.readlines()
    map_1 = {}
    map_2 = {}
    place = map_var[0].strip()

    #for each line in the file, stripping + splitting, then adding to the correct dictionary
    for line in map_var:
        lines_1 = line.strip().split(",")

        #if the line just has a location then it becomes a key
        if len(lines_1) > 1:
            location = lines_1[0]
            time = lines_1[1]
            map_2[lines_1[0]] = time

        #if the line has something like Public Policy 50, then it gets added to the value for the key that the program is looking at 
        if len(lines_1) == 1:
            map_1[place] = map_2
            place = lines_1[0]
            map_2 = {}

    #it wouldn't add ITE at the end, so i've just added it here
    map_1["ITE"] = {}
    map_file.close()
    return map_1

def load_events(event_file_name):
    """                                                                        
    This function will take in the event file and return the events for the pro
    gram to use.                                                               
    :param event file name: event text file                                    
    """
    #opening the file
    event_file = open(event_file_name, "r")
    event_var = event_file.readlines()

    #creating a list for the contents of the file to be added to
    events_1 = []
    for line in event_var:
        lines_2 = line.strip().split(",")
        events_1.append(lines_2)

    #this file ends up becoming a 2d list, and each "list" has the info for each location
    event_file.close()
    return events_1

def play_game(start_time, game_map, events, points):
    """                                                                        
    This function will play the game.
    :param start_time: time the user chooses to start with
    :param game_map: map that is used to play the game                     
    :param events: list that stores each locations events and other things
    :param points: list with charisma and stealth points
    """
#setting the current location as dorms, and variables for charisma and stealth
    current_location = "The Dorms"
    charisma = points[0]
    stealth = points[1]

#while the user is not at ITE and still has time, the program will keep running
    while current_location != "ITE" and start_time > 0:        
        print("You are currently in", current_location, "and have", start_time, "seconds left to get to ITE.")

    #for each location in the map, the locations to move to, will be printed
        for place in game_map[current_location]:
            print("\t", place, game_map[current_location][place])

        #getting the next location and validating
        place_1 = input('Where do you wanna go next? ')
        while place_1 not in game_map[current_location]:
            place_1 = input('Where do you wanna go next? ')

#subtracting the time (from map file) from the starting time & setting the location
        start_time = start_time - int(game_map[current_location][place_1])
        current_location = place_1

        #for the places in the events (2d list)
        for i in range(len(events)):
            if current_location == events[i][0] or place_1 == events[i][0]:
                
                #setting a varibale so the loop stops at the correct index
                var_a = i
                print(events[var_a][1])

        #if the user has enough charisma & stealth, they move on w/o penalty
                if charisma >= int(events[var_a][4]) and stealth >= int(events[var_a][5]):
                    print(events[var_a][2])
                    
#if the user doesn't have enough charisma or stealth, they get a time penalty and can move on
                else:
                    start_time = start_time - int(events[var_a][6])
                    print(events[var_a][3])
                    print("You lose", int(events[var_a][6]), "seconds")
                    
    #once the user makes it to ITE with enough time, they win
    if (current_location == "ITE" and place_1 == "ITE") and start_time >= 0:
        print("You made it to ITE and now can learn the secrets of computer science.  You win!")

    #if the user does not make it to ITE and runs out of time, they lose
    else:
        print("You have run out of time, and so you lose.")
            
def create_character():
    """                                                                        
    This function will create the chracter that will be used to play the game. 
    """
    #asking for characters name, making sure it's at least 3 strings long      
    name = input('What is your name? Enter a first (middle) last separated by spaces, middle being optional. ')
    name_var = name.split()
    while len(name_var) > 3 or len(name_var) == 1:
        name = input('What is your name? Enter a first (middle) last separate by spaces, middle being optional. ')
        name_var = name.split()

    #getting the skill point values for charisma and stealth                
    print("You have 10 skill points to distribute, otherwise you aren't going anywhere.")
    charisma = int(input('How charismatic are you, you have 10 skill points left? '))
    var_1 = 10 - float(charisma)
    stealth = int(input("How sneaky are you, you have " + str(var_1) + " skill points left? "))
    var_2 = charisma + stealth

    #making sure the values entered are positive and add up to 10              
    while (charisma < 0 or stealth < 0) or var_2 != 10:
        print("You have 10 skill points to distribute, otherwise you aren't going anywhere.")
        charisma = int(input('How charismatic are you, you have 10 skill points left? '))
        var_1 = 10 - float(charisma)
        stealth = int(input("How sneaky are you, you have " + str(var_1) + " skill points left? "))
        var_2 = charisma + stealth
        
    points = [charisma, stealth]
    return points

if __name__ == "__main__":
    #getting the file for the map and storing it for play_game
    map_file_name = input('What is the map file? ')
    game_map = load_map(map_file_name)
    #print(game_map)

    #getting the file for the events and storing it for play_game
    event_file_name = input('What is the events file? ')                   
    events = load_events(event_file_name)
#    print(events)

#getting how much time the user wants and making sure it's a positive number
    start_time = int(input('How much time do you want to start with? '))
    while start_time <= 0:
        start_time = int(input('How much time do you want to start with? '))

    #points is the list with charisma and stealth, retrieving it from the create_character function
    points = create_character()

    #function to play the game
    var_5 = play_game(start_time, game_map, events, points)

#i left those 2 print statements commented it out, because it might be easier to actually look at how i've returned the map + events file... just in case

#also for reference, for the event file:
#location = events[0]
#description = events[1]
#win_text = events[2]
#lose_text = events[3]
#charisma = events[4]
#stealth = events[5]
#time penalty = events[6]
