from bisect import insort

class School(object):
    def __init__(self):
        self.students = {}
        for num in range(12):
            self.students[num] = []

    def add_student(self, name, grade):
        insort(self.students[grade], name)
            
    def roster(self):
        student_lst = []
        for num in range(12):
            student_lst.extend(self.students[num])
        return student_lst
            

    def grade(self, grade_number):
        return self.students[grade_number]
