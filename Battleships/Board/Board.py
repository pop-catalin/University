from Board.ValidatorException import ValidatorException

class Square:
    def __init__(self,x,y):
        self.__x = x
        self.__y = y

    def getX(self):
        return self.__x

    def getY(self):
        return self.__y

class Board:
    def __init__(self):
        self.__board = [[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0],[0,0,0,0,0,0,0,0,0,0]]

    def isEmpty(self,l,c):
        return self.__board[l][c] == 0

    def is1(self,l,c):
        return self.__board[l][c] == 1

    def getBoard(self):
        return self.__board

    def placeShip(self,l,c,direction,length):
        if direction == "up":
            for i in range(length):
                if self.__board[l - i][c] != 0 or l - i < 0 or l - i > 4 or c < 0 or c > 4:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l - i][c] = 1
        elif direction == "down":
            for i in range(length):
                if self.__board[l + i][c] != 0 or l + i < 0 or l + i > 4 or c < 0 or c > 4:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l + i][c] = 1
        elif direction == "left":
            for i in range(length):
                if self.__board[l][c - i] != 0 or l < 0 or l > 4 or c - i < 0 or c - i > 4:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l][c - i] = 1
        elif direction == "right":
            for i in range(length):
                if self.__board[l][c + i] != 0 or l < 0 or l > 4 or c + i < 0 or c + i > 4:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l][c + i] = 1
        else:
            raise ValidatorException("Direction should be up, down, left or right!")

    def placeShipComputer(self,l,c,direction,length):
        if direction == "up":
            for i in range(length):
                if self.__board[l - i][c] != 0 or l - i < 0 or l - i > 4 or c < 5 or c > 9:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l - i][c] = 1
        if direction == "down":
            for i in range(length):
                if self.__board[l + i][c] != 0 or l + i < 0 or l + i > 4 or c < 5 or c > 9:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l + i][c] = 1
        if direction == "left":
            for i in range(length):
                if self.__board[l][c - i] != 0 or l < 0 or l > 4 or c - i < 5 or c - i > 9:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l][c - i] = 1
        if direction == "right":
            for i in range(length):
                if self.__board[l][c + i] != 0 or l < 0 or l > 4 or c + i < 5 or c + i > 9:
                    raise ValidatorException("Can't place ship here!")
            for i in range(length):
                self.__board[l][c + i] = 1

    def attack(self, l, c):
        if self.is1(l,c):
            self.__board[l][c] = "x"

    def isLost(self):
        ok = 0
        for l in range(5):
            for c in range (5):
                if self.__board[l][c] == "x":
                    ok += 1
        if ok == 9:
            return True
        return False

    def isWon(self):
        ok = 0
        for l in range(5):
            for c in range (5,10):
                if self.__board[l][c] == "x":
                    ok += 1
        if ok == 9:
            return True
        return False

    def notHitYet(self, l, c):
        if self.__board[l][c] == 1:
            return 0
        else:
            return self.__board[l][c]
