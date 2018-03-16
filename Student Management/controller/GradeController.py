from domain.Grade import Grade

class GradeController():
    def __init__(self, gradeRepo, assRepo, studRepo):
        self._gradeRepo = gradeRepo
        self._assRepo = assRepo
        self._studRepo = studRepo

    def createGrade(self, gradeId, assId, studId, grade):
        gr = Grade(gradeId, self._assRepo.find(assId), self._studRepo.find(studId), 0)
        self._gradeRepo.store(gr)
        return gr

    def deleteGrade(self, gradeId):
        grade = self._gradeRepo.delete(gradeId)
        return grade

    def createGradeGroup(self, gradeId, assId, group):
        result = []
        for student in self._studRepo.getAll():
            if student.getGroup() == group:
                gr = Grade(gradeId, self._assRepo.find(assId), student,0)
                self._gradeRepo.store(gr)
                result.append(gr)
        return result

    def grade(self, assId, studId, grade):
        for x in self._gradeRepo.getAll():
            if x.getAss().getId() == assId and x.getStud().getId() == studId:
                gr = Grade(x.getId(), self._assRepo.find(assId), self._studRepo.find(studId), grade)
                self._gradeRepo.update(gr)

    def list(self):
        return self._gradeRepo.getAll()