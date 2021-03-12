class BowlingGame(object):
    def __init__(self):
        self.frame = 0
        self.roll_num = 0
        self.rolls = {}
        self.abs_rolls = {}

    def roll(self, pins):
        if pins not in range(11) or type(pins) != int:
            raise ValueError('Liar.')
        if self.frame < 18:
            if self.frame % 2 == 0:
                if pins == 10:
                    self.rolls[self.roll_num] = 'strike'
                    self.frame += 1
                else:
                    self.rolls[self.roll_num] = pins
            else:
                last = self.rolls[self.roll_num-1]
                if pins + last > 10:
                    raise ValueError('Liar')
                if pins + last == 10:
                    self.rolls[self.roll_num] = 'spare'
                else:
                    self.rolls[self.roll_num] = pins
        elif self.frame < 21:
            if self.frame == 18:
                self.rolls[self.roll_num] = pins
            if self.frame == 19:
                last = self.rolls[self.roll_num-1] % 10
                if pins + last > 10:
                    raise ValueError('Liar')
                self.rolls[self.roll_num] = pins
            if self.frame == 20:
                last = (self.rolls[self.roll_num-1]
                        + self.rolls[self.roll_num-2]) % 10
                if pins + last > 10:
                    raise ValueError('Liar')
                if (self.rolls[self.roll_num-1]
                    + self.rolls[self.roll_num-2]) < 10:
                    raise ValueError('The game\'s over.')
                self.rolls[self.roll_num] = pins
        else:
            raise ValueError('The game\'s over.')
        self.frame += 1
        self.abs_rolls[self.roll_num] = pins
        self.roll_num += 1

    def score(self):
        if self.frame == 20:
            if (self.rolls[self.roll_num-2] == 'strike'
                or self.rolls[self.roll_num-1] == 'spare'
                ):
                raise ValueError('Your game hasn\'t ended.')
        elif self.frame < 20:
            raise ValueError('Your game hasn\'t ended.')
        total = 0
        while self.roll_num > 0:
            self.roll_num -= 1
            if self.rolls[self.roll_num] == 'strike':
                strike = (10
                          + self.abs_rolls[self.roll_num+1]
                          + self.abs_rolls[self.roll_num+2])
                self.rolls[self.roll_num] = strike
            elif self.rolls[self.roll_num] == 'spare':
                self.rolls[self.roll_num] = (self.abs_rolls[self.roll_num]
                                             + self.abs_rolls[self.roll_num+1])
        for key in self.rolls:
            total += self.rolls[key]
        return total
