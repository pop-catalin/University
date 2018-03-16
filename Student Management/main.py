from controller.Controller import Controller
from controller.AssignmentController import *
from controller.StudentController import *
from controller.GradeController import *
from domain.Student import *
from domain.Assignment import *
from repository.Repository import *
from UI.ui import *
from controller.UndoController import *

strepo = Repository()
assrepo = Repository()
grdrepo = Repository()
assvalidator = AssignmentValidator()
stvalidator = StudentValidator()
opList = []

def initStudents():
    strepo.store(Student("1","Ma Rupe","916"))
    strepo.store(Student("2","Tema Asta", "913"))
    strepo.store(Student("3","Foarte Tare", "910"))
    strepo.store(Student("4", "Ioana", "915"))

def initAssignments():
    assrepo.store(Assignment("7","descriere 1","5.6"))
    assrepo.store(Assignment("8","descriere nr 2","12.10"))
    assrepo.store(Assignment("9","descriere 4","13.12"))
    assrepo.store(Assignment("10", "Spelling", "14.12"))

def initGrades():
    grdrepo.store(Grade("5", Assignment("10", "Spelling", "14.12"), Student("4", "Ioana", "915") , "6"))

initStudents()
initAssignments()
initGrades()
undoctrl = UndoController(opList)
stctrl = StudentController(strepo, stvalidator)
assctrl = AssignmentController(assrepo, assvalidator)
grdctrl = GradeController(grdrepo, assrepo, strepo)
ctrl = Controller(stctrl, assctrl, grdctrl, undoctrl)
ui = UI(ctrl, undoctrl)
ui.start()