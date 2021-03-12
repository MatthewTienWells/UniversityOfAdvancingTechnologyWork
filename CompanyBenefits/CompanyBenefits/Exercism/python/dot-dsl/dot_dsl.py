NODE, EDGE, ATTR = range(3)


class Node(object):
    def __init__(self, name, attrs=None):
        if attrs == None:
            raise ValueError('No attributes given for Node')
        self.name = name
        self.attrs = attrs

    def __eq__(self, other):
        return self.name == other.name and self.attrs == other.attrs


class Edge(object):
    def __init__(self, src, dst, attrs=None):
        if attrs == None:
            raise ValueError('No attributes given for Edge')
        self.src = src
        self.dst = dst
        self.attrs = attrs

    def __eq__(self, other):
        return (self.src == other.src and
                self.dst == other.dst and
                self.attrs == other.attrs)


class Graph(object):
    def __init__(self, data=[]):
        self.nodes = []
        self.edges = []
        self.attrs = {}
        try:
            for entry in data:
                if type(entry) != tuple:
                    raise TypeError('Argument passed was not a data tuple!')
                elif (entry[0] != EDGE and len(entry) > 3) or len(entry) > 4:
                        raise ValueError('Attribute has too many args.')
                elif entry[0] == NODE:
                    self.nodes.append(Node(*entry[1:]))
                elif entry[0] == EDGE:
                    self.edges.append(Edge(*entry[1:]))
                elif entry[0] == ATTR:
                    self.attrs[entry[1]] = entry[2]
                else:
                    raise ValueError('Data entry unknown.')
        except IndexError:
            raise TypeError('Entry contains invalid arguments.')
