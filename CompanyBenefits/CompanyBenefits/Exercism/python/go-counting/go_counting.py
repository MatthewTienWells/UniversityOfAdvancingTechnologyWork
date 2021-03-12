NONE = 0
WHITE = 1
BLACK = 2

class Board:
    """Count territories of each player in a Go game

    Args:
        board (list[str]): A two-dimensional Go board
    """

    def __init__(self, board):
        self.data = []
        for line in board:
            row = []
            for char in line:
                if char == ' ':
                    row.append(None)
                elif char == 'W':
                    row.append(1)
                else:
                    row.append(2)
            self.data.append(row)
        self.cols = len(self.data[0])
        self.rows = len(self.data)

    def territory(self, x, y):
        """Find the owner and the territories given a coordinate on
           the board

        Args:
            x (int): Column on the board
            y (int): Row on the board

        Returns:
            (str, set): A tuple, the first element being the owner
                        of that area.  One of "W", "B", "".  The
                        second being a set of coordinates, representing
                        the owner's territories.
        """
        crawl_zone = set()
        to_check = [(x,y)]
        curr_owner = None
        if x not in range(self.cols) or y not in range(self.rows):
            raise ValueError('Coordinate', str(x), str(y), ' not on board', str(self.data))
        if self.data[y][x] != None:
            return 0, set()
        while len(to_check) > 0:
            x = to_check[0][0]
            y = to_check[0][1]
            for cord in [(x+1, y), (x,y+1), (x-1,y), (x,y-1)]:
                if cord[0] in range(self.cols) and cord[1] in range(self.rows):
                    if cord not in crawl_zone:
                        owner = self.data[cord[1]][cord[0]]
                        if curr_owner != owner and owner:
                            if curr_owner != None:
                                curr_owner = 0
                            else:
                                curr_owner = owner
                        if owner == None:
                            to_check.append(cord)
            to_check = to_check[1:]
            crawl_zone.add((x,y))
        if curr_owner == None:
            curr_owner = 0
        return(curr_owner, crawl_zone)

    def territories(self):
        """Find the owners and the territories of the whole board

        Args:
            none

        Returns:
            dict(str, set): A dictionary whose key being the owner
                        , i.e. "W", "B", "".  The value being a set
                        of coordinates owned by the owner.
        """
        crawled = set()
        territors = {0:set(),1:set(),2:set()}
        x = 0
        y = 0
        for row in self.data:
            for point in row:
                if (x, y) not in crawled:
                    owner, terr = self.territory(x, y)
                    crawled.update(terr)
                    territors[owner].update(terr)
                x += 1
            y += 1
            x = 0
        return territors
