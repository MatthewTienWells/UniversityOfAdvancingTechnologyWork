def recite(start_verse, end_verse):
    gifts = ["twelve Drummers Drumming, ",
        "eleven Pipers Piping, ",
        "ten Lords-a-Leaping, ",
        "nine Ladies Dancing, ",
        "eight Maids-a-Milking, ",
        "seven Swans-a-Swimming, ",
        "six Geese-a-Laying, ",
        "five Gold Rings, ",
        "four Calling Birds, ",
        "three French Hens, ",
        "two Turtle Doves, ",
        "and a Partridge in a Pear Tree."]
    count = ['first', 'second', 'third', 'fourth', 'fifth', 'sixth', 'seventh',
             'eighth', 'ninth', 'tenth', 'eleventh', 'twelfth']
    verses = []
    while start_verse <= end_verse:
        verses.append(verse(count[start_verse-1], gifts[12-start_verse:]))
        start_verse += 1
    return verses
    

def verse(count, gifts):
    string = 'On the ' + count + ' day of Christmas my true love gave to me: '
    if len(gifts) == 1:
        return string + gifts[0][4:]
    return string + ''.join(gifts)
