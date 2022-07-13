"""
File: proj1.py
Author: Sumaa Sayed
Date: 10/15/2019
Section: 16
E-mail:  ssayed1@umbc.edu
Description: This program will allow the user to play a baking simulator, and the user must stay within the budget. If they stay within the budget, they move
on to baking the items.
"""

STARTING_PRICE = 80.0
FLOUR_COST_PER_BAG = 2.5
EGGS_COST_PER_CRATE = 1.9
YEAST_COST_PER_BAGS = 3.25
BUTTER_COST_PER_PACK = 1.25
MILK_COST_PER_JUG = 2.75
GALLONS_MILK_PER_JUG = 1.0
EGGS_PER_CRATE = 24.0
TBSP_BUTTER_PER_PACK = 64.0
CUPS_FLOUR_PER_BAG = 25.0
CUP_YEAST_PER_BAG = 6.0
FLOUR_REQUIRED = 48.0 + 112.5
EGGS_REQUIRED = 12.0 + 60.0
BUTTER_REQUIRED = 144.0
YEAST_REQUIRED = 39 + 50
MILK_REQUIRED = 18.0
CUPS_IN_GALLON = 16
TSP_IN_CUP = 48

#added more constants, but may possibly need more, will figure it out while actually coding yaknow
FLOUR_FOR_CROISSANTS = 48.0
EGGS_PER_CROISSANTS = 12.0
BUTTER_PER_CROISSANTS = 144.0
YEAST_PER_CROISSANTS = 39.0
CUPS_MILK_PER_CROISSANT = 18.0
EGGS_PER_MACARONS = 60.0
FLOUR_PER_BAGUETTES = 112.5
YEAST_PER_BAGUETTES = 50.0
CRATES_OF_EGGS = 5.0
BAGS_OF_FLOUR = 7.0
PACKS_OF_BUTTER = 5.0
BAGS_OF_YEAST = 5.0
JUGS_OF_MILK = 5.0
#not entirely sure if all of these are allowed but putting them anyways
tasks_remaining = ["Begin the baguette dough", "Make the macarons", "make the croissants", "bake the baguettes"]
shopping_cart = ["eggs", "butter", "yeast", "flour", "milk"]
index = len(tasks_remaining)
tasks = tasks_remaining

def go_shopping():
    """
    A function to go shopping and will print what the user needs to buy, with the given $80.
    :return: the items bought from the store/shopping trip
    """
    print("Baker! You must buy the following with $80:\n For 300 croissants:\n 48 cups of flour\n 12 eggs\n 144 tbsp of butter\n 39 tsp of yeast\n 18 cups of milk\n For 600 macarons:\n 60 eggs\n For 100 baguettes:\n 112.5 cups of flour\n 5 tsp of yeast\n Welcome to the supermarket!")
# this will ask the user what times they would like to buy the groccery store 
    purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
    current_funds = STARTING_PRICE
    while purchase != "NOTHING":
        # purchases must be from the shopping cart list, i just realized that i never actually implemented that whoops 
        if purchase == "eggs":
            num_eggs = int(input('How many crates of eggs would you like? '))
            price_eggs = num_eggs * EGGS_COST_PER_CRATE
            amount_eggs = EGGS_REQUIRED - (num_eggs * EGGS_PER_CRATE) 
            purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
            
        if purchase == "flour":
            num_flour = int(input('How many bags of flour would you like? '))
            price_flour = num_flour * FLOUR_COST_PER_BAG
            amount_flour = FLOUR_REQUIRED - (num_flour * CUPS_FLOUR_PER_BAG)
            purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
            
        if purchase == "butter":
            num_butter = int(input('How many packs of butter would you like? '))
            price_butter = num_butter * BUTTER_COST_PER_PACK
            amount_butter = BUTTER_REQUIRED - (num_butter * TBSP_BUTTER_PER_PACK)
            purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
            
        if purchase == "yeast":
            num_yeast = int(input('How many bags of yeast would you like? '))
            price_yeast = num_yeast * YEAST_COST_PER_BAGS
            amount_yeast = YEAST_REQUIRED - (num_yeast * CUP_YEAST_PER_BAG)
            purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
            
        if purchase == "milk":
            num_milk = int(input('How many jugs of milk would you like? '))
            price_milk = num_milk * MILK_COST_PER_JUG
            amount_milk = MILK_REQUIRED - (num_milk * GALLONS_MILK_PER_JUG) 
            purchase = input('What would you like to purchase? (ENTER "NOTHING" to leave store): ')
            
# for loop in case someone types in something that's invalid// DOES NOT WORK
#        if purchase != shopping_cart and purchase != "NOTHING":
 #           print("invalid entry")
  #          purchase = input('What would you like to purchase? (ENTER "NOTHING"to leave store): ')

# if purchase == "NOTHING": , probaly should have put this into this function but nothing is working

def check_items_enough(shopping_cart):
    """
    A function to check if there are enough items in the shopping cart
    :param shopping_cart: the items in the cart/ needed in the cart
    :return: the items that are in the cart
    """
    price_eggs = num_eggs * EGGS_COST_PER_CRATE
    price_flour = num_flour * FLOUR_COST_PER_BAG
    price_butter = num_butter * BUTTER_COST_PER_PACK
    price_yeast = num_yeast * YEAST_COST_PER_BAGS
    price_milk = num_milk * MILK_COST_PER_JUG
# something along the lines of "if (EGGS_REQUIRED - amount_eggs) blah" should ho here but this entire thing is due in 20 minutes!!! i'm soryy!!!!!!

    purchase = input('What would you like to purchase? (Enter "NOTHING" to leave store): ')
    if purchase == "NOTHING":
        # if the purchases are above $80 then fail!
        if int(price_eggs) + int(price_flour) + int(price_butter) + int(price_yeast) + int(price_milk) > current_funds:
            print("You did not buy enough ingredients to even begin baking. Youare a failure of all sorts. Good day.")
            
        # if the purchases are below $80 then move one   
        if int(price_eggs) + int(price_flour) + int(price_butter) + int(price_yeast) + int(price_milk) < current_funds:
            print("We have everything we need! Ready! Set! Bake!")
# these 2 print statements above print like a bunch of times and i can't get itto move on afterwards, but the rest of my functions(besides check_items_enough and maybe is_valid_input) work well together 
# i'm pretty sure the calculations here have to do with the ingredients and not the amounts but again, this is due very very soon

def print_task_list(tasks_remaining):
    """
    A function that prints the tasks remaining. Baguettes should be completed first. (a more specific order is in the sample doc, but it should be baguettes, then croissants and then whatever else i think???)
    :param tasks_remaining: tasks that have not been completed
    :return: nothing
    """
    tasks_remaining = ["Begin the baguette dough", "Make the macarons", "make the croissants", "bake the baguettes"]
    print("Here are your remaining tasks of the day:")
    for i in range(len(tasks_remaining)):
        print(i+1, tasks_remaining[i])
# this for loop print out the tasks with the numbers

# okay so i totally messed up on this function while completing the design... i fixed it now but it's obviously going to be different from my design file
def is_valid_input(index, tasks):
    """
    A function that will check if the input was valid, given the list of tasks.
    :param index: number that is inputted
    :param tasks: tasks that are left to do, starting with 1 (baguettes)
    :return: possibly an error saying that the user should work on the baguettes first, depends on input
    """
    #okay this part is definitly incorrect but its literally 11pm and i'm tired
    if len(tasks_remaining) < index:
        return false
    else:
        return True
    
def bake():
    """
    A function that prints the tasks left and checks to see if the tasks are completed in order.
    :return: if the products were baked in the correct order, then the program will printout a statement saying that every task was completed... if the itemswere baked incorrectly, a message will prin out, pushing the user to make baguettes.
    """
    tasks_remaining = ["Begin the baguette dough", "Make the macarons", "make the croissants", "bake the baguettes"]
# asking the user what task they want to complete 
    complete_task = int(input('What action would you like to cross off your list next?: '))
    # regardless of what you put for the input the first time^, you're gonna have to input twice, especially for task 1... can't figure out why
    while complete_task != "1":
        print("We should really start the baguette dough first!")
        complete_task = input('What action would you like to cross off your list next?: ')
        print(tasks_remaining)
# while the input isn't 1, the user will keep getting the input question until they type in 1
# once the user types in 1, then they continue to simiulate throuhg the baking order until they've completed all the tasks
    if complete_task == "1":
        print("Okay let's knead some baguette dough!")
        tasks_remaining.remove("Begin the baguette dough")
        print(tasks_remaining)
        complete_task = input('What action would you like to cross off your list next?: ')
        if complete_task == "1":
            print("Adorable sandwich cookies coming right up!")
            tasks_remaining.remove("Make the macarons")
            print(tasks_remaining)
            complete_task = input('What action would you like to cross off your list next?: ')
            if complete_task == "1":
                print("Let's make some flaky crescent goodness!")
                tasks_remaining.remove("make the croissants")
                print(tasks_remaining)
                complete_task = input('What action would you like to cross off your list next?: ')
                if complete_task == "1":
                    print("All done! Let's hope we've PRUEven ourselves worthy.")              
        if complete_task == "2":
            print("Let's make some flaky crescent goodness!")
            tasks_remaining.remove("make the croissants")
            print(tasks_remaining)
            complete_task = input('What action would you like to cross off your list next? ')
            
            if complete_task == "1":
                print("Adorable sandwich cookies coming right up!")
                tasks_remaining.remove("Make the macarons")
                print(tasks_remaining)
                complete_task = input('What action would you like to cross off your list next?: ')
                
                if complete_task == "1":
                    print("All done! Let's hope we've PRUEven ourselves worthy.")
            if complete_task == "2":
                print("Whoa, we should probably do everything else first!")
                print(tasks_remaining)
                complete_task = input('What action would you like to cross off your list next?: ')
                
        # the user must bake the baguettes last!! or else they'll be a failure
        elif complete_task == "3":
            print("Whoa, we should probably do everything else first!")
            print(tasks_remaining)
            complete_task = input('What action would you like to cross off your list next? ')
            
            if complete_task == "1":
                print("Adorable sandwich cookies coming right up!")
                tasks_remaining.remove("Make the macarons")
                print(tasks_remaining)
                complete_task = input('What action would you like to cross off your list next?: ')
                
            if complete_task == "2":
                print("Let's make some flaky crescent goodness!")
                tasks_remaining.remove("make the croissants")
                print(tasks_remaining)
                complete_task = input('What action would you like to cross off your list next?: ')
                
# once the user is done, just like i am with this project, then the user gets this statement
                if complete_task == "1":
                    print("All done! Let's hope we've PRUEven ourselves worthy")
                    
if __name__ == '__main__':
    go_shopping()
    check_items_enough(shopping_cart)
    print_task_list(tasks_remaining)
    is_valid_input(index, tasks)
    bake()
# okay so the last 3 functions work, from what i checked but, the first function is sort of bursting print statements and i can't really figure out the check items function so if i can get any sort of credit for this, it might be better to run each function individually (which sucks) but that's how i worked out the ones that "run"
