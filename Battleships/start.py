from Board.Board import Board
from Game.Game import Game
from UI.UI import UI

board = Board()
game = Game(board)
ui = UI(game, board)
ui.startUI()