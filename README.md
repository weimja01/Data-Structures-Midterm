# Data-Structures-Midterm/Final

Jeff Weimer
CSCI202 Data Structures
November 2025

The Oregon Journey

This is a text based game, based on the original The Oregon Trail game.

The player must head West to Oregon from the starting point in Missouri. 

The player must keep track of their food provisions and their health.

Along the way there will be problems that the player must solve.

The player can take actions throughout the game to gain food, restore health, or deal with problems. 

Problems must be dealt with before moving on to the next level. 

The player wins if they reach Oregon City, Oregon without dying along the way.

The player can die by losing all health, or running out of food. 

Trail Locations:
1. Independence, Missouri - Starting Point
2. Kansas River - River Crossing
3. Fort Kearney - Rest Stop
4. Chimney Rock - Famous Landmark
5. Oregon City - Final Destination

Problems - Use Stack
1. Broken Wagon - Costs health and food to repair
2. Illness - Requires rest to recover costs health
3. Bad Weather - Must wait out storms costs food
4. Snake Bite - Costs health to survive

Actons - Use Queue
1. Travel - Move to the next location (costs food, may trigger problems)
2. Rest - Restores health (costs food)
3. Hunt - Gather food (costs health from exhaustion)
Actions are queued by the player and executed in a first in first out order.

Resources to manage
1. Food: Start with 200lbs
2. Health: Start with 100.


Example Gameplay
========================================
     THE OREGON Journey
========================================

Setting up the Oregon Journey...
Trail established with 5 locations.
Your journey begins....

*** NEW PROBLEM OCCURRED! ***
[Broken Wagon] Your wagon needs repair before departing.

=================================
LOCATION 1 of 5
=================================
Independence, Missouri
Starting point! April 1, 1848
=================================

---PARTY STATUS---
Health: 100/100
Food: 200 lbs
------------------

!!! URGENT PROBLEM (must solve first) !!!
[Broken Wagon] Your wagon needs repair before departing.

WHAT DO YOU WANT TO DO?
1. Solve current problem
2. Queue an action
3. Execute queued actions
...




