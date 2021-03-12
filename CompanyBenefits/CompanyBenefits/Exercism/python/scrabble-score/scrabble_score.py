scores = {}
for letter in 'aeioulnrst':
    scores[letter] = 1
for letter in 'dg':
    scores[letter] = 2
for letter in 'bcmp':
    scores[letter] = 3
for letter in 'fhvwy':
    scores[letter] = 4
for letter in 'k':
    scores[letter] = 5
for letter in 'jx':
    scores[letter] = 8
for letter in 'qz':
    scores[letter] = 10


def score(word, db_letters=[], trp_letters=[], multplr=1, scores=scores):
    total = 0
    index = 1
    for char in word.lower():
        if char not in scores:
            raise ValueError(word, 'contains a non-letter character')
        total += scores[char]
        if index in db_letters:
            total += scores[char]
        if index in trp_letters:
            total += 2*scores[char]
        index += 1
    return total*multplr
