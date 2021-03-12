def rotate(text, key):
    lower = 'abcdefghijklmnopqrstuvwxyz'
    upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ'
    ntext = ''
    for char in text:
        if char.isupper():
            ntext += upper[(upper.index(char)+key)%26]
        elif char.islower():
            ntext += lower[(lower.index(char)+key)%26]
        else:
            ntext += char
    return ntext
