def rebase(input_base, digits, output_base):
    for value in digits:
        if value < 0 or type(value) != int:
            raise ValueError('Only natural numbers allowed.')
        if value >= input_base:
            raise ValueError('Impossible number provided.')
    for value in (input_base, output_base):
        if value < 2 or type(value) != int:
            raise ValueError('Bases must be integers greater than one.')
    b_10_rep = 0
    digits = digits[::-1]
    scale = 0
    for digit in digits:
        b_10_rep += digit*(input_base**scale)
        scale += 1
    out_digits = []
    while b_10_rep > 0:
        out_digits.append(int(b_10_rep%output_base))
        b_10_rep -= b_10_rep % output_base
        b_10_rep /= output_base
    if out_digits == []:
        return [0]
    return out_digits[::-1]
