from repository.Repository import Repository
from domain.Student import Student

class StudCSVFileRepository(Repository):
    def __init__(self,fileName = "students.txt"):
        Repository.__init__(self)
        self.__fName = fileName
        self.__loadFromFile()

    def store(self, student):
        Repository.store(self, student)
        self.__storeToFile()

    def delete(self, studId):
        Repository.delete(self,studId)
        self.__storeToFile()

    def update(self, newStud):
        Repository.update(self, newStud)
        self.__storeToFile()

    def __loadFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                params = line.split(",")
                stud = Student(params[0], params[1], params[2])
                Repository.store(self, stud)
                line = f.readline().strip()
        except IOError:
            pass
        finally:
            f.close()

    def __storeToFile(self):
        f = open(self.__fName, "w")
        students = Repository.getAll(self)
        for stud in students:
            strf = str(stud.getId()) + "," + str(stud.getName()) + "," + str(stud.getGroup()) + "\n"
            f.write(strf)
        f.close()