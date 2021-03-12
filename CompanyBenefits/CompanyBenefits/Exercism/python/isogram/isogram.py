def is_isogram(string):
    characters = {}
    for char in string:
        if char.lower() in characters:
            return False
        elif char not in '- ':
            characters[char.lower()] = True
    return True
