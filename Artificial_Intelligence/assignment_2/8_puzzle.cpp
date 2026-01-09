#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair
const int gridSize = 3;
// LURB

void printGrid(vector<vector<char>> &grid)
{
    cout << endl;

    for (int i = 0; i < gridSize; i++)
    {
        for (int j = 0; j < gridSize; j++)
            cout << grid[i][j] << " ";
        cout << endl;
    }
    return;
}

struct state{  
    pii zeroPos;
    vector<vector<char>> board;

    state(int x,int y){
        zeroPos.first = x;
        zeroPos.second = y;
        board.resize(gridSize,vector<char>(gridSize));
    }

    state(){
        zeroPos.first = 0;
        zeroPos.second=0;
        board.resize(gridSize, vector<char>(gridSize));
    }

    void moveUp(){
        swap(board[zeroPos.first-1][zeroPos.second],board[zeroPos.first][zeroPos.second]);
        zeroPos.first--;
        return;
    }

    void moveDown(){
        swap(board[zeroPos.first+1][zeroPos.second],board[zeroPos.first][zeroPos.second]);
        zeroPos.first++;
        return;
    }

    void moveLeft(){
        swap(board[zeroPos.first][zeroPos.second-1],board[zeroPos.first][zeroPos.second]);
        zeroPos.second--;
        return;
    }

    void moveRight(){
        swap(board[zeroPos.first][zeroPos.second+1],board[zeroPos.first][zeroPos.second]);
        zeroPos.second++;
        return;
    }

    bool upValid(){
        return zeroPos.first>=1;
    }

    bool downValid(){
        return zeroPos.first<gridSize-1;
    }

    bool leftValid(){
        return zeroPos.second>=1;
    }

    bool rightValid(){
        return zeroPos.second<gridSize-1;
    }

    bool operator < (const state& s) const{
        return board<s.board;
    }

    bool operator == (const state& s)const{
        return board == s.board;
    }

    bool operator != (const state& s)const{
        return board != s.board;
    }

    void applyString(vector<char>& traversal){
        printGrid(board);
        for(char& c:traversal){
            if(c=='U')
                this->moveUp();
            if(c=='B')
                this->moveDown();
            if(c=='L')
                this->moveLeft();
            if(c=='R')
                this->moveRight();

            printGrid(board);
        }
    }
};

ostream& operator << (ostream& os,state s){
    os<<endl;

    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridSize;j++)
            os<<s.board[i][j]<<" ";
        os<<endl;
    }

    return os;
}

istream& operator >> (istream& is,state& s){
    for(int i=0;i<gridSize;i++){
        for(int j=0;j<gridSize;j++){
            is>>s.board[i][j];

            if(s.board[i][j]=='x'){
                s.zeroPos.first=i;
                s.zeroPos.second=j;
            }
        }
    }
    return is;
}

class Solver{
    public:
        state initialState;
        state finalState;
        set<state> visited;
        vector<char> traversal;
        vector<state> nodesVisited;
        bool isFound;

        Solver(){
            cin>>initialState;
            cin>>finalState;
            isFound = false;
        }

        void dfsUtil(state& src){
            if(src==finalState){
                isFound=true;
            }
            
            if(isFound)
                return;
            
            if(visited.find(src)!=visited.end())
                return;

            nodesVisited.pb(src);
            
            visited.insert(src);
            bool tempFound = false;

            if(src.leftValid()){
                src.moveLeft();
                dfsUtil(src);
                src.moveRight();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('L');
                }
            }

            if(src.upValid()){
                src.moveUp();
                dfsUtil(src);
                src.moveDown();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('U');
                }
            }

            if(src.rightValid()){
                src.moveRight();
                dfsUtil(src);
                src.moveLeft();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('R');
                }
            }

            if(src.downValid()){
                src.moveDown();
                dfsUtil(src);
                src.moveUp();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('B');
                }
            }
            return;
        }

        void dfs(){
            dfsUtil(initialState);
        }

        void printTraversal(){
            if(!isFound){
                cout<<"Goal state not found"<<endl;
                return;
            }

            cout<<"Goal state found"<<endl;
            reverse(traversal.begin(),traversal.end());
            initialState.applyString(traversal);
        }

        void bfs(){
            map<state,state> parent;
            queue<state> q;

            q.push(initialState);
            visited.insert(initialState);

            while(!q.empty()){
                state front = q.front();
                state temp = front;
                nodesVisited.pb(front);
                q.pop();

                if(front.leftValid()){
                    front.moveLeft();
                    if(visited.find(front)==visited.end()){
                        q.push(front);
                        visited.insert(front);
                        parent[front] = temp;
                    }

                    if(front==finalState){
                        isFound = true;
                        break;
                    }
                    
                    front.moveRight();

                }

                if(front.upValid()){
                    front.moveUp();
                    if(visited.find(front)==visited.end()){
                        q.push(front);
                        visited.insert(front);
                        parent[front] = temp;
                    }

                    if(front==finalState){
                        isFound = true;
                        break;
                    }

                    front.moveDown();
                }

                if(front.rightValid()){
                    front.moveRight();
                    if(visited.find(front)==visited.end()){
                        q.push(front);
                        visited.insert(front);
                        parent[front] = temp;
                    }

                    if(front==finalState){
                        isFound = true;
                        break;
                    }

                    front.moveLeft();
                }

                if(front.downValid()){
                    front.moveDown();
                    if(visited.find(front)==visited.end()){
                        q.push(front);
                        visited.insert(front);
                        parent[front] = temp;
                    }

                    if(front==finalState){
                        isFound = true;
                        break;
                    }
                    front.moveUp();
                }
            }

            if(!isFound){
                cout<<"Goal state not found"<<endl;
            }

            else{
                cout<<"Goal state found"<<endl;
                vector<state> path;
                nodesVisited.pb(finalState);
                state par = finalState;

                while(par!=initialState){
                    path.pb(par);
                    par = parent[par];
                }

                path.pb(initialState);
                reverse(path.begin(),path.end());

                for(state p:path)
                    cout<<p;
            }
        }

        void idsUtil(map<state,int>& depths,state& src,int depth,int& limit){

            if(depth>limit)
                return;

            if(src==finalState){
                isFound=true;
            }
            
            if(isFound)
                return;

            if(depths.find(src)==depths.end())
                nodesVisited.pb(src);

            
            if(depths.find(src)!=depths.end()&&depths[src]<=depth)
                return;

            depths[src]=depth;
            bool tempFound = false;

            if(src.leftValid()){
                src.moveLeft();
                idsUtil(depths,src,depth+1,limit);
                src.moveRight();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('L');
                }
            }

            if(src.upValid()){
                src.moveUp();
                idsUtil(depths,src,depth+1,limit);
                src.moveDown();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('U');
                }
            }

            if(src.rightValid()){
                src.moveRight();
                idsUtil(depths,src,depth+1,limit);
                src.moveLeft();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('R');
                }
            }

            if(src.downValid()){
                src.moveDown();
                idsUtil(depths,src,depth+1,limit);
                src.moveUp();

                if(isFound&&!tempFound){
                    tempFound=true;
                    traversal.pb('B');
                }
            }
            return;
        }

        void ids(){
            int limit = 0;
            map<state,int> depths;
            while(!isFound&&limit<50){
                depths.clear();
                idsUtil(depths,initialState,0,limit);

                cout<<"\nAfter depth "<<limit<<" traversal is "<<endl;
                this->printVisited();
                nodesVisited.clear();
                limit++;
            }
        }

        void ibsUtil(state& src,int& breadth,vector<int>& ops){
            if(src==finalState){
                isFound=true;
                nodesVisited.pb(src);
            }

            if(isFound)
                return;

            if(visited.find(src)!=visited.end())
                return;

            nodesVisited.pb(src);

            unsigned seed = std::chrono::system_clock::now()
                        .time_since_epoch()
                        .count();

            shuffle(ops.begin(),ops.end(),default_random_engine(seed));

            visited.insert(src);

            bool tempFound = false;

            int cnt = 0;
            for(int op:ops){
                if(cnt==breadth)
                    break;

                if(op==0){
                    if(src.leftValid()){
                        src.moveLeft();
                        ibsUtil(src,breadth,ops);
                        src.moveRight();

                        if(isFound&&!tempFound){
                            tempFound=true;
                            traversal.pb('L');
                        }
                        cnt++;
                    }
                }

                else if(op==1){
                    if(src.upValid()){
                        src.moveUp();
                        ibsUtil(src,breadth,ops);
                        src.moveDown();

                        if(isFound&&!tempFound){
                            tempFound=true;
                            traversal.pb('U');
                        }
                        cnt++;
                    }
                }

                else if(op==2){
                    if(src.rightValid()){
                        src.moveRight();
                        ibsUtil(src,breadth,ops);
                        src.moveLeft();

                        if(isFound&&!tempFound){
                            tempFound=true;
                            traversal.pb('R');
                        }
                        cnt++;
                    }
                }

                else if(op==3){
                    if(src.downValid()){
                        src.moveDown();
                        ibsUtil(src,breadth,ops);
                        src.moveUp();

                        if(isFound&&!tempFound){
                            tempFound=true;
                            traversal.pb('B');
                        }
                        cnt++;
                    }
                }
            }
        }

        void ibs(){
            int breadth = 0;
            vector<int> ops = {0,1,2,3};
            while(!isFound&&breadth<=4){
                visited.clear();
                ibsUtil(initialState,breadth,ops);

                cout<<"\nAfter breadth "<<breadth<<" traversal is "<<endl;
                this->printVisited();
                nodesVisited.clear();
                breadth++;
            }
        }

        int getHeuristic(state& s){
            int h=0;
            for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                    if(s.board[i][j]!=finalState.board[i][j])
                        h++;
                }
            }
            return h;
        }

        int getCost(state& s,map<state,int>& costs){
            if(costs.find(s)==costs.end())
                return inf;
            return costs[s];
        }

        void aStar(){
            map<state,int> costs;
            vector<pii> pos(9);

            auto comparator = [&](state& s,state& b){
                return (getCost(s,costs)+getHeuristic(s))>(getCost(b,costs)+getHeuristic(b));
            };

            priority_queue<state,vector<state>,decltype(comparator)> pq(comparator);

            pq.push(initialState);
            costs[initialState]=0;
            map<state,state> parent;
            

            while(!pq.empty()){
                state src = pq.top();
                pq.pop();

                if(src==finalState){
                    isFound=true;
                    nodesVisited.pb(src);
                    break;
                }

                if(visited.find(src)!=visited.end())
                    continue;
                
                state temp = src;
                nodesVisited.pb(src);
                visited.insert(src);

                if(src.leftValid()){
                    src.moveLeft();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);
                    }
                    src.moveRight();
                }

                if(src.upValid()){
                    src.moveUp();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);
                    }
                    src.moveDown();
                }

                if(src.rightValid()){
                    src.moveRight();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);

                    }
                    src.moveLeft();
                }

                if(src.downValid()){
                    src.moveDown();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);

                    }
                    src.moveUp();
                }
            }

            if(!isFound){
                cout<<"Goal state not found"<<endl;
            }

            else{
                cout<<"Goal state found"<<endl;
                vector<state> path;
                nodesVisited.pb(finalState);
                state par = finalState;

                while(par!=initialState){
                    path.pb(par);
                    par = parent[par];
                }

                path.pb(initialState);
                reverse(path.begin(),path.end());

                for(state p:path)
                    cout<<p;
            }
        }
        
        void ucs(){
            map<state,int> costs;
            vector<pii> pos(9);

            auto comparator = [&](state& s,state& b){
                return getCost(s,costs)>getCost(b,costs);
            };

            priority_queue<state,vector<state>,decltype(comparator)> pq(comparator);

            pq.push(initialState);
            costs[initialState]=0;
            map<state,state> parent;
            

            while(!pq.empty()){
                state src = pq.top();
                pq.pop();

                if(src==finalState){
                    isFound=true;
                    nodesVisited.pb(src);
                    break;
                }

                if(visited.find(src)!=visited.end())
                    continue;
                
                state temp = src;
                nodesVisited.pb(src);
                visited.insert(src);

                if(src.leftValid()){
                    src.moveLeft();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);
                    }
                    src.moveRight();
                }

                if(src.upValid()){
                    src.moveUp();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);
                    }
                    src.moveDown();
                }

                if(src.rightValid()){
                    src.moveRight();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);

                    }
                    src.moveLeft();
                }

                if(src.downValid()){
                    src.moveDown();
                    if(getCost(src,costs)>getCost(temp,costs)+1){
                        costs[src]=getCost(temp,costs)+1;
                        parent[src]=temp;
                        pq.push(src);

                    }
                    src.moveUp();
                }
            }

            if(!isFound){
                cout<<"Goal state not found"<<endl;
            }

            else{
                cout<<"Goal state found"<<endl;
                vector<state> path;
                nodesVisited.pb(finalState);
                state par = finalState;

                while(par!=initialState){
                    path.pb(par);
                    par = parent[par];
                }

                path.pb(initialState);
                reverse(path.begin(),path.end());

                for(state p:path)
                    cout<<p;
        }
        }

        void bfgUtil(state& src){
            if(src==finalState){
                isFound=true;
                nodesVisited.pb(src);
                return;
            }

            auto comparator = [&](state& s,state& b){
                return getHeuristic(s)>getHeuristic(b);
            };

            vector<state> children;

            if(src.leftValid()){
                src.moveLeft();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveRight();
            }

            if(src.upValid()){
                src.moveUp();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveDown();
            }

            if(src.rightValid()){
                src.moveRight();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveLeft();
            }

            if(src.downValid()){
                src.moveDown();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveUp();
            }

            sort(children.begin(),children.end(),comparator);

            if(children.size()==0)
                return;

            visited.insert(children[0]);
            nodesVisited.pb(children[0]);
            bfgUtil(children[0]);
            return;
        }

        void bfg(){
            visited.insert(initialState);
            nodesVisited.pb(initialState);
            bfgUtil(initialState);
        }

        void greedyUtil(state src){
            if(src==finalState){
                isFound=true;
                nodesVisited.pb(src);
                return;
            }

            auto comparator = [&](state& s,state& b){
                return getHeuristic(s)>getHeuristic(b);
            };

            vector<state> children;

            if(src.leftValid()){
                src.moveLeft();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveRight();
            }

            if(src.upValid()){
                src.moveUp();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveDown();
            }

            if(src.rightValid()){
                src.moveRight();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveLeft();
            }

            if(src.downValid()){
                src.moveDown();
                if(visited.find(src)==visited.end()){
                    children.pb(src);
                }
                src.moveUp();
            }

            sort(children.begin(),children.end(),comparator);

            if(children.size()==0)
                return;

            for(state s:children){
                visited.insert(s);
                nodesVisited.pb(s);
                greedyUtil(s);
                if(isFound)
                    return;
            }
            return;
        }

        void greedy(){
            visited.insert(initialState);
            nodesVisited.pb(initialState);
            greedyUtil(initialState);
        }

        void printVisited(){
            cout<<nodesVisited.size()<<endl;
            for(state s:nodesVisited)
                cout<<s;
        }
};

int main(){
    Solver s;

    string choice;
    cin>>choice;

    if(choice=="bfs"){
        cout<<"----------------PATH----------------"<<endl;
        s.bfs();
    }

    else if(choice=="dfs"){
        cout<<"----------------PATH----------------"<<endl;
        s.dfs();
        s.printTraversal();
    }
    
    else if(choice=="ids"){
        s.ids();
        cout<<"----------------PATH----------------"<<endl;
        s.printTraversal();
    }

    else if(choice=="ibs"){
        s.ibs();
        cout<<s.traversal.size()<<endl;
        cout<<"----------------PATH----------------"<<endl;
        s.printTraversal();
    }

    else if(choice=="astar"){
        cout<<"----------------PATH----------------"<<endl;
        s.aStar();
    }

    else if(choice=="ucs"){
        cout<<"----------------PATH----------------"<<endl;
        s.ucs();
    }

    else if(choice=="bfg"){
        cout<<"----------------PATH----------------"<<endl;
        s.bfg();
    }

    else{
        cout<<"Invalid choice"<<endl;
    }

    if(choice!="ids" && choice!="ibs"){
        cout<<"----------------TRAVERSAL----------------"<<endl;
        s.printVisited();
    }
}