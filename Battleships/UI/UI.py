from Board.Board import Square
from Game.Game import Game
from random import randint
from random import random


class UI:
    def __init__(self, game, board):
        self.__game = game
        self.__board = board

    def parceMove(self,s):
        s = s.strip().split(",")
        if len(s) != 2:
            raise Exception("Format is <line>, <column>")
        else:
            return s

    def printBoard(self):
        x = self.__game.getBoard()
        for l in range(5):
            print(str(x[l][0]) + " " + str(x[l][1]) + " " + str(x[l][2]) + " " + str(x[l][3]) + " " + str(x[l][4]))
        print("\n")
        for l in range(5):
            print(str(self.__board.notHitYet(l,5)) + " " + str(self.__board.notHitYet(l,6)) + " " + str(self.__board.notHitYet(l,7)) + " " + str(self.__board.notHitYet(l,8)) + " " + str(self.__board.notHitYet(l,9)))


    def startUI(self):
        print("Start game, please place your ships")
        length = 2
        while length < 5:
            try:
                l = int(input("Select line of starting point: "))
                c = int(input("Select column of starting point: "))
                dir = input("Select direction: ")
                self.__game.placePlayer(l, c, dir, length)
                length += 1
            except Exception as ee:
                print(ee)
        length = 2
        while length < 5:
            try:
                self.__game.placeComputer(length)
                length += 1
            except Exception as ee:
                pass

        playerMove = True
        while self.__game.isWon() == False and self.__game.isLost() == False:
            self.printBoard()
            if playerMove:
                square = self.parceMove(input("Select move: "))
                self.__game.attPlayer(int(square[0]),int(square[1]))
                playerMove = False

            if not playerMove:
                self.__game.attComputer()
                playerMove = True

            if self.__game.isWon():
                print("Congratulations, you won!")
            elif self.__game.isLost():
                print("Oh no, you lost!")
