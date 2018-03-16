from domain.Grade import Grade
import datetime

class StatisticsController():
    def __init__(self, gradeRepo):
        self._gradeRepo = gradeRepo

    def studentLate(self):
        students = []
        for gr in self._gradeRepo.getAll():
            dl = gr.getAss().getDeadline()
            now = datetime.datetime.now()
            if int(dl[0]) > now.day and int(dl[1]) > now.month:
                students.append(gr.getStud())
        return students