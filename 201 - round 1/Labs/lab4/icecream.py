"""
File: icecream.py
Author: Sumaa Sayed
Date: 9/25/19
Section: 16
Email: ssayed1@umbc.edu
Description: This program prints out differnt flavors of icecream and toppings that go with that flavor of icecream.
"""

if __name__ == '__main__':
   ice_cream_flavors = ["vanilla", "strawberry", "chocolate"]
   toppings = ["caramel", "marshmallow", "gummi bears"]

   for ice_cream_type in ice_cream_flavors:
      if ice_cream_type == "strawberry":
         print(ice_cream_type, "is fine on its own!")
      else:
         for topping in toppings:
            print(ice_cream_type, "is tasty with", topping)
       


