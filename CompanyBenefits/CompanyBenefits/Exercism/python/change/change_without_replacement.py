def find_fewest_coins(coins, target):
    if target == 0:
        return []
    if any(coin == target for coin in coins):
        return [target]
    if not any(coin < 0 for coin in coins):
        for coin in coins:
            if coin > target:
                coins.remove(coin)
    if not any(coin > 0 for coin in coins):
        for coin in coins:
            if coin < target:
                coins.remove(coin)
    valid_combos = []
    for num in range(2**len(coins)):
        coin_set = [coins[i] for i in range(len(coins)) if num & 2**i]
        x = sum(coin_set)
        if x == target:
            if len(valid_combos) == 0:
                valid_combos = [coin_set]
            elif len(coin_set) < len(valid_combos[0]):
                valid_combos = [coin_set]
            elif len(coin_set) == len(valid_combos[0]):
                valid_combos.append(coin_set)
    return valid_combos
        
