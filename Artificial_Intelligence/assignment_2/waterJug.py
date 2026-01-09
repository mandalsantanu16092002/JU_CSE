#BFS uses a Queue data structure that follows first in first out. 
#In BFS, one vertex is selected at a time when it is visited and marked then its adjacent are visited and stored in the queue.
visited = set()
order = []
path = []
flag = False

def fx(u,v,x,y):
    return (x,v)
def fy(u,v,x,y):
    return (u,y)
def ex(u,v,x,y):
    return (0,v)
def ey(u,v,x,y):
    return (u,0)
def px(u,v,x,y):
    if (x-u)>=v:
        return (u+v,0)
    return (x,v-x+u)
def py(u,v,x,y):
    if (y-v)>=u:
        return (0,u+v)
    return (u-y+v,y)

operations = [fx,fy,ex,ey,px,py]

#DFS, Depth First Search, is an edge-based technique. It uses the Stack data structure and performs two stages, first visited vertices are pushed into the stack, 
# and second if there are no vertices then visited vertices are popped. 
def dfs(u,v,x,y,target):
    global visited
    global order
    global path
    global flag
    global operations

    if (u,v) in visited:
        return

    visited.add((u,v))
    order.append((u,v))
    path.append((u,v))

    if v == target:
        flag = True
        return
    
    for operation in operations:
        (_u,_v) = operation(u,v,x,y)
        dfs(_u,_v,x,y,target)
        if flag:
            return
    
    path = path[:-1]

def utilizeDFS(x,y,target):
    global visited
    global order
    global path
    global flag
    visited = set()
    order = []
    path = []
    flag = False
    dfs(0,0,x,y,target)
    order = " ".join([str(x) for x in order])
    path = " ".join([str(x) for x in path])
    print(f"Order of nodes visited:\n{order}")

    if flag == True:
        print(f"Solution path:\n{path}")
    else:
        print(f"There is no way to fill 2nd jug with {target} units water!!!")



def utilizeBFS(x,y,target):
    global operations
    queue = [((0,0),"(0, 0) ")]
    flag = False
    order = []
    visited = set()
    while len(queue)>0:
        (u,v) = queue[0][0]
        path = queue[0][1]
        queue = queue[1:]
        if (u,v) in visited:
            continue
        visited.add((u,v))
        order.append((u,v))
        if v == target:
            flag = True
            break
        for operation in operations:
            (_u,_v) = operation(u,v,x,y)
            if (_u,_v) not in visited:
                newpath = path + f"({_u}, {_v}) "
                queue.append(((_u,_v),newpath))

    order = [str(x) for x in order]
    order = " ".join(order)

    print(f"Order of nodes visited:\n{order}")

    if flag == True:
        print(f"Solution path:\n{path}")
    else:
        print(f"There is no way to fill 2nd jug with {target} units water!!!")


def dls(parentU,parentV,u,v,x,y,target,depth,currentVis):
    global order
    global path
    global flag
    global operations

    if (u,v) in currentVis:
        return

    order.append((u,v))
    path.append((u,v))
    currentVis.add((u,v))

    if v == target:
        flag = True
        return
    
    if depth>0:
        for operation in operations:
            (_u,_v) = operation(u,v,x,y)
            if not(_u == parentU and _v == parentV) and not(u == parentU and v == parentV):
                dls(u,v,_u,_v,x,y,target,depth-1,currentVis)
                if flag:
                    return
    
    path = path[:-1]
    currentVis.remove((u,v))

def utilizeDLS(x,y,target):
    global order
    global path
    global flag
    order = []
    path = []
    flag = False
    depth = int(input("Enter maximum depth to search:"))
    dls(None,None,0,0,x,y,target,depth,set())
    order = " ".join([str(x) for x in order])
    path = " ".join([str(x) for x in path])
    print(f"Order of nodes visited:\n{order}")

    if flag == True:
        print(f"Solution path:\n{path}")
    else:
        print(f"There is no way to fill 2nd jug with {target} units water!!!")



def utilizeIDS(x,y,target):
    global order
    global path
    global flag
    depth = int(input("Enter depth of the graph/tree:"))
    totalOrder = ""
    tempFlag = False
    for i in range(0,depth+1):
        flag = False
        order = []
        path = []
        dls(None,None,0,0,x,y,target,i,set())
        order = " ".join([str(x) for x in order])
        path = " ".join([str(x) for x in path])
        totalOrder = totalOrder+order+"\n"
        if flag == True:
            tempFlag = True
            print(f"Order of nodes visited:\n{totalOrder}")
            print(f"Solution path:\n{path}\n")
            break
    if tempFlag == False:
        print(f"Order of nodes visited:\n{totalOrder}")
        print(f"There is no way to fill 2nd jug with {target} units water!!!")


def utilizeIBS(x,y,target):
    depth = int(input("Enter depth of the graph/tree:"))
    totalOrder = ""
    tempFlag = False
    for i in range(0,depth+1):
        queue = [((0,0),f"(0, 0) "),((None,None),"")]
        flag = False
        order = []
        visited = set()
        noneCount = 0
        while len(queue)>0:
            (u,v) = queue[0][0]
            path = queue[0][1]
            queue = queue[1:]
            if u == None:
                queue.append(((None,None),""))
                noneCount += 1
                if noneCount>i:
                    break
                continue
            if (u,v) in visited:
                continue
            visited.add((u,v))
            order.append((u,v))
            if v == target:
                flag = True
                break
            for operation in operations:
                (_u,_v) = operation(u,v,x,y)
                if (_u,_v) not in visited:
                    newpath = path + f"({_u}, {_v}) "
                    queue.append(((_u,_v),newpath))

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
        print(f"There is no way to fill 2nd jug with {target} units water!!!")



x,y = [int(i) for i in input("Enter size of two containers:").split()]
target = int(input("Enter amount to be filled in 2nd container:"))

while(True):
    print("Enter 1 to use dfs!!!")
    print("Enter 2 to use bfs!!!")
    print("Enter 3 to use dls!!!")
    print("Enter 4 to use ids!!!")
    print("Enter 5 to use ibs!!!")
    print("Enter 6 to exit!!!")
    i = int(input())

    match(i):
        case 1:
            utilizeDFS(x,y,target) 
        case 2:
            utilizeBFS(x,y,target)
        case 3:
            utilizeDLS(x,y,target)
        case 4:
            utilizeIDS(x,y,target)
        case 5:
            utilizeIBS(x,y,target)
        case 6:
            break  