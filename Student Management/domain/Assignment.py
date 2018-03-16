from domain.ValidatorException import ValidatorException

class Assignment():
    def __init__(self, assignmentId, description, deadline):
        self._assignmentId = assignmentId
        self._description = description
        self._deadline = deadline

    def getId(self):
        return self._assignmentId

    def getDescription(self):
        return self._description

    def getDeadline(self):
        return self._deadline

    def setAssignmentId(self, assId):
        self._assignmentId = assId

    def setDescription(self, description):
        self._description = description

    def setDeadline(self, deadline):
        self._deadline = deadline

    def __eq__(self, x):
        if isinstance(x, Assignment) == False:
            return False
        return self._assignmentId == x._assignmentId

    def __str__(self):
        return "ID: " + str(self.getId()) + ", Description: " + str(self.getDescription()) + ", Deadline: " + str(self.getDeadline())

    def __repr__(self):
        return str(self)

class AssignmentValidator:
    def __init__(self):
        self._errors = ""

    def _assIdValid(self, assId):
        for i in range(len(assId)):
            if assId[i] < '0' or assId[i] > '9':
                return False
        return True

    def _descriptionValid(self, description):
        for i in range(len(description)):
            if description[i] == ",":
                return False
        return True

    def _deadlineValid(self,deadline):
        dl = deadline.split('.')
        if len(dl) != 2:
            return False
        try:
            if int(dl[0]) > 31 or int(dl[0]) < 1:
                return False
            if int(dl[1]) > 12 or int(dl[0]) < 1:
                return False
        except TypeError:
            return False
        return True

    def validate(self, assignment):
        if isinstance(assignment, Assignment) == False:
            raise TypeError("Can only validate Assignment objects")
        _errors = []
        if len(assignment.getId()) == 0:
            _errors.append("No ID provided")
        if len(assignment.getDeadline()) == 0:
            _errors.append("No deadline provided")
        if len(assignment.getDescription()) == 0:
            _errors.append("No description provided")
        if self._assIdValid(assignment.getId()) == False:
            _errors.append("Invalid ID")
        if self._deadlineValid(assignment.getDeadline()) == False:
            _errors.append("Invalid Deadline")
        if self._descriptionValid(assignment.getDescription()) == False:
            _errors.append("Invalid Description")
        if len(_errors) > 0:
            raise ValidatorException(_errors)
        return True