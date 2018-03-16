from Board.Board import Board
import random

from Board.ValidatorException import ValidatorException


class Game:
    def __init__(self, board):
        self.__board = board

    def placePlayer(self,l,c,direction,length):
        self.__board.placeShip(l,c,direction,length)

    def placeComputer(self,length):
        directions = ['up', 'down', 'left', 'right']
        l = random.randint(0, 4)
        c = random.randint(5, 9)
        dir = random.choice(directions)
        self.__board.placeShipComputer(l,c,dir,length)

    def attComputer(self):
        l = random.randint(0,4)
        c = random.randint(0,4)
        self.__board.attack(l,c)

    def attPlayer(self,l,c):
        if l < 0 or l > 4 or c < 0 or c > 4:
            raise ValidatorException("Can't hit this tile")
        self.__board.attack(l,c + 5)

    def isWon(self):
        return self.__board.isWon()

    def isLost(self):
        return self.__board.isLost()

    def getBoard(self):
        return self.__board.getBoard()