"""
File: person.py
Author: Sumaa Sayed 
Date: 4/29/20
Section: 16
Email: ssayed1@umbc.edu
Description: Person class for project 3.
"""

class Person:
    def __init__(self, name):
        """
        This function is to declare the lists for parents and kids.
        :param name: name of the person where parents & kids will be stored
        """
        #setting the name variable and lists for parents + kids 
        self.name = name
        self.parents = []
        self.children  = []

    def add_parent(self, name):
        """
        This function will add the parents in the appropriate parent list.
        :param name: name of person whose parents are being added
        """
        #making sure that each person has ~2 people in their parents list
        if name not in self.parents and len(self.parents) < 2:
            self.parents.append(name)
            
    def add_children(self, name):
        """
        This function will add the children to the appropriate list.
        :param name: name of person whose children are being added
        """
        #making sure that the same child isn't added twice
        if name not in self.children:
            self.children.append(name)

    def get_parents(self):
        """
        This function will return the list of parents.
        """
        return self.parents

    def get_children(self):
        """
        This function will return the list of children.
        """
        return self.children

    def jsonify(self):
        """
        This function will "jsonify" the dictionary used in DD.
        """
        #just formatting the dictionary for saving/loading
        return {self.name : {'parents': self.parents, 'children': self.children } }
