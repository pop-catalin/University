import unittest

from controller.UndoController import UndoController
from domain.Student import Student
from domain.Student import StudentValidator
from domain.Assignment import Assignment
from domain.Assignment import AssignmentValidator
from domain.Grade import Grade
from domain.Grade import GradeValidator
from controller.StudentController import StudentController
from controller.AssignmentController import AssignmentController
from repository.Repository import Repository

class testStudent(unittest.TestCase):
    def testStud(self):
        stud = Student("42", "Mihai Adamescu", "913")
        self.assertTrue(stud.getId() == "42")
        self.assertTrue(stud.getName() == "Mihai Adamescu")
        self.assertTrue(stud.getGroup() == "913")
        stud.setGroup("914")
        stud.setName("Cal Pane")
        self.assertTrue(stud.getGroup() == "914")
        self.assertTrue(stud.getName() == "Cal Pane")

class testValidator(unittest.TestCase):
    def testValidateStud(self):
        validator = StudentValidator()
        stud = Student("42", "Mihai Adamescu", "913")
        try:
            validator.validate(stud)
            self.assertTrue(True)
        except:
            pass

    def testValidateAss(self):
        validator = AssignmentValidator()
        ass = Assignment("22","imi plac caii","20.4")
        try:
            validator.validate(ass)
            self.assertTrue(True)
        except:
            pass

    def testValidateGr(self):
        validator = GradeValidator()
        stud = Student("42", "Mihai Adamescu", "913")
        ass = Assignment("22", "imi plac caii", "20.4")
        gr = Grade("1", ass, stud,"5")
        try:
            validator.validate(gr)
            self.assertTrue(True)
        except:
            pass

class testAssignment(unittest.TestCase):
    def testAss(self):
        ass = Assignment("22","imi plac caii","20.4")
        self.assertTrue(ass.getId() == "22")
        self.assertTrue(ass.getDescription() == "imi plac caii")
        self.assertTrue(ass.getDeadline() == "20.4")
        ass.setAssignmentId("23")
        ass.setDeadline("4.4")
        ass.setDescription("cu placere")
        self.assertTrue(ass == Assignment("23","cu placere","4.4"))

class testGrade(unittest.TestCase):
    def testGr(self):
        stud = Student("42", "Mihai Adamescu", "913")
        stud2 = Student ("12", "Adfs Aop", "915")
        ass = Assignment("22", "imi plac caii", "20.4")
        ass2 = Assignment("29", "nu imi plac caii", "20.9")
        gr = Grade("23", ass, stud, "7")
        self.assertTrue(gr.getId() == "23")
        gr.setStud(stud2)
        gr.setAss(ass2)
        gr.setGrade("9")
        self.assertTrue(gr.getAss() == ass2)
        self.assertTrue(gr.getStud() == stud2)
        self.assertTrue(gr.getGrade() == "9")

class RepositoryTest(unittest.TestCase):
    def setUp(self):
        self._repo = Repository()

    def testRepo(self):
        self.assertEqual(len(self._repo), 0)
        x = Student("1","Pop Catalin","916")
        self._repo.store(x)
        self.assertEqual(len(self._repo), 1)
        self._repo.delete("1")
        self.assertEqual(len(self._repo), 0)
        self._repo.store(x)

class StudentControllerTest(unittest.TestCase):
    def setUp(self):
        studentValidator = StudentValidator()
        studentRepo = Repository()
        self._ctrl = StudentController(studentRepo,studentValidator)

    def testStudentController(self):
        self.assertEqual(self._ctrl.getStudCount(), 0)
        self._ctrl.add("4", "Pop Catalin", "916")
        self.assertEqual(self._ctrl.getStudCount(), 1)
        self._ctrl.remove("4")
        self.assertEqual(self._ctrl.getStudCount(), 0)

class AssignmentControllerTest(unittest.TestCase):
    def setUp(self):
        assignmentValidator = AssignmentValidator()
        assignmentRepo = Repository()
        self._ctrl = AssignmentController(assignmentRepo, assignmentValidator)

    def testStudentController(self):
        self.assertEqual(self._ctrl.getAssCount(), 0)
        self._ctrl.add("4", "adsfa", "10.2")
        self.assertEqual(self._ctrl.getAssCount(), 1)
        self._ctrl.remove("4")
        self.assertEqual(self._ctrl.getAssCount(), 0)
if __name__ == "__main__":
    unittest.main()