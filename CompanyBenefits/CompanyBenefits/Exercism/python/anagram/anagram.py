def find_anagrams(word, candidates):
    dic = char_count(word.lower())
    anagrams = []
    for string in candidates:
        lstring = string.lower()
        temp_dic = dic.copy()
        try:
            if lstring == word.lower():
                raise KeyError
            for char in lstring:
                temp_dic[char] -= 1
            for key in temp_dic:
                if temp_dic[key] != 0:
                    raise KeyError
            anagrams.append(string)
        except KeyError:
            pass
    return anagrams

def char_count(string):
    dic = {}
    for char in string:
        if char not in dic:
            dic[char] = 1
        else:
            dic[char] += 1
    return dic
