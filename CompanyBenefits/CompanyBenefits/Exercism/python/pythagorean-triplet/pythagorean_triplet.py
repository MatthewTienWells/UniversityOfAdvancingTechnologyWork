def triplets_with_sum(number):
    triplets = []
    for y in range(1, (1+number//2)):
        for x in range(1, y):
            ex = x**2 + y**2
            if (number-x-y)**2 == ex:
                triplets.append([x, y, number-x-y])
            elif ex**0.5 + x + y > number:
                exit
    return triplets

def is_triplet(triplet):
    a = triplet[0]
    b = triplet[1]
    c = triplet[2]
    return a < b and b < c and a**2 + b**2 == c**2
