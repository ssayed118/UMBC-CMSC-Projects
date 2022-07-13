"""
File: battle_dictionary.py
Author: Sumaa Sayed
Date: 5/15/20
Section: 16
Email: ssayed1@umbc.edu
Description: This program will take in 2 pokemon's stats and declare a winner.
"""

def stats(pokemon):
    """   
    This function will return the stats of a pokemon.
    :param pokemon: pokemon that the function will look at
    """
    
    #counter for stats
    total_stats = 0
    for stat in pokemon["stats"]:
        total_stats += stat["base_stat"]

    return total_stats

def fight(first_pokemon, second_pokemon):
    """
    This function will compare the stats of 2 pokemon's.
    :param first_pokemon: dictionary for the first pokemon
    :param second_pokemon: dictionary for the second pokemon
    """
    
    #setting variables for each pokemons stats
    pokemon_1 = stats(first_pokemon)
    pokemon_2 = stats(second_pokemon)

    #printing the stats for each character
    print(first_pokemon["name"], "has", pokemon_1, "combined stats.")
    print(second_pokemon["name"], "has", pokemon_2, "combined stats.")

    #comparing stats + determining winner
    if pokemon_1 > pokemon_2:
        print(first_pokemon["name"], "wins!")

    elif pokemon_2 > pokemon_1:
        print(second_pokemon["name"], "wins!")

    else:
        print("It's a tie!")

        
if __name__ == "__main__":
    first_pokemon = {
  "name": "bidoof",
  "order": 506,
  "species": {
    "name": "bidoof",
    "url": "https://pokeapi.co/api/v2/pokemon-species/399/"
  },
  "stats": [
    {
      "base_stat": 31,
      "effort": 0,
      "stat": {
        "name": "speed",
        "url": "https://pokeapi.co/api/v2/stat/6/"
      }
    },
    {
      "base_stat": 40,
      "effort": 0,
      "stat": {
        "name": "special-defense",
        "url": "https://pokeapi.co/api/v2/stat/5/"
      }
    },
    {
      "base_stat": 35,
      "effort": 0,
      "stat": {
        "name": "special-attack",
        "url": "https://pokeapi.co/api/v2/stat/4/"
      }
    },
    {
      "base_stat": 40,
      "effort": 0,
      "stat": {
        "name": "defense",
        "url": "https://pokeapi.co/api/v2/stat/3/"
      }
    },
    {
      "base_stat": 45,
      "effort": 0,
      "stat": {
        "name": "attack",
        "url": "https://pokeapi.co/api/v2/stat/2/"
      }
    },
    {
      "base_stat": 59,
      "effort": 1,
      "stat": {
        "name": "hp",
        "url": "https://pokeapi.co/api/v2/stat/1/"
      }
    }
  ],
  "types": [
    {
      "slot": 1,
      "type": {
        "name": "normal",
        "url": "https://pokeapi.co/api/v2/type/1/"
      }
    }
  ],
  "weight": 200
}

    second_pokemon = {
  "name": "ditto",
  "order": 197,
  "species": {
    "name": "ditto",
    "url": "https://pokeapi.co/api/v2/pokemon-species/132/"
  },

  "stats": [
    {
      "base_stat": 48,
      "effort": 0,
      "stat": {
        "name": "speed",
        "url": "https://pokeapi.co/api/v2/stat/6/"
      }
    },
    {
      "base_stat": 48,
      "effort": 0,
      "stat": {
        "name": "special-defense",
        "url": "https://pokeapi.co/api/v2/stat/5/"
      }
    },
    {
      "base_stat": 48,
      "effort": 0,
      "stat": {
        "name": "special-attack",
        "url": "https://pokeapi.co/api/v2/stat/4/"
      }
    },
    {
      "base_stat": 48,
      "effort": 0,
      "stat": {
        "name": "defense",
        "url": "https://pokeapi.co/api/v2/stat/3/"
      }
    },
    {
      "base_stat": 48,
      "effort": 0,
      "stat": {
        "name": "attack",
        "url": "https://pokeapi.co/api/v2/stat/2/"
      }
    },
    {
      "base_stat": 48,
      "effort": 1,
      "stat": {
        "name": "hp",
        "url": "https://pokeapi.co/api/v2/stat/1/"
      }
    }
  ],
  "types": [
    {
      "slot": 1,
      "type": {
        "name": "normal",
        "url": "https://pokeapi.co/api/v2/type/1/"
      }
    }
  ],
  "weight": 40
}
    var = (fight(first_pokemon, second_pokemon))
