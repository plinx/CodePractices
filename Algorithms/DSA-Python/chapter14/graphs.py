__author__ = 'linx'

class Graph(object):

    class Vertex(object):
        __slots__ = "_elem"

        def __init__(self, elem):
            self._elem = elem

        def elem(self):
            return self._elem

        def __hash__(self):
            return hash(id(self))

        pass

    class Edge(object):
        __slots__ = "_u", "_v", "_elem"

        def __init__(self, u, v, elem):
            self._u = u
            self._v = v
            self._elem = elem

        def opposite(self, value):
            return self._v if value == self._u else self._u

        def elem(self):
            return self._elem

        def __hash__(self):
            return hash((self._u, self._v))

        pass

    def __init__(self, directed = False):
        self._outgoing = {}
        self._incoming = {} if directed else self._outgoing

    def is_directed(self):
        return self._incoming != self._outgoing

    def vertex_count(self):
        return len(self._outgoing)

    def vertices(self):
        return self._outgoing.keys()

    def edge_count(self):
        total = sum(len(self._outgoing[k]) for k in self._outgoing)
        return total if self.is_directed() else total / 2

    def edges(self):
        ret = set()
        for secondary_map in self._outgoing.values():
            ret.update(secondary_map.values())
        return ret

    def get_edge(self, u, v):
        #return self._outgoing[u].get(v)
        return self._outgoing[u][v]

    def degree(self, value, outgoing=True):
        adj = self._outgoing if outgoing else self._incoming
        return len(adj[value])

    def incident_edge(self, value, outgoing=True):
        adj = self._outgoing if outgoing else self._incoming
        for edge in adj[value].values():
            yield edge

    def insert_vertex(self, elem=None):
        dest = self.Vertex(elem)
        self._outgoing[dest] = {}
        if self.is_directed():
            self._incoming = {}
        return dest

    def insert_edge(self, u, v, elem=None):
        edge = self.Edge(u, v, elem)
        self._outgoing[u][v] = edge
        self._incoming[v][u] = edge




