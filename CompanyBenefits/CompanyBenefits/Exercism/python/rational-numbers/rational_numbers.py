from __future__ import division
from math import gcd

class Rational(object):
    def __init__(self, numer, denom):
        self.numer = numer
        self.denom = denom
        self.reduce()

    def __eq__(self, other):
        return self.numer == other.numer and self.denom == other.denom

    def __repr__(self):
        return '{}/{}'.format(self.numer, self.denom)

    def __add__(self, other):
        self.numer = (self.numer * other.denom) + (other.numer * self.denom)
        self.denom *= other.denom
        self.reduce()
        return self

    def __sub__(self, other):
        self.numer = (self.numer * other.denom) - (other.numer * self.denom)
        self.denom *= other.denom
        self.reduce()
        return self

    def __mul__(self, other):
        self.numer *= other.numer
        self.denom *= other.denom
        self.reduce()
        return self

    def __truediv__(self, other):
        self.numer *= other.denom
        self.denom *= other.numer
        self.reduce()
        return self

    def __abs__(self):
        self.numer = abs(self.numer)
        self.denom = abs(self.denom)
        return self

    def __pow__(self, power):
        if power >= 0:
            self.numer **= power
            self.denom **= power
        else:
            self.numer = self.denom**power
            self.denom = self.numer**power
        return self

    def __rpow__(self, base):
        return (base**self.numer)**(self.denom**-1)

    def reduce(self):
        self.numer = int(self.numer)
        self.denom = int(self.denom)
        if self.denom == 0:
            raise ZeroDivisionError
        div = gcd(self.numer, self.denom)
        self.numer /= div
        self.denom /= div
        if self.denom < 0:
            self.denom *= -1
            self.numer *= -1
