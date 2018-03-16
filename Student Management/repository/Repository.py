class Repository:
    def __init__(self):
        self._objects = []

    def store(self, object):
        self._objects.append(object)
        return object

    def update(self, object):
        x = self.find(object.getId())
        i = self._objects.index(x)
        self._objects.remove(x)
        self._objects.insert(i, object)
        return x

    def find(self, theId):
        for x in self._objects:
            if theId == x.getId():
                return x
        return None

    def delete(self, theId):
        object = self.find(theId)
        self._objects.remove(object)
        return object

    def getAll(self):
        return self._objects

    def __len__(self):
        return len(self._objects)

    def __str__(self):
        x = ""
        for i in self._objects:
            x += str(i)
            x += "\n"
        return x