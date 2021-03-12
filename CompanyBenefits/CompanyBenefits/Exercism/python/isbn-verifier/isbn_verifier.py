def is_valid(isbn):
    isbn = ''.join(isbn.split('-'))
    if len(isbn) != 10:
        return False
    if isbn[-1] == 'X':
        checksum = 10
    elif isbn[-1] in '0123456789':
        checksum = int(isbn[-1])
    else:
        return False
    isbn = isbn[-2::-1]
    try:
        checksum += sum([int(x)*int(y) for x, y, in zip(isbn, range(2,11))])    except ValueError:
        return False
    return checksum % 11 == 0


