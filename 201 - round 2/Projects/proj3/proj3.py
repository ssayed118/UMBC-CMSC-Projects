"""
File: proj3.py
Author: Sumaa Sayed
Date: 4/29/20
Section: 16
Email: ssayed1@umbc.edu
Description: hoenstly idk please just give me an A
"""
import json
from person import Person

class DynasticDescent:
    def __init__(self):
        """
        Setting a dictionary to make the tree and for person.
        """
        self.family_tree = {}
        self.person = {}
        
    def add_person(self):
        """                                                                  
        This function will add names to the family_tree dictionary.            
        """
        #getting the name to add
        name = input('What is the name of the human? ')
        while name in self.family_tree:
            name = input('What is the name of the human? ')
            
        person = Person(name)
        self.family_tree[name] = person
        
    def find_ancestors(self, degree, name):
        """
        This function will find a person's ancestors.
        :param name: name of person whose ancestors are being found
        :param degree: the number of generations to run through
        """
        #using this to keep track of person the function is at
        current_person = d_d.family_tree[name]

        #base case
        if degree == 0:
            return name

        #recursive case
        else:
#setting an empty string to append to (if there's just more than 1 person)
            temp = ''
            parents = current_person.get_parents()

            #for loop to go through each parent
            for i in parents:
                temp += self.find_ancestors(degree - 1, i)
    
            return temp
    
    def find_descendants(self, degree, name):
        """
        This function will find a person's descendants.                        
        :param name: name of person whose descendants are being found          
        :param degree: the number of generations to run through
        """
        #same comments from above function apply here!
        current_person = self.family_tree[name]
        if degree == 0:
            return name

        else:
            temp = ''
            child = current_person.get_children()
            for i in child:
                temp += self.find_descendants(degree - 1, i)

            return temp
        
    def get_siblings(self):
        """
        This function will retrieve a persons siblings.
        """
        #getting the persons name to find their siblings
        name = str(input('What is the name of the human? '))
        while name not in self.family_tree.keys():
            name = str(input('What is the name of the human? '))

        #setting variable to loop through the persons parents list
        person = self.family_tree[name]
        var = person.parents

        #setting an empty list to store siblings
        sib_list = []

        #looping throuhg the parents and grabbing names 
        for parent_name in var:
            parent = self.family_tree[parent_name]
            for child in parent.children:
                if child != name:
                    #appending if it's anyone besided the name entered
                    sib_list.append(child)
        
        return sib_list

    def save_tree(self, file_name):
        """
        Function for saving the tree into a file.
        :param file_name: name of file to save the tree to
        """
        #setting an empty dict to store the contents of the tree
        my_dict = {}

        #for each name in the tree, "jsonifying" it to add to my_dict
        for name in self.family_tree:
            print(self.family_tree[name].jsonify())
            my_dict.update(self.family_tree[name].jsonify())

        #writing the file
        with open(file_name, "w") as tree_file:
            tree_file.write(json.dumps(my_dict))
    
    def load_tree(self, file_name):
        """
        Function for loading a tree that the user inputs.
        :param file_name: name of file to be read and used
        """
        #reading the file
        with open(file_name, "r") as read_json:
            entire_file = read_json.read()
            family_dict = json.loads(entire_file)

            #formatting it to the proper format
            for name in family_dict:
                person_dict = family_dict[name]
                new_person = Person(name)
                
                #grabbing names that aren't already in person
                if name not in self.person:
                    self.person[name] = new_person
                    
#        print(self.person)

if __name__ == "__main__":
#okay yes, i know this area is a mess, and definitly not "clean" but i am tired
    
    #calling the class
    d_d = DynasticDescent()

#prompting user for a move, and getting the program to run until user enters 'quit'
    move = input('What would you like to do next? ')
    while move != "quit":

#for each move, a function will be called & user will be re-prompted for a move
        if move == "add":
            d_d.add_person()
            
            #re-prompting for a move
            move = input('What would you like to do next? ')

        if move == "get parents":
            #setting the degree for the function
            degree = 1

            #getting a name for the program to look through
            name = str(input('What is the name of the human? '))
            while name not in d_d.family_tree.keys():
                name = str(input('What is the name of the human? '))
                
            print(d_d.find_ancestors(degree, name))
            move = input('What would you like to do next? ')
            
        if move == "get grandparents":
            degree = 2
            
            name = str(input('What is the name of the human? '))               
            while name not in d_d.family_tree.keys():                         
                name = str(input('What is the name of the human? '))
                
            print(d_d.find_ancestors(degree, name))
            move = input('What would you like to do next? ')

        if move == "get ancestors":
            name = str(input('What is the name of the human? '))
            while name not in d_d.family_tree.keys():
                name = str(input('What is the name of the human? '))
                
            #prompting the user for a degree
            degree = int(input('What is the degree of ancestors? '))
            print(d_d.find_ancestors(degree, name))
            move = input('What would you like to do next? ')

        if move == "get children":
            degree = 1
            
            name = str(input('What is the name of the human? '))
            while name not in d_d.family_tree.keys():
                name = str(input('What is the name of the human? '))
                
            print(d_d.find_descendants(degree, name))
            move = input('What would you like to do next? ')
            
        if move == "get grandchildren":
            degree = 2
            
            name = str(input('What is the name of the human? '))
            while name not in d_d.family_tree.keys():
                name = str(input('What is the name of the human? '))
                
            print(d_d.find_descendants(degree, name))
            move = input('What would you like to do next? ')
            
        if move == "get descendants":
            name = str(input('What is the name of the human? '))
            while name not in d_d.family_tree.keys():
                name = str(input('What is the name of the human? '))
                
            degree = int(input('What is the degree of descent? '))
            print(d_d.find_descendants(degree, name))
            move = input('What would you like to do next? ')

        if move == "get siblings":
            #after retrieving siblings of a person, printing them out
            siblings_list = d_d.get_siblings()
            for name in siblings_list:
                print(name, end=' ')
            print()
            
            move = input('What would you like to do next? ')
            
        if move == "relate":
            #getting the parent name & validating
            parent_name = input('What is the name of the parent human? ')
            while parent_name not in d_d.family_tree.keys():
                parent_name = input('What is the name of the parent human? ')

            #getting child name & validation
            child_name = input('What is the name of the child human? ')
            while child_name not in d_d.family_tree.keys():
                child_name = input('What is the name of the child human? ')

            #appending the names to the appropriate lists
            d_d.family_tree[parent_name].add_children(child_name)
            d_d.family_tree[child_name].add_parent(parent_name) 
            move = input('What would you like to do next? ')
            
        if move == "save tree":
            #asking user what they wanna call their file
            file_name = input('What is the file name to save? ')
            d_d.save_tree(file_name)
            move = input('What would you like to do next? ')
            
        if move == "load tree":
            #getting the file name from user
            file_name = input('What is the file name to load? ')
            d_d.load_tree(file_name)
            move = input('What would you like to do next? ')

    #can't remember if this is required but it just helps to see the tree 
        if move == "print":
            print(d_d.family_tree)
            move = input('What would you like to do next? ')
         
