def response(hey_bob):
    alpha = 'QWERTYUIOPASDFGHJKLZXCVBNM'
    hey_bob = hey_bob.strip('\t\n\r ')
    if hey_bob == '':
        return 'Fine. Be that way!'
    elif hey_bob == hey_bob.upper() and any(cha in hey_bob for cha in alpha):
        if hey_bob[-1] == '?':
            return 'Calm down, I know what I\'m doing!'
        else:
            return 'Whoa, chill out!'
    elif hey_bob[-1] == '?':
        return 'Sure.'
    else:
        return 'Whatever.'
