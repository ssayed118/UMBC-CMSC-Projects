"""                                                                            
File: hw1_part3.py                                                             
Author: Sumaa Sayed                                                            
Date: 2/2/20                                                                   
Section: 16                                                                    
Email: ssayed1@umbc.edu                                                       
Description: This program will allow the user to calculate the monthly cost of a loan.
"""

if __name__ == "__main__":
    
    # getting the input from the user (values for P, r, and n)
    p_loan = float(input('What is the principal of the loan? '))
    r_interest = float(input('What is the interest rate? (in decimal form) '))
    n_loan = float(input('What is the length of the loan in years? '))

    # this is to convert the "n" value from years to months
    n_value = (n_loan * 12)

    #dividing the "r" value by 12
    r_value = (r_interest / 12)
    
    #i broke up the equation into pieces to make finding the cost easier 
    value = ((1 + r_value) ** n_value)

    # equation to calculate the cost of the loan
    cost = ((p_loan * r_value) * value) / (value - 1)
    
    print("The monthly cost of the loan is", cost)
