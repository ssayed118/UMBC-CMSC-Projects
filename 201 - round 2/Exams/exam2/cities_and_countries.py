"""
File: cites_and_countries.py
Author: Sumaa Sayed
Date: 4/17/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take a country, and its cities, and then print out a list of countires, that the city is in.
"""

class CitiesAndCountries:
   
   #need a constructor to set a dictionary
   def __init__(self):
      self.my_dict = {}

   def add_country(self, country_name):
       """
       :param country_name: name of new country
       :return: True if added, False if duplicate
       """
       #adding the country to the dictionary and making it the key, value will be a list
       if country_name not in self.my_dict:
          self.my_dict[country_name] = []
          return True
       
       else:
          return False

   def add_city(self, country_name, city_name):
       """
       :param country_name: must be a country in the already defined countries
       :param city_name: name of new city.
       :return: True if added, False if not added
       """
       #adding the city to the appropriate country list
       if country_name in self.my_dict:
          self.my_dict[country_name].append(city_name)
          return True
          
       else:
          return False

   def find_city(self, city_name):
       """
       :param city_name: get all cities with that name, in all different countries 
       :return: list of countries which have a city with that name, empty list if none
       """
       #making a list of countries if it has a specific city
       c_and_c_list = []
       for country in self.my_dict:
          if city_name in self.my_dict[country]:
             c_and_c_list.append(country)
       return c_and_c_list

if __name__ == "__main__": 
   c_and_c = CitiesAndCountries()
   c_and_c.add_country('USA')
   c_and_c.add_city('USA', 'Baltimore')
   c_and_c.add_city('USA', 'Washington, D.C.')
   c_and_c.add_city('USA', 'Los Angeles')
   c_and_c.add_city('USA', 'Moscow')
   # there's one in Idaho
   c_and_c.add_country('Russia')
   c_and_c.add_city('Russia', 'Novosibirsk')
   c_and_c.add_city('Russia', 'Vladivostok')
   c_and_c.add_city('Russia', 'Moscow')
   print(c_and_c.find_city('Moscow'))
   print(c_and_c.find_city('Los Angeles'))

   #for my own testing purpose
   print(c_and_c.find_city('Baltimore'))
   print(c_and_c.find_city('Novosibirsk'))
