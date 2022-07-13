"""
File: hw6_part2.py
Author: Sumaa Sayed
Date: 4/12/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in 2 numbers, and print out a's and b's.
"""

def as_and_bs(n, k, current):
   """
   This function will take in the HELLO
   :param n: the number of total letters in the string
   :param k: the number of a's in the string
   :param current: starts off as an empty string, holds the current value
   """
   #base case   
   if k == 0 and n == 0:
      print(current)
      
   #recursive cases
   if n > 0 and k == 0:
      as_and_bs(n - 1, k, current + "b")
      
   if k > 0 and n > 0:
      as_and_bs(n - 1, k - 1, current + "a")
      as_and_bs(n - 1, k, current + "b")

if __name__ == "__main__":   
   #asking for values for n, and k, setting current as an empty string
   n = int(input('Enter how long the strings are: '))
   k = int(input('How many a.s do you want: '))
   current = " "

   #calling the function
   var = as_and_bs(n, k, current)
