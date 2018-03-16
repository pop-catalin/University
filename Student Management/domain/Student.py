from domain.ValidatorException import ValidatorException

class Student():
    def __init__(self, studId, name, group):
        self._studId = studId
        self._name = name
        self._group = group

    def getId(self):
        return self._studId

    def getName(self):
        return self._name

    def getGroup(self):
        return self._group

    def setName(self, name):
        self._name = name

    def setGroup(self, group):
        self._group = group

    def __eq__(self, x):
        if isinstance(x, Student) == False:
            return False
        return self.getId() == x.getId()

    def __str__(self):
        return "ID: " + str(self.getId()) + ", Name: " + self._name + ", Group: " + self._group

    def __repr__(self):
        return str(self)

class StudentValidator:
    def __init__(self):
        self._errors = ""

    def _studIdValid(self, studId):
        for i in range(len(studId)):
            if studId[i] < '0' or studId > '9':
                return False
        return True

    def _studNameValid(self, name):
        nume = name.split(" ")
        for i in range(len(nume)):
            if nume[i][0] < 'A' or nume[i][0] > 'Z':
                return False
            for j in range(1, len(nume[i])):
                if nume[i][j] < 'a' or nume[i][j] > 'z':
                    return False
        return True

    def _studGroupValid(self, group):
        for i in range(len(group)):
            if group[i] < '0' or group[i] > '9':
                return False
        return True

    def validate(self, student):
        if isinstance(student,Student) == False:
            raise TypeError("Can only validate Student objects")
        _errors =[]
        if (len(student.getId())) == 0:
            _errors.append("No ID given")
        if (len(student.getGroup())) == 0:
            _errors.append("No group given")
        if (len(student.getName())) == 0:
            _errors.append("No name given")
        if self._studIdValid(student.getId()) == False:
            _errors.append("ID not valid")
        if self._studGroupValid(student.getGroup()) == False:
            _errors.append("Group not valid")
        if self._studNameValid(student.getName()) == False:
            _errors.append("Name not valid")
        if len(_errors) > 0:
            raise ValidatorException(_errors)
        return True

