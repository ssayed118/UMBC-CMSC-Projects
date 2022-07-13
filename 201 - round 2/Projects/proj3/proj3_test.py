"""
File: proj3_test.py
Author: Sumaa Sayed
Date: 4/29/20
Section: 16
Email: ssayed1@umbc.edu
Description: Test scripts for project 3.
"""
from proj3 import DynasticDescent

def test_find_ancestors(person_name, degree):
    #i renamed find_ancestors from get_parents
    """
    This function will get the ancestor for the person.
    :param person_name: name of person getting checked
    :param degree: how far to go for the recursive function
    """
    dd = DynasticDescent()
    dd.load_file('test_parents.json')
    
    if dd.find_ancestors('test person', 1) == ['parent one', 'parent two']:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if dd.find_ancestors('test person', 1) == ['parent one']:
        print("test 2 passed")
    else:
        print("test 2 passed")

    if dd.find_ancestors('test person', 1) == [ ]:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if dd.find_ancestors('test person', 2) == ['grandparent one', 'grandparent two']:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if dd.find_ancestors('test person', 2) == ['grandparent one']:
        print("test 5 passed")
    else:
        print("test 5 failed")

def test_find_descendants(person_name, degree):
    #renamed from get_children
    """
    This function will find the children for the person.
    :param person_name: name of person getting checked
    :param degree: how far to go for the recursive function
    """
    dd = DynasticDescent()
    dd.load_file('test_children.json')

    if dd.find_descendants('test person', 1) == {'person name' : ['child']}:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if dd.find_descendants('test person', 1) == {'person name': [ ] }:
        print("test 2 passed")
    else:
        print("test 2 passed")

    if dd.find_descendants('test person', 1) == {'person name' : ['child 1', 'child 2']:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if dd.find_descendants('test person', 1) == {'person name': ['child 1', 'child 2', 'child 3']}:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if dd.find_descendants('test person', 1) == {'person name' : ['child 1', 'child 2', 'child 3', 'child 4']}:
        print("test 5 passed")
    else:
        print("test 5 failed")
        
def test_save_tree(file_name):
    """
    This function is for saving the tree.
    :param file_name: name of file
    """
    dd = DynasticDescent()
    
    if dd.save_tree('plantagenet.json') == {'person name' : [['child'], ['parent 1'], ['sibling 1']]}:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if dd.save_tree('plantagenet_3.json') == {'person name': [['child 1'], ['parent 1', 'parent 2']]}:
        print("test 2 passed")
    else:
        print("test 2 passed")

    if dd.save_tree('harry_potter_fam.json') == {'person name': [['child 1', 'child 2', 'child 3'], ['parent 1', 'parent 2']]}:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if dd.save_tree('plantagentnet_2.json') == {'person name': [['child 1, child 2'], ['parent 1'], [ ]]}:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if dd.save_tree('family_tree_1.json') == {'person name': [[ ], ['parent 1', 'parent 2'], ['sibling 1']]}:
        print("test 5 passed")
    else:
        print("test 5 failed")

def test_load_tree(file_name):
    """
    This function is to load the tree
    :param file_name: name of file
    """
    dd = DynasticDescent()
    if dd.load_tree('plantagenet.json') == {'person name' : [['child'], ['parent 1'], ['sibling 1']]}:
        print("test 1 passed")
    else:
        print("test 1 failed")

    if dd.load_tree('plantagenet_3.json') == {'person name': [['child 1'], ['parent 1', 'parent 2']]}:
        print("test 2 passed")
    else:
        print("test 2 passed")

    if dd.load_tree('harry_potter_fam.json') == {'person name': [['child 1', 'child 2', 'child 3'], ['parent 1', 'parent 2']]}:
        print("test 3 passed")
    else:
        print("test 3 failed")

    if dd.load_tree('plantagentnet_2.json ') == {'person name': [['child 1, child 2'], ['parent 1'], [ ]]}:
        print("test 4 passed")
    else:
        print("test 4 failed")

    if dd.load_tree('family_tree_1.json') == {'person name': [[ ], ['parent 1',['parent 2'], ['sibling 1']]}:
        print("test 5 passed")
    else:
        print("test 5 failed")
    
if __name__ == "__main__":
    print(test_find_ancestors(person_name, degree))
    print(test_find_descendants(person_name, degree))
    print(test_save_tree(file_name))
    print(test_load_tree(file_name))
