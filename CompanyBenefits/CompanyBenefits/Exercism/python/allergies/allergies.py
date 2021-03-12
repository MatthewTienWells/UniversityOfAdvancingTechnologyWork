class Allergies(object):

    def __init__(self, score):
        x = 0
        self.codes = [x for x in range(8) if ((score % 2**(x+1)) >= 2**x)]
        self.allergydict = {
            0:'eggs',
            1:'peanuts',
            2:'shellfish',
            3:'strawberries',
            4:'tomatoes',
            5:'chocolate',
            6:'pollen',
            7:'cats'
            }

    def allergic_to(self, item):
        return item in self.lst

    @property
    def lst(self):
        return [self.allergydict[x] for x in self.codes]
