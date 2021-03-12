class Luhn(object):
    def __init__(self, card_num):
        self.num = ''.join(card_num.split(' '))
        try:
            check = int(self.num)
            self.val = self.validate()
        except ValueError:
            self.val = False
            
    def valid(self):
        return self.val

    def validate(self):
        luhn = str(self.num)
        print(luhn)
        if len(luhn) < 2:
            return False
        check =(
            sum(2*int(x) - (9*(2*int(x)//10)) for x in luhn[-2::-2])
            + sum(int(y) for y in luhn[-1::-2])
            )
        return check % 10 == 0
            
