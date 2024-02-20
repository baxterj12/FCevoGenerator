# FCevoGenerator
Determines what the best possible evolution combination is for a FC24 ultimate team player
in FC24 ultimate team, evolutions are used to raise the stats of a player. Evos can be chained, 
so an already evolved player can go into another evo
data files were taken from https://www.kaggle.com/datasets/stefanoleone992/ea-sports-fc-24-complete-player-dataset and mutated in R
to create an all players data file.
This is read into the players class, from which onePlayer takes the data pertaining to a specific player
the evos class contains data on evo including their requirements and how much they increase a player's stats
the combo class functions use a base player from the onePlayer class and recursively make new iterations of the player and apply the possible evos, creating a vector of all possible evolutions and couting the summary.

Constraints: 
1. to reduce the number of parameters, only the categories of pace, shooting, passing, dribbling, defending, and defense, along
with overall, are taken into account. Some evolutions use subcategories of these states (ex: balance in dribbling) to determine if a player
may use that evo. My code does not take this into account, and therefore may not be entirely accurate\
2. I only took from a data set using base players. Therefore, event players such as Team of the Week and Winter Wildcards are not
able to be analyzed through this code
3. all data about a player was taking from the kaggle dataset, which appears to be accurate but i cannot gauarantee its accuracy.

Next Steps:
1. create a function that determines the best possible evos from all players, not just from the player inputted.
2. decrease runtime and make code cleaner, reduce WCSC if possible
3. maybe - frontend implementation
