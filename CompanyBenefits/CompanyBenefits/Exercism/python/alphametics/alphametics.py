from itertools import permutations

def solve(puzzle):
    puzzle = ''.join(puzzle.split(' '))
    components, summ = puzzle.split('==')
    comp = components.split('+')
    zero_exclude = []
    letters = set()
    for item in (*comp, summ):
        if item[0] not in zero_exclude:
            zero_exclude.append(item[0])
        letters.update([char for char in item])
    letters = list(letters)
    for combo in permutations(range(10), len(letters)):
        temp_dict = {}
        for num in range(len(combo)):
            temp_dict[letters[num]] = combo[num]
        if any(temp_dict[char] == 0 for char in zero_exclude):
            continue
        left_sum = 0
        for component in comp:
            left_sum += int(''.join(str(temp_dict[char]) for char in component))
        right_sum = int(''.join(str(temp_dict[char]) for char in summ))
        if left_sum == right_sum:
            return temp_dict
