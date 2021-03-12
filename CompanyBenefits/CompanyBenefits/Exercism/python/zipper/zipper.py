KEYS = {'value', 'left', 'right'}

class Zipper:
    def __init__(self, tree):
        self.tree = tree
        self.parent = None
        
    @staticmethod
    def from_tree(tree):
        if type(tree) == dict:
            if tree.keys() == KEYS:
                return Zipper(tree)
        raise TypeError('Not a binary tree.')

    def value(self):
        return self.tree['value']

    def set_value(self, new_value=None):
        self.tree['value'] = new_value
        return self

    def left(self):
        new_tree = self.tree['left']
        if type(new_tree) != dict:
            return new_tree
        elif new_tree.keys() != KEYS:
            return new_tree
        new_zip = Zipper.from_tree(new_tree)
        new_zip.parent = self
        return new_zip

    def set_left(self, new_value):
        self.tree['left'] = new_value
        return self

    def right(self):
        new_tree = self.tree['right']
        if type(new_tree) != dict:
            return new_tree
        elif new_tree.keys() != KEYS:
            return new_tree
        new_zip = Zipper.from_tree(new_tree)
        new_zip.parent = self
        return new_zip

    def set_right(self, new_value):
        self.tree['right'] = new_value
        return self

    def up(self):
        return self.parent

    def to_tree(self):
        if self.parent != None:
            return self.parent.to_tree()
        else:
            return self.tree

    def __eq__(self, other):
        return self.tree == other
