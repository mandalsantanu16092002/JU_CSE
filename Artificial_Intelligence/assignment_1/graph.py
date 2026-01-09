# Initialize graph
class Graph:
    def __init__(self,n):
        self.n = n
        self.adj = {i:[] for i in range(n)}

    #add edges
    #u and v are source and destination node of your graph
    def addEdge(self,u,v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dfs(self,node,dest):
        if self.vis[node]:
            return

        self.vis[node] = True
        self.order.append(node)
        self.path.append(node)

        if node == dest:
            self.flag = True
            return

        for it in self.adj[node]:
            self.dfs(it,dest)
            if self.flag == True:
                return
    #add path
        self.path = self.path[:-1]

    #algorithm for DFS
    def utilizeDFS(self,u,v):
        self.vis = [False for i in range(self.n)]
        self.flag = False
        self.order = []
        self.path = []
        self.dfs(u,v)
        self.order = " ".join([str(x) for x in self.order])
        self.path = " ".join([str(x) for x in self.path])
        print(f"Order of nodes visited:\n{self.order}")

        if self.flag == True:
            print(f"Solution path:\n{self.path}")
        else:
            print(f"There is no path from {u} to {v}!!!")

    #algorithm for BFS
    def utilizeBFS(self,u,v):
        queue = [(u,f"{u} ")]
        flag = False
        order = []
        vis = [False for i in range(self.n)]
        while len(queue)>0:
            node = queue[0][0]
            path = queue[0][1]
            queue = queue[1:]
            if vis[node]:
                continue
            vis[node] = True
            order.append(node)
            if node == v:
                flag = True
                break
            for it in self.adj[node]:
                if not(vis[it]):
                    newpath = path + f"{it} "
                    queue.append((it,newpath))

        order = [str(x) for x in order]
        order = " ".join(order)

        print(f"Order of nodes visited of the graph :\n{order}")

        if flag == True:
            print(f"Solution path:\n{path}")
        else:
            print(f"There is no path from {u} to {v}!!!")


if __name__ == "__main__":
    n = int(input("Enter number of nodes of graph : "))
    g = Graph(n)
    e = int(input("Enter number of edges according to nodes : "))
    print("Enter the corresponding edges of your graph : ")
    for i in range(e):
        u,v = [int(x) for x in input().split()]
        g.addEdge(u,v)

    while True:
        print("FOR DFS Enter 1")
        print("FOR BFS ENTER 2")
        print("FOR EXIT ENTER 3\n")
        x = int(input("Enter your choice : "))
        
        if x == 3:
            break

        u,v = [int(y) for y in input("Enter your source and destination node of your graph : ").split()]

        if x == 1:
            g.utilizeDFS(u,v)
        else:
            g.utilizeBFS(u,v)
