from controller.Controller import Controller
from controller.AssignmentController import *
from controller.StudentController import *
from controller.GradeController import *
from controller.StatisticsController import *
from domain.Student import *
from domain.Assignment import *
from repository.Repository import *
from UI.ui import *
from controller.UndoController import *
from repository.StudentCSVFileRepository import StudCSVFileRepository
from repository.AssignmentCSVFileRepository import AssCSVFileRepository
from repository.GradesCSVFileRepository import GradeCSVFileRepository
from repository.PickleFileRepository import PickleFileRepository

#SETTINGS_FILE = "settings_text.properties"
SETTINGS_FILE = "settings_binary.properties"

def readSettings():
    f = open(SETTINGS_FILE, "r")
    lines = f.read().split("\n")
    settings = {}

    for line in lines:
        setting = line.split("=")
        if len(setting) > 1:
            settings[setting[0]] = setting[1]
    f.close()
    return settings

settings = readSettings()

studRepo = None
assRepo = None
grdRepo = None

if 'CSV' == settings['repository']:
    studRepo = StudCSVFileRepository(settings['students'])
    assRepo = AssCSVFileRepository(settings['assignments'])
    grdRepo = GradeCSVFileRepository(settings['assignments'],settings['students'])

if 'binary' == settings['repository']:
    studRepo = PickleFileRepository(settings['students'])
    assRepo = PickleFileRepository(settings['assignments'])
    grdRepo = PickleFileRepository(settings['grades'])

assValidator = AssignmentValidator()
studValidator = StudentValidator()
opList = []
undoCtrl = UndoController(opList)
studCtrl = StudentController(studRepo, studValidator)
assCtrl = AssignmentController(assRepo, assValidator)
grdCtrl = GradeController(grdRepo, assRepo, studRepo)
statCtrl = StatisticsController(grdRepo)
ctrl = Controller(studCtrl, assCtrl, grdCtrl,statCtrl, undoCtrl)
ui = UI(ctrl,undoCtrl)
ui.start()