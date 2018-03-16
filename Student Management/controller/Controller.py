from controller.UndoController import *

class Controller:
    def __init__(self, studentController, assignmentController, gradeController, statisticsController, undoctrl):
        self._studentController = studentController
        self._assignmentController = assignmentController
        self._gradeController = gradeController
        self._statisticsController = statisticsController
        self._undoctrl = undoctrl

    def addStudent(self, studId, name, group, recUndo = True):
        self._studentController.add(studId, name, group)
        if recUndo == True:
            undo = FunctionCall(self.removeStudent, studId, False)
            redo = FunctionCall(self.addStudent, studId, name, group, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def removeStudent(self, studId, recUndo = True):
        x = self._studentController.remove(studId)
        if recUndo == True:
            undo = FunctionCall(self.addStudent, x.getId(), x.getName(), x.getGroup(), False)
            redo = FunctionCall(self.removeStudent, studId, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def updateStudent(self, studId, newName, newGroup, recUndo = True):
        x = self._studentController.updateStud(studId, newName, newGroup)
        if recUndo == True:
            undo = FunctionCall(self.updateStudent, x.getId(), x.getName(), x.getGroup(), False)
            redo = FunctionCall(self.updateStudent, studId, newName, newGroup, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def listStudents(self):
        return self._studentController.list()

    def addAssignment(self,assId, description,deadline, recUndo = True):
        self._assignmentController.add(assId, description, deadline)
        if recUndo == True:
            undo = FunctionCall(self.removeAssignment, assId, False)
            redo = FunctionCall(self.addAssignment, assId, description, deadline, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def removeAssignment(self,assId, recUndo = True):
        x = self._assignmentController.remove(assId)
        if recUndo == True:
            undo = FunctionCall(self.addAssignment, x.getId(), x.getDescription(), x.getDeadline(), False)
            redo = FunctionCall(self.removeAssignment, assId, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def updateAssignment(self, assId, newDesc, newDeadline, recUndo = True):
        x = self._assignmentController.updateAss(assId, newDesc, newDeadline)
        if recUndo == True:
            undo = FunctionCall(self.updateAssignment, assId, x.getDescription(), x.getDeadline(), False)
            redo = FunctionCall(self.updateAssignment, assId, newDesc, newDeadline, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def listAssignments(self):
        return self._assignmentController.list()

    def giveAssignmentStudent(self, gradeId, assId, studId, recUndo = True):
        self._gradeController.createGrade(gradeId, assId, studId, 0)
        if recUndo == True:
            undo = FunctionCall(self.deleteAssignmentStudent, gradeId, False)
            redo = FunctionCall(self.giveAssignmentStudent, gradeId, assId, studId, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def giveAssignmentGroup(self,gradeId, assId, group):
        self._gradeController.createGradeGroup(gradeId, assId, group)

    def deleteAssignmentStudent(self, gradeId, recUndo = True):
        x = self._gradeController.deleteGrade(gradeId)
        if recUndo == True:
            undo = FunctionCall(self.giveAssignmentStudent, gradeId, x.getAss().getId(), x.getStud().getId(), False)
            redo = FunctionCall(self.deleteAssignmentStudent, gradeId, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def giveGrade(self, assId, studId, grade, recUndo = True):
        self._gradeController.grade(assId,studId,grade)
        if recUndo == True:
            undo = FunctionCall(self.giveGrade, assId, studId, 0, False)
            redo = FunctionCall(self.giveGrade, assId, studId, grade, False)
            op = Operation(redo, undo)
            self._undoctrl.recordOperation(op)

    def listGrades(self):
        return self._gradeController.list()

    def isLate(self):
        return self._statisticsController.studentLate()