class Graph:
    def __init__(self,n,edges):
        self.n = n
        self.adj = edges

    def addEdge(self,u,v):
        self.adj[u].append(v)
        self.adj[v].append(u)

    def dls(self,parent,node,dest,depth):
        self.order.append(node)
        self.path.append(node)

        if node == dest:
            self.flag = True
            return


        if depth>0:
            for it in self.adj[node]:
                if it!=parent:
                    self.dls(node,it,dest,depth-1)
                    if self.flag == True:
                        return

        self.path = self.path[:-1]

    def utilizeDLS(self,u,v):
        depth = int(input("Enter maximum depth to search:"))
        self.flag = False
        self.order = []
        self.path = []
        self.dls(None,u,v,depth)
        self.order = " ".join([str(x) for x in self.order])
        self.path = " ".join([str(x) for x in self.path])
        print(f"Order of nodes visited:\n{self.order}")

        if self.flag == True:
            print(f"Solution path:\n{self.path}")
        else:
            print(f"There is no path from {u} to {v}!!!")


    def utilizeIDS(self,u,v):
        depth = int(input("Enter depth of the graph/tree:"))
        totalOrder = ""
        tempFlag = False
        for i in range(0,depth+1):
            self.flag = False
            self.order = []
            self.path = []
            self.dls(None,u,v,i)
            self.order = " ".join([str(x) for x in self.order])
            self.path = " ".join([str(x) for x in self.path])
            totalOrder = totalOrder+self.order+"\n"
            if self.flag == True:
                tempFlag = True
                print(f"Order of nodes visited:\n{totalOrder}")
                print(f"Solution path:\n{self.path}\n")
                break
        if tempFlag == False:
            print(f"Order of nodes visited:\n{totalOrder}")
            print(f"There is no path from {u} to {v}!!!\n")

    def utilizeIBS(self,u,v):
        depth = int(input("Enter depth of the graph/tree:"))
        totalOrder = ""
        tempFlag = False
        for i in range(0,depth+1):
            queue = [(u,f"{u} "),(None,"")]
            flag = False
            order = []
            vis = {i:False for i in self.adj.keys()}
            noneCount = 0
            while len(queue)>0:
                node = queue[0][0]
                path = queue[0][1]
                queue = queue[1:]
                if node == None:
                    queue.append((None,""))
                    noneCount += 1
                    if noneCount>i:
                        break
                    continue
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
            totalOrder = totalOrder+order+"\n"
            if flag == True:
                tempFlag = True
                break
        print(f"Order of nodes visited:\n{totalOrder}")
        if tempFlag == True:
            print(f"Solution path:\n{path}")
        else:
            print(f"There is no path from {u} to {v}!!!")

if __name__ == "__main__":
    n = int(input("Enter number of nodes:"))
    edges = {i:[] for i in input("Enter nodes:").split()}
    g = Graph(n,edges)
    e = int(input("Enter number of edges:"))
    print("Enter edges:")
    for i in range(e):
        u,v = [x for x in input().split()]
        g.addEdge(u,v)

    while True:
        print("Enter 1 to use dls!!!")
        print("Enter 2 to use ids!!!")
        print("Enter 3 to use ibs!!!")
        print("Enter 4 to exit!!!")
        x = int(input())
        if x == 4:
            break

        u,v = [y for y in input("Enter source and dest. node:").split()]

        if x == 1:
            g.utilizeDLS(u,v)
        elif x == 2:
            g.utilizeIDS(u,v)
        else:
            g.utilizeIBS(u,v)
