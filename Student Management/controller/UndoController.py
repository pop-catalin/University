class UndoController:
    def __init__(self, opList):
        self._index = -1
        self._opList = opList

    def recordOperation(self, op):
        self._opList = self._opList[0:self._index + 1]
        self._opList.append(op)
        self._index += 1

    def undo(self):
        if self._index != -1:
            self._opList[self._index].undo()
            self._index -= 1
            return True
        else:
            return False

    def redo(self):
        if self._index != len(self._opList) - 1:
            self._index += 1
            self._opList[self._index].redo()
            return True
        else:
            return False

class FunctionCall:
    def __init__(self, functionRef, *parameters):
        self._functionRef = functionRef
        self._parameters = parameters

    def call(self):
        self._functionRef(*self._parameters)

class Operation:
    def __init__(self, functionDo, functionUndo):
        self._functionDo = functionDo
        self._functionUndo = functionUndo

    def undo(self):
        self._functionUndo.call()

    def redo(self):
        self._functionDo.call()