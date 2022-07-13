"""                                                                           
File: hw1_part2.py                                                            
Author: Sumaa Sayed                                                           
Date: 2/2/20                                                                  
Section: 16                                                                    
Email: ssayed1@umbc.edu                                                        
Description: This program will allow the user to input the price of a burrito, and a products price, and compare the two.   
"""

if __name__ == "__main__":

    # prompting the user to input price of burrito, product name, and product price
    price_burrito = float(input('What is the average price of a burrito? '))
    product = input('What item would you like to convert into burritos? ')
    price_product = float(input('What is the price of a(n) ' + product + '? '))

    # calculation for how many burritos you could buy for your product
    number = price_product / price_burrito

    #printing how many burritos you could buy for the product
    print("Your", product, "is worth", number, "burritos.")
