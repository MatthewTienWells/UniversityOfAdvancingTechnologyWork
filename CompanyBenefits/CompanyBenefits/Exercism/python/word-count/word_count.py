def count_words(sentence):
    sentence = sentence.lower()
    wtspc = '\n\t,.:;_'
    sentence = ''.join(list(filter(valid, sentence)))
    for char in wtspc:
        sentence = sentence.replace(char, ' ')
    words = {}
    for word in sentence.split(' '):
        word = word.strip('\'')
        if word in words:
            words[word] += 1
        elif word != '':
            words[word] = 1
    return words
    


def valid(char):
    alph = '1234567890qwertyuiopasdfghjklzxcvbnm\' \n\t,:;._'
    return char in alph
