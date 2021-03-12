from itertools import combinations_with_replacement

def find_fewest_coins(coins, target):
    if target == 0:
        return []
    if target < 0 or type(target) != int:
        raise ValueError('I can only make change for natural numbers!')
    if target < min(coins):
        raise ValueError('Don\'t have any coins that small, sorry!')
    if target % max(coins) == 0:
        return [max(coins) for x in range(target//max(coins))]
    min_coins = 1 + target//max(coins)
    max_coins = target//min(coins)
    for number_of_coins in range(min_coins, max_coins+1):
        for combo in combinations_with_replacement(coins, number_of_coins):
            if sum(combo) == target:
                return list(combo)
    raise ValueError('Sorry, can\'t break it. Try next door?')
