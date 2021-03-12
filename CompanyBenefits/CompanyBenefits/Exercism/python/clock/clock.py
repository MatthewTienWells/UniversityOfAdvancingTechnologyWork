class Clock(object):
    def __init__(self, hour, minute):
        self.hour = 0
        self.minute = 0
        minute += 60*hour
        self.__add__(minute)

    def __repr__(self):
        return ('0' + str(self.hour))[-2:] + ':' + ('0' + str(self.minute))[-2:]

    def __eq__(self, other):
        return self.hour == other.hour and self.minute == other.minute

    def __add__(self, minutes):
        minutes = minutes % 1440
        self.minute += minutes
        self.hour += self.minute // 60
        self.minute %= 60
        self.hour %= 24
        return self

    def __sub__(self, minutes):
        return self.__add__(-minutes)
        
