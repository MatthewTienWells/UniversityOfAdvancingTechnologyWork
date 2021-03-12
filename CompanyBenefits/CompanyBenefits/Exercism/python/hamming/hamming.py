def distance(strand_a, strand_b):
    if len(strand_a) != len(strand_b):
        raise ValueError('Length of strands is different!')
    ham = 0
    for ind in range(len(strand_a)):
        if strand_a[ind] != strand_b[ind]:
            ham += 1
    return ham
