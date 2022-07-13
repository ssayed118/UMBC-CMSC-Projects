"""
File: hw6_part5.py
Auhtor: Sumaa Sayed
Date: 4/10/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in a name of a space ship, and its speed, and compare it to other ships.
"""

class SpaceShip:
   def __init__(self, name, speed):
      """
      This function will take in the name of the ship, and its speed.
      :param name: the name of the ship
      :param speed: ship's speed
      """
      # setting the speed and name variables
      self.speed = speed
      self.name = name

   def compare(self, var):
      """
      This function will compare the speeds for each ship. 
      :param var: other ship's name that is being compared
      """
      #comparing the speeds
      if var.speed < self.speed:
         print(self.name, "is faster than", var.name)


if __name__ == '__main__':
   apollo_11 = SpaceShip('Apollo 11', 7/300000)
   millennium_falcon = SpaceShip('Millennium Falcon', 1.5)
   next_generation = SpaceShip('Enterprise-D', 8)
   print(next_generation.name, next_generation.speed)
   next_generation.compare(millennium_falcon)
   millennium_falcon.compare(apollo_11)
