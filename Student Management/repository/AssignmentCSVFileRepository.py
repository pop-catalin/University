from repository.Repository import Repository
from domain.Assignment import Assignment

class AssCSVFileRepository(Repository):
    def __init__(self,fileName = "assignments.txt"):
        Repository.__init__(self)
        self.__fName = fileName
        self.__loadFromFile()

    def store(self, assignment):
        Repository.store(self, assignment)
        self.__storeToFile()

    def delete(self, assId):
        Repository.delete(self,assId)
        self.__storeToFile()

    def update(self, newAss):
        Repository.update(self, newAss)
        self.__storeToFile()

    def __loadFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                params = line.split(",")
                ass = Assignment(params[0], params[1], params[2])
                Repository.store(self, ass)
                line = f.readline().strip()
        except IOError:
            pass
        finally:
            f.close()

    def __storeToFile(self):
        f = open(self.__fName, "w")
        assignments = Repository.getAll(self)
        for ass in assignments:
            strf = str(ass.getId()) + "," + str(ass.getDescription()) + "," + str(ass.getDeadline()) + "\n"
            f.write(strf)
        f.close()