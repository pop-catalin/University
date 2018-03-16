from controller.Controller import Controller

class UI:
    def __init__(self, controller, undoctrl):
        self._controller = controller
        self._undoctrl = undoctrl

    def readCommand(self):
        cmd = input(">>")
        if cmd.find(" ") == -1:
            self._command = cmd
            self._params = ""
        else:
            self._command = cmd[:cmd.find(" ")]
            self._params = cmd[cmd.find(" "):]
            self._params = self._params.strip()
            self._params = self._params.split(",")

    def start(self):
        while True:
            try:
                self.readCommand()
                self.checkParams()
                if self._command == "addStudent":
                    self._controller.addStudent(self._params[0], self._params[1], self._params[2])
                elif self._command == "removeStudent":
                    self._controller.removeStudent(self._params[0])
                elif self._command == "updateStudent":
                    self._controller.updateStudent(self._params[0], self._params[1], self._params[2])
                elif self._command == "listStudents":
                    self.printList(self._controller.listStudents())
                elif self._command == "addAssignment":
                    self._controller.addAssignment(self._params[0], self._params[1], self._params[2])
                elif self._command == "removeAssignment":
                    self._controller.removeAssignment(self._params[0])
                elif self._command == "updateAssignment":
                    self._controller.updateAssignment(self._params[0], self._params[1], self._params[2])
                elif self._command == "listAssignments":
                    self.printList(self._controller.listAssignments())
                elif self._command == "giveAssignment" and self._params[2] == "student":
                    self._controller.giveAssignmentStudent(self._params[0], self._params[1], self._params[3])
                elif self._command == "giveAssignment" and self._params[2] == "group":
                    self._controller.giveAssignmentGroup(self._params[0], self._params[1], self._params[3])
                elif self._command == "giveGrade":
                    self._controller.giveGrade(self._params[0], self._params[1], self._params[2])
                elif self._command == "listGrades":
                    self.printList(self._controller.listGrades())
                elif self._command == "undo":
                    self._undoctrl.undo()
                elif self._command == "redo":
                    self._undoctrl.redo()
                elif self._command == "late":
                    self.printList(self._controller.isLate())
                elif self._command == "exit":
                    break
                else:
                    print("Invalid command")
            except ValueError as ve:
                print(ve)

            except TypeError as te:
                print(te)

            except Exception as ee:
                print(ee)



    def printList(self,lst):
        for x in lst:
            print(x)

    def checkParams(self):
        if self._command == "addStudent" and len(self._params) != 3:
            raise TypeError("Invalid number of parameters!")
        if self._command == "removeStudent" and len(self._params) != 1:
            raise TypeError("Invalid number of parameters!")
        if self._command == "updateStudent" and len(self._params) != 3:
            raise TypeError("Invalid number of parameters!")
        if self._command == "listStudents" and len(self._params) != 0:
            raise TypeError("Invalid number of parameters!")
        if self._command == "addAssignment" and len(self._params) != 3:
            raise TypeError("Invalid number of parameters!")
        if self._command == "removeAssignment" and len(self._params) != 1:
            raise TypeError("Invalid number of parameters!")
        if self._command == "updateAssignment" and len(self._params) != 3:
            raise TypeError("Invalid number of parameters!")
        if self._command == "listAssignments" and len(self._params) != 0:
            raise TypeError("Invalid number of parameters!")
        if self._command == "giveAssignment" and len(self._params) != 4:
            raise TypeError("Invalid number of parameters!")
        if self._command == "giveGrade" and len(self._params) != 3:
            raise TypeError("Invalid number of parameters!")
        if self._command == "listGrades" and len(self._params) != 0:
            raise TypeError("Invalid number of parameters!")
        if self._command == "undo" and len(self._params) != 0:
            raise TypeError("Invalid number of parameters!")
        if self._command == "redo" and len(self._params) != 0:
            raise TypeError("Invalid number of parameters!")