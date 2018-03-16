from domain.Assignment import Assignment

class AssignmentController:
    def __init__(self, repository, validator):
        self.__repository = repository
        self.__validator = validator

    def add(self, assId, description, deadline):
        assignment = Assignment(assId, description, deadline)
        self.__validator.validate(assignment)
        self.__repository.store(assignment)
        return assignment

    def remove(self, assId):
        assignment = self.__repository.delete(assId)
        return assignment

    def updateAss(self, assId, newDesc, newDeadline):
        assignment = Assignment(assId, newDesc, newDeadline)
        self.__validator.validate(assignment)
        assignment = self.__repository.update(assignment)
        return assignment

    def getAssCount(self):
        return len(self.__repository)

    def list(self):
        return self.__repository.getAll()