names = ['Alice', 'Bob', 'Charlie', 'David', 'Eve', 'Fred',  'Ginny', 'Harriet',
         'Ileana', 'Joseph', 'Kincaid', 'Larry']

class Garden(object):
    def __init__(self, diagram, students=names):
        self.windrow, self.inrow = diagram.split('\n')
        students.sort()
        self.students = students
        self.flowers = {'V': 'Violets', 'G': 'Grass', 'R': 'Radishes',
                        'C': 'Clover'}

    def plants(self, student):
        place = self.students.index(student)
        keys = [self.windrow[place*2], self.windrow[place*2+1],
                self.inrow[place*2], self.inrow[place*2+1]]
        return [self.flowers[key] for key in keys]
        
