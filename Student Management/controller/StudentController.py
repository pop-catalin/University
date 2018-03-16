from domain.Student import Student

class StudentController:
    def __init__(self, repository, validator):
        self.__repository = repository
        self.__validator = validator

    def add(self, studId, name, group):
        student = Student(studId, name, group)
        self.__validator.validate(student)
        self.__repository.store(student)
        return student

    def remove(self, studId):
        student = self.__repository.delete(studId)
        return student

    def updateStud(self,studId, newName, newGroup):
        student = Student(studId, newName, newGroup)
        self.__validator.validate(student)
        student = self.__repository.update(student)
        return student

    def getStudCount(self):
        return(len(self.__repository))

    def list(self):
        return self.__repository.getAll()
