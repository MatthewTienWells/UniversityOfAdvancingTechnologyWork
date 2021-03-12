class Point(object):
    def __init__(self, x, y):
        self.x = None
        self.y = None

    def __eq__(self, other):
        return self.x == other.x and self.y == other.y


class WordSearch(object):
    def __init__(self, puzzle):
        self.len = len(puzzle[0])
        if any(len(line) != self.len for line in puzzle):
            raise ValueError('Puzzle is not a rectangle.')
        self.ht = len(puzzle)
        self.lines = puzzle

    def search(self, word):
        for x in range(self.len):
            for y in range(self.ht):
                if self.lines[y][x] == word[0]:
                    next_let = 1
                    possible_start = Point(x, y)
                    xt = x
                    yt = y
                    for coord in [
                        (-1, -1), (-1, 0), (-1, 1), (0, -1),
                        (0, 1), (1, -1), (1, 0), (1, 1)
                        ]:
                        while (0 <= yt+coord[0] < self.ht and
                            0 <= xt+coord[1] < self.len
                            ):
                            if (self.lines[yt+coord[0]][xt+coord[1]]
                                == word[next_let]
                                ):
                                yt += coord[0]
                                xt += coord[1]
                                next_let += 1
                                if next_let == len(word):
                                    return (possible_start, Point(xt, yt))
                            else:
                                xt = -2
                                yt = -2
                        next_let = 1
                        xt = x
                        yt = y
                            
