__author__ = 'linx'

from collections import MutableMapping

class MapBase(MutableMapping):
    class _Item(object):
        __slots__ = "_key", "_value"
        def __init__(self, key, value):
            self._key = key
            self._value = value

        def __eq__(self, other):
            return self._key == other._key

        def __ne__(self, other):
            return not (self == other)

        def __lt__(self, other):
            return self._key < other._key


class UnsortedTebleMap(MapBase):
    def __init__(self):
        self._table = []

    def __getitem__(self, key):
        for item in self._table:
            if key == item._key:
                return item._value
            raise KeyError("Key error : " + repr(key))

    def __setitem__(self, key, value):
        for item in self._table:
            if key == item._key:
                item._value = value
                return
        self._table.append(self._Item(key, value))

    def __delitem__(self, key):
        for j in range(len(self._table)):
            if key == self._table[j]._key:
                self._table.pop(j)
                return
        raise KeyError("Key error : " + repr(key))

    def __len__(self):
        return len(self._table)

    def __iter__(self):
        for item in self._table:
            yield item._key




