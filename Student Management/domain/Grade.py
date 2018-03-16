from domain.ValidatorException import ValidatorException

class Grade():
    def __init__(self, gradeId, assignment, student, grade):
        self._gradeId = gradeId
        self._assignment = assignment
        self._student = student
        self._grade = grade

    def getId(self):
        return self._gradeId

    def getAss(self):
        return self._assignment

    def getStud(self):
        return self._student

    def getGrade(self):
        return self._grade

    def setAss(self, assignment):
        self._assignment = assignment

    def setStud(self, student):
        self._student = student

    def setGrade(self, grade):
        self._grade = grade

    def __str__(self):
        return "Assignment: " + str(self._assignment) + "\nStudent: " + str(self._student) + "\nGrade: " + str(self._grade)

    def __repr__(self):
        return str(self)

class GradeValidator:
    def validate(self, grade):
        if isinstance(grade, Grade):
            raise TypeError("Not a Grade")
        _errors = []
        try:
            if int(grade) < 1 or int(grade) > 10:
                _errors.append("Invalid grade")
        except TypeError:
            _errors.append("Grade should be a number")
        if len(_errors) > 0:
            raise ValidatorException(_errors)

