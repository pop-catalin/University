from repository.Repository import Repository
from domain.Grade import Grade

class GradeCSVFileRepository(Repository):
    def __init__(self, assRepo, studRepo, fileName="grades.txt"):
        Repository.__init__(self)
        self.__assRepo = assRepo
        self.__studRepo = studRepo
        self.__fName = fileName
        self.__loadFromFile()

    def store(self, grade):
        Repository.store(self, grade)
        self.__storeToFile()

    def update(self, newGrade):
        Repository.update(self, newGrade)
        self.__storeToFile()

    def __loadFromFile(self):
        try:
            f = open(self.__fName, "r")
            line = f.readline().strip()
            while line != "":
                params = line.split(",")
                gradeId = params[0]
                assId =  params[1]
                studId = params[2]
                grade = params[3]
                ass = self.__assRepo.find(assId)
                stud = self.__studRepo.find(studId)
                gr = Grade(gradeId, ass, stud, grade)
                Repository.store(self,gr)
                line = f.readline().strip()
        except IOError:
            pass
        finally:
            f.close()

    def __storeToFile(self):
        f = open(self.__fName, "w")
        grades = Repository.getAll(self)
        for gr in grades:
            strf = str(gr.getId()) + "," + str(gr.getAss().getId()) + "," + str(gr.getStud().getId()) + "," + str(gr.getGrade()) + "\n"
            f.write(strf)
        f.close