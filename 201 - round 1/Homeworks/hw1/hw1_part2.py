"""
File: hw1_part2.py
Author: Sumaa Sayed
Date: 9/12/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program allows for the user to see how many candy bars they can buy, with the amount of money they make in a day. 
"""

if __name__ == '__main__':
    money_made_in_a_day = float(input('Enter the amount of money made: ' ))
    price_of_favorite_candy_bar = float(input('Enter the price of candy bar: '))
    
    pay_in_price_of_candy_bars = money_made_in_a_day / price_of_favorite_candy_bar

    print("What is your daily income?", money_made_in_a_day)    
    print("How much does your favorite candy bar cost?", price_of_favorite_candy_bar)
    print("You earned", pay_in_price_of_candy_bars, "candy bars today!")