"""
This exercise stub and the test suite contain several enumerated constants.

Since Python 2 does not have the enum module, the idiomatic way to write
enumerated constants has traditionally been a NAME assigned to an arbitrary,
but unique value. An integer is traditionally used because it’s memory
efficient.
It is a common practice to export both constants and functions that work with
those constants (ex. the constants in the os, subprocess and re modules).

You can learn more here: https://en.wikipedia.org/wiki/Enumerated_type
"""


# Score categories.
# Change the values as you see fit.
YACHT = 0
ONES = 1
TWOS = 2
THREES = 3
FOURS = 4
FIVES = 5
SIXES = 6
FULL_HOUSE = 7
FOUR_OF_A_KIND = 8
LITTLE_STRAIGHT = 9
BIG_STRAIGHT = 10
CHOICE = 11


def score(dice, category):
    if category in range(1,7):
        return sum(x for x in dice if x == category)
    elif category == 11:
        return sum(dice)
    elif qualifier(dice, category):
        if category in [9, 10]:
            return 30
        elif category == 0:
            return 50
        elif category == 8:
            return qualifier(dice, category)
        else:
            return sum(dice)
    else:
        return 0

def qualifier(dice, category):
    dice_count = {}
    dice.sort()
    for die in dice:
        if die in dice_count:
            dice_count[die] += 1
        else:
            dice_count[die] = 1
    if len(dice_count) < 3:
        if category == 7:
            for die in dice_count:
                if dice_count[die] == 3:
                    return True
        elif category == 8:
            for die in dice_count:
                if dice_count[die] >= 4:
                    return 4*die
    if len(dice_count) == 1 and category == 0:
        return True
    if category == 9:
        return [*range(1, 6)] == dice
    if category == 10:
        return [*range(2, 7)] == dice
    return False
        
    
