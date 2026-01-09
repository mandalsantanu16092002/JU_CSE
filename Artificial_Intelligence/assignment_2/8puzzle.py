import copy

class State:
    def __init__(self, values, parent=None, move=""):
        self.values = values
        self.parent = parent
        self.move = move

    def __eq__(self, other):
        return self.values == other.values

    def is_goal(self):
        return self.values == [1, 2, 3, 8, 0, 4, 7, 6, 5]

    def possible_moves(self):
        i = self.values.index(0)
        if i in [0, 1, 2]:
            return ["Down", "Right"]
        if i in [3, 4, 5]:
            return ["Up", "Down", "Right"]
        if i in [6, 7]:
            return ["Up", "Right"]
        if i == 8:
            return ["Up", "Left"]
        if i in [0, 3, 6]:
            return ["Down", "Right", "Left"]
        if i in [2, 5, 8]:
            return ["Down", "Up", "Left"]

    def make_move(self, move):
        i = self.values.index(0)
        if move == "Down":
            j = i + 3
        elif move == "Up":
            j = i - 3
        elif move == "Left":
            j = i - 1
        elif move == "Right":
            j = i + 1
        values = copy.deepcopy(self.values)
        values[i], values[j] = values[j], values[i]
        return State(values, self, move)

    def __str__(self):
        return str(self.values[0:3]) + "\n" + str(self.values[3:6]) + "\n" + str(self.values[6:9])

def print_moves(state):
    moves = []
    while state.parent != None:
        moves.append(state.move)
        state = state.parent
    moves = moves[::-1]
    print("Moves:", moves)

def solve(initial):
    frontier = [initial]
    while True:
        if not frontier:
            return None
        state = frontier.pop(0)
        if state.is_goal():
            return state
        for move in state.possible_moves():
            child = state.make_move(move)
            frontier.append(child)

initial = State([1, 2, 3, 8, 0, 4, 7, 6, 5])
goal = solve(initial)
if goal != None:
    print_moves(goal)
else:
    print("No solution found")

#This code defines a State class that represents the state of the 8-puzzle. The class has several methods 
# for finding possible moves, making moves, and checking if the state is the goal state. 
# The solve function performs the search for a solution, and the print_moves function prints out 
# the solution path from the initial state to the goal state. The code can be run by creating an initial state 
# and calling the solve function.
