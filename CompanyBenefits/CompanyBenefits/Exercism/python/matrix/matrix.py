class Matrix(object):
    def __init__(self, matrix_string):
        rows = [*matrix_string.split('\n')]
        self.matrix = []
        for row in rows:
            self.matrix.append([*map(int, row.split(' '))])

    def row(self, index):
        return self.matrix[index-1]

    def column(self, index):
        col = []
        for row in self.matrix:
            col.append(row[index-1])
        return col

