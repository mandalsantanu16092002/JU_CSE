from queue import Queue

class MazeSolver:
    def __init__(self, maze):
        self.maze = maze
        self.width = len(maze[0])
        self.height = len(maze)
        self.visited = [[False for y in range(self.height)] for x in range(self.width)]

    def solve_dfs(self, start, end):
        self.visited[start[0]][start[1]] = True
        return self.dfs(start, end)

    def dfs(self, current, end):
        if current == end:
            return [current]
        
        for neighbor in self.get_neighbors(current):
            if not self.visited[neighbor[0]][neighbor[1]]:
                self.visited[neighbor[0]][neighbor[1]] = True
                path = self.dfs(neighbor, end)
                if path is not None:
                    return [current] + path

        return None

    def solve_bfs(self, start, end):
        queue = Queue()
        queue.put([start])
        self.visited[start[0]][start[1]] = True

        while not queue.empty():
            path = queue.get()
            current = path[-1]
            if current == end:
                return path
            for neighbor in self.get_neighbors(current):
                if not self.visited[neighbor[0]][neighbor[1]]:
                    self.visited[neighbor[0]][neighbor[1]] = True
                    new_path = path.copy()
                    new_path.append(neighbor)
                    queue.put(new_path)

        return None

    def solve_idfs(self, start, end, depth_limit=100):
        for depth in range(depth_limit):
            self.visited = [[False for y in range(self.height)] for x in range(self.width)]
            path = self.dls(start, end, depth)
            if path is not None:
                return path

        return None

    def dls(self, current, end, depth):
        if current == end:
            return [current]
        if depth == 0:
            return None

        for neighbor in self.get_neighbors(current):
            if not self.visited[neighbor[0]][neighbor[1]]:
                self.visited[neighbor[0]][neighbor[1]] = True
                path = self.dls(neighbor, end, depth-1)
                if path is not None:
                    return [current] + path

        return None

    def get_neighbors(self, cell):
        x, y = cell
        neighbors = []
        if x > 0 and not self.maze[y][x-1]:
            neighbors.append((x-1, y))
        if x < self.width-1 and not self.maze[y][x+1]:
            neighbors.append((x+1, y))
        if y > 0 and not self.maze[y-1][x]:
            neighbors.append((x, y-1))
        if y < self.height-1 and not self.maze[y+1][x]:
            neighbors.append((x, y+1))
        return neighbors


# Example usage
maze = [
    [False, False, False, False, False],
    [True, True, False, True, False],
    [False, False, False, True, False],
    [True, True, True, True, False],
    [False, False, False, False, False]
]
solver = MazeSolver(maze)
start = (0, 0)
end = (4, 4)
dfs_path = solver.solve_dfs(start, end)
bfs_path = solver.solve_bfs(start, end)
idfs_path = solver.solve_idfs(start, end)
print("DFS path:", dfs_path)
print("BFS path:", bfs_path)
print("IDFS path:", idfs_path)