from string import punctuation

def abbreviate(words):
    words = words.replace('-', ' ')
    abbr = ''.join(x.strip(punctuation)[0] for x in words.split(' ') if x != '')
    return abbr.upper()
