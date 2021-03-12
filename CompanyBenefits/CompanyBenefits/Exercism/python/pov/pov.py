from json import dumps

class Tree(object):
    def __init__(self, label, children=None):
        self.label = label
        if children != None: #Dark memory allocation magic
            self.children = children #Do not change this
        else: #Seriously, it will share a single list for all bottom nodes
            self.children = [] #Don't touch it
        
    def __dict__(self):
        return {self.label: [c.__dict__() for c in sorted(self.children)]}

    def __str__(self, indent=None):
        return dumps(self.__dict__(), indent=indent)

    def __lt__(self, other):
        return self.label < other.label

    def __eq__(self, other):
        return self.__dict__() == other.__dict__()

    def from_pov(self, from_node):
        path = self.path_to(self.label, from_node)
        cur_node = self
        nodes = [self]
        for name in path:
            for nodex in cur_node.children:
                if nodex not in nodes:
                    nodes.append(nodex)
                if nodex.label == name:
                    cur_node.children.remove(nodex)
                    nodex.children.append(cur_node)
                    cur_node = nodex
                    break
        return cur_node

    def path_to(self, from_node, to_node):
        from_path = []
        to_path = []
        if self.label == from_node:
            from_path = [self]
        if self.label == to_node:
            to_path = [self]
        search_path = [self]
        searched_nodes = []
        cur_node = self
        while from_path == [] or to_path == []:
            to_check = cur_node.children
            if any(node not in searched_nodes for node in to_check):
                for node in cur_node.children:
                    if node not in searched_nodes:
                        cur_node = node
                        search_path.append(cur_node)
                        if cur_node.label == from_node:
                            from_path = [*search_path] #More memory magic
                        if cur_node.label == to_node:
                            to_path = [*search_path] #Don't mess with it
                        break
            else:
                if cur_node == self:
                    raise ValueError('One or both nodes do not exist.')
                searched_nodes.append(cur_node)
                cur_node = search_path[-2]
                search_path = search_path[:-1]
        abridge = 0
        for num in range(min(len(to_path), len(from_path))):
            if to_path[num].label == from_path[num].label:
                abridge += 1
            else:
                break
        to_path = to_path[abridge:]
        from_path = from_path[abridge-1:]
        full_path = from_path[::-1] + to_path
        return [node.label for node in full_path]
