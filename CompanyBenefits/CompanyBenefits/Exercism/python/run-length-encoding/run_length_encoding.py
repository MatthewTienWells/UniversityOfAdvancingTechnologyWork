def decode(string):
    digit_str = ''
    uncoded = ''
    for char in string:
        if char.isdigit():
            digit_str += char
        elif digit_str != '':
            uncoded += int(digit_str)*char
            digit_str = ''
        else:
            uncoded += char
    return uncoded


def encode(string):
    coded_string = ''
    reps = 0
    if string == '':
        return ''
    curr_chr = string[0]
    for char in string:
        if char == curr_chr:
            reps += 1
        elif reps > 1:
            coded_string += str(reps) + curr_chr
            curr_chr = char
            reps = 1
        else:
            coded_string += curr_chr
            curr_chr = char
    if reps > 1:
        coded_string += str(reps) + curr_chr
    else:
        coded_string += curr_chr
    return coded_string
