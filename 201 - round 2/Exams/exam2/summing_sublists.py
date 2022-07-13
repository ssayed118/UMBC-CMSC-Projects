"""
File: summing_sublists.py
Author: Sumaa Sayed
Date: 4/15/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take a list of numbers and find a sublist in that list, that adds up to a "goal."
"""

def sum_goal_buggy(my_list, goal):
    """
    :param my_list: list of numbers
    :param goal: goal to be added up
    :return: True if some sublist adds to goal, False else
    """
    if goal == 0:
        return True
    
    else:
        if len(my_list) == 0:
            return False
#added the above 2 lines b/c if the list is empty, but the goal > 0, then the goal won't be reached
        
        # ignore my_list[0] ~ Professor's comment
        if sum_goal_buggy(my_list[1:], goal - my_list[0]):
        #my_list[0] was added so it's included in the sum
        
            return True
        
        # include my_list[0] in the sum ~ Proffessor's comment
        elif sum_goal_buggy(my_list[1:], goal):
    #my_list[0] isn't needed here, so removed that, and started splicng at 1
            
            return True
        
        return False

if __name__ == "__main__":
    print(sum_goal_buggy([1, 2, 3], 5))
    # True
    print(sum_goal_buggy([1, 2, 3], 17))
    # False
    print(sum_goal_buggy([1, 2, 3], 3))
    # True
    print(sum_goal_buggy([1, 2, 3, 6, 8, 12], 18))
    # True
    print(sum_goal_buggy([1, 2, 3, 6, 8, 12], 33))
    # False

    #for my own testing purposes
    print(sum_goal_buggy([18, 27, 36], 0))
    #True
    print(sum_goal_buggy([1, 7, 16], 23))
    #True
