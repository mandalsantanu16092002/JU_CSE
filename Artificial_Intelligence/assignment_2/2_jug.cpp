#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include<chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

struct state{
    pii data;

    state(){
        data.first = 0;
        data.second = 0;
    }

    state(int a,int b){
        data.first = a;
        data.second = b;
    }

    state emptyLeft(){
        return state(0,data.second);
    }

    state emptyRight(){
        return state(data.first,0);
    }

    state pourLeft(int limit){
        int slack = limit-data.second;
        return state(max(0,data.first-slack),data.second+min(slack,data.first));
    }

    state pourRight(int limit){
        int slack = limit - data.first;
        return state(data.first+min(slack,data.second),max(0,data.second-slack));
    }

    state fillLeft(int limit){
        return state(limit,data.second);
    }

    state fillRight(int limit){
        return state(data.first,limit);
    }

    bool operator == (const state& s) const{
        return data==s.data;
    }

    bool operator != (const state& s) const{
        return data!=s.data;
    }

};

bool operator < (const state& s1,const state& s2){
    return s1.data<s2.data;
}

ostream& operator << (ostream& o,const state& s){
    o<<s.data.first<<" "<<s.data.second<<endl;
    return o;
}

class Solver{
    state initialState;
    state finalState;
    int goalCost;
    pii maxSize;
    set<state> visited;
    map<state,state> parent;
    vector<state> path;
    bool isFound;

    public:

        bool isFinal(state s){
            return s.data.first==goalCost||s.data.second==goalCost;
        }
        Solver(){
            // cout<<"Enter the max sizes of both buckets"<<endl;
            cin>>maxSize.first>>maxSize.second;
            // cout<<"Enter initial state"<<endl;
            cin>>initialState.data.first>>initialState.data.second;
            // cout<<"Enter goal state"<<endl;
            cin>>goalCost;
            isFound = false;
        }

        void dfsUtil(state src,state par){
            if(isFinal(src)){
                isFound = true;
                finalState = src;
                path.pb(src);
            }

            if (visited.find(src) != visited.end())
                return;

            parent[src] = par;

            if(isFound)
                return;

            path.pb(src);

            visited.insert(src);
            state temp;

            if(src.data.first!=0){
                temp = src.emptyLeft();
                dfsUtil(temp,src);
            }

            if(src.data.second!=0){
                temp = src.emptyRight();
                dfsUtil(temp,src);
            }

            if(src.data.first<maxSize.first){
                temp = src.fillLeft(maxSize.first);
                dfsUtil(temp,src);
            }

            if(src.data.second<maxSize.second){
                temp = src.fillRight(maxSize.second);
                dfsUtil(temp,src);
            }

            if(src.data.second<maxSize.second&&src.data.first>0){
                temp = src.pourLeft(maxSize.second);
                dfsUtil(temp,src);
            }

            if(src.data.first<maxSize.first&&src.data.second>0){
                temp = src.pourRight(maxSize.first);
                dfsUtil(temp,src);
            }

            return;
        }


        void dfs(){
            dfsUtil(initialState,initialState);
            return;
        }

        void bfs(){
            queue<state> q;
            q.push(initialState);
            parent[initialState] = initialState;
            visited.insert(initialState);

            while(!q.empty()){
                state src = q.front();
                q.pop();
                path.pb(src);
                if(isFinal(src)){
                    isFound = true;
                    finalState = src;
                }

                if(isFound)
                    break;

                state temp;
                if(src.data.first!=0){
                    temp = src.emptyLeft();

                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

                if(src.data.second!=0){
                    temp = src.emptyRight();
                    
                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

                if(src.data.first<maxSize.first){
                    temp = src.fillLeft(maxSize.first);

                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

                if(src.data.second<maxSize.second){
                    temp = src.fillRight(maxSize.second);

                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

                if(src.data.second<maxSize.second&&src.data.first>0){
                    temp = src.pourLeft(maxSize.second);

                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

                if(src.data.first<maxSize.first&&src.data.second>0){
                    temp = src.pourRight(maxSize.first);

                    if(visited.find(temp)==visited.end()){
                        q.push(temp);
                        parent[temp] = src;
                        visited.insert(temp);
                    }

                }

            }
            return;
        }

        void idsUtil(map<state,int>& depths,state src,state par,int depth,int& limit){
            if(isFound)
                return;

            if(depth>limit)
                return;

            if(isFinal(src)){
                isFound = true;
                finalState = src;
                parent[src] = par;
                path.pb(src);
                return;
            }

            if(depths.find(src)==depths.end()){
                depths[src] = depth;
                parent[src] = par;
                path.pb(src);
            }
            else if(depths[src]>depth){
                depths[src] = depth;
                path.pb(src);
                parent[src]=par;
            }
            else
                return;

            if(isFound)
                return;

            state temp;

            if(src.data.first!=0){
                temp = src.emptyLeft();
                idsUtil(depths,temp,src,depth+1,limit);
            }

            if(src.data.second!=0){
                temp = src.emptyRight();
                idsUtil(depths,temp,src,depth+1,limit);
            }

            if(src.data.first<maxSize.first){
                temp = src.fillLeft(maxSize.first);
                idsUtil(depths,temp,src,depth+1,limit);
            }

            if(src.data.second<maxSize.second){
                temp = src.fillRight(maxSize.second);
                idsUtil(depths,temp,src,depth+1,limit);
            }

            if(src.data.second<maxSize.second&&src.data.first>0){
                temp = src.pourLeft(maxSize.second);
                idsUtil(depths,temp,src,depth+1,limit);
            }

            if(src.data.first<maxSize.first&&src.data.second>0){
                temp = src.pourRight(maxSize.first);
                idsUtil(depths,temp,src,depth+1,limit);
            }

            return;
        }

        void ids(){
            int limit = 0;
            map<state,int> depths;
            while(!isFound){
                depths.clear();
                //path.clear();
                parent.clear();
                idsUtil(depths,initialState,initialState,0,limit);

                cout<<"\nAfter depth "<<limit<<" Traverasal is "<<endl;
                this->printTraversal();
                path.clear();
                limit++;
            }
            //cout<<(parent.find(finalState)==parent.end())<<endl;
            //cout<<parent.size()<<endl;
            return;
        }

        void ibsUtil(state src,state par,int& breadth,vector<int>& ops){
            if(isFinal(src)){
                isFound = true;
                finalState = src;
            }

            if(visited.find(src)==visited.end()){
                visited.insert(src);
                path.pb(src);
                parent[src] = par;
            }
            else
                return;

            if(isFound)
                return;

            unsigned int seed = chrono::system_clock::now().time_since_epoch().count();

            shuffle(ops.begin(),ops.end(),default_random_engine(seed));


            state temp;
            int cnt=0;

            for(int& op:ops){
                if(cnt==breadth)
                    break;

                if(op==0){
                    if(src.data.first!=0){
                        temp = src.emptyLeft();
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }

                else if(op==1){
                    if(src.data.second!=0){
                        temp = src.emptyRight();
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }

                else if(op==2){
                    if(src.data.first<maxSize.first){
                        temp = src.fillLeft(maxSize.first);
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }

                else if(op==3){
                    if(src.data.second<maxSize.second){
                        temp = src.fillRight(maxSize.second);
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }

                else if(op==4){
                    if(src.data.second<maxSize.second&&src.data.first>0){
                        temp = src.pourLeft(maxSize.second);
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }

                else if(op==5){
                    if(src.data.first<maxSize.first&&src.data.second>0){
                        temp = src.pourRight(maxSize.first);
                        ibsUtil(temp,src,breadth,ops);
                        cnt++;

                        if(isFound)
                            return;
                    }
                }
            }
        }

        void ibs(){
            int breadth = 0;
            vector<int> ops = {0,1,2,3,4,5};
            while(!isFound){
                visited.clear();
                parent.clear();
                ibsUtil(initialState,initialState,breadth,ops);

                cout<<"\nAfter limit "<<breadth<<" Traversal is"<<endl;

                this->printTraversal();
                path.clear();

                breadth++;
            }
            return;
        }

        int getHeuristic(state& s){
            return abs(s.data.first-goalCost)+abs(s.data.second-goalCost);
        }

        int getCost(state& s,map<state,int>& costs){
            if(costs.find(s)==costs.end())
                return inf;
            return costs[s];
        }

        void astar(){
            map<state,int> costs;

            auto comparator = [&](state& s,state& b){
                return (getCost(s,costs)+getHeuristic(s))>(getCost(b,costs)+getHeuristic(b));
            };

            priority_queue<state,vector<state>,decltype(comparator)> pq(comparator);

            pq.push(initialState);
            costs[initialState]=0;

            while(!pq.empty()){
                state src = pq.top();
                path.pb(src);
                pq.pop();

                if(isFinal(src)){
                    isFound = true;
                    finalState = src;
                    break;
                }

                if(visited.find(src)==visited.end()){
                    visited.insert(src);
                }
                

                //use getcost fn

                state temp;

                if(src.data.first!=0){
                    temp = src.emptyLeft();
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                    }
                }

                if(src.data.second!=0){
                    temp = src.emptyRight();
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }

                if(src.data.first<maxSize.first){
                    temp = src.fillLeft(maxSize.first);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }

                if(src.data.second<maxSize.second){
                    temp = src.fillRight(maxSize.second);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }


                if(src.data.second<maxSize.second&&src.data.first>0){
                    temp = src.pourLeft(maxSize.second);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }


                if(src.data.first<maxSize.first&&src.data.second>0){
                    temp = src.pourRight(maxSize.first);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }
            }
        }

        void greedyUtil(state& src){
            if(isFinal(src)){
                isFound = true;
                finalState = src;
                path.pb(src);
                return;
            }

            auto comparator = [&](state& s,state& b){
                return getHeuristic(s)>getHeuristic(b);
            };

            visited.insert(src);
            path.pb(src);

            vector<state> children;

            if(src.data.first!=0){
                if(visited.find(src.emptyLeft())==visited.end())
                    children.pb(src.emptyLeft());
            }

            if(src.data.second!=0){
                if(visited.find(src.emptyRight())==visited.end())
                    children.pb(src.emptyRight());
            }

            if(src.data.first<maxSize.first){
                if(visited.find(src.fillLeft(maxSize.first))==visited.end())
                    children.pb(src.fillLeft(maxSize.first));
            }

            if(src.data.second<maxSize.second){
                if(visited.find(src.fillRight(maxSize.second))==visited.end())
                    children.pb(src.fillRight(maxSize.second));
            }

            if(src.data.second<maxSize.second&&src.data.first>0){
                if(visited.find(src.pourLeft(maxSize.second))==visited.end())
                    children.pb(src.pourLeft(maxSize.second));
            }

            if(src.data.first<maxSize.first&&src.data.second>0){
                if(visited.find(src.pourRight(maxSize.first))==visited.end())
                    children.pb(src.pourRight(maxSize.first));
            }

            sort(children.begin(),children.end(),comparator);

            if(children.size()==0)
                return;

            state next = children[0];
            parent[next] = src;
            greedyUtil(next);
            return;
        }

        void greedy(){
            greedyUtil(initialState);
        }

        void bfgUtil(state src){
            if(isFinal(src)){
                isFound = true;
                finalState = src;
                path.pb(src);
                return;
            }

            auto comparator = [&](state& s,state& b){
                return getHeuristic(s)>getHeuristic(b);
            };

            visited.insert(src);
            path.pb(src);

            vector<state> children;

            if(src.data.first!=0){
                if(visited.find(src.emptyLeft())==visited.end())
                    children.pb(src.emptyLeft());
            }

            if(src.data.second!=0){
                if(visited.find(src.emptyRight())==visited.end())
                    children.pb(src.emptyRight());
            }

            if(src.data.first<maxSize.first){
                if(visited.find(src.fillLeft(maxSize.first))==visited.end())
                    children.pb(src.fillLeft(maxSize.first));
            }

            if(src.data.second<maxSize.second){
                if(visited.find(src.fillRight(maxSize.second))==visited.end())
                    children.pb(src.fillRight(maxSize.second));
            }

            if(src.data.second<maxSize.second&&src.data.first>0){
                if(visited.find(src.pourLeft(maxSize.second))==visited.end())
                    children.pb(src.pourLeft(maxSize.second));
            }

            if(src.data.first<maxSize.first&&src.data.second>0){
                if(visited.find(src.pourRight(maxSize.first))==visited.end())
                    children.pb(src.pourRight(maxSize.first));
            }

            sort(children.begin(),children.end(),comparator);

            if(children.size()==0)
                return;

            for(state& child:children){
                parent[child] = src;
                bfgUtil(child);
                if(isFound)
                    return;
            }
            return;
        }

        void bfg(){
            bfgUtil(initialState);
        }

        void printPath(){
            if(!isFound){
                cout<<"Goal state not found"<<endl;
                return;
            }

            else
                cout<<"Goal state found"<<endl;

            vector<state> path;
            state temp = finalState;

            while(temp!=initialState){
                path.pb(temp);
                temp = parent[temp];
            }

            path.pb(initialState);
            reverse(path.begin(),path.end());

            for(state& s:path)
                cout<<s;
        }

        void ucs(){
            map<state,int> costs;

            auto comparator = [&](state& s,state& b){
                return (getCost(s,costs))>(getCost(b,costs));
            };

            priority_queue<state,vector<state>,decltype(comparator)> pq(comparator);

            pq.push(initialState);
            costs[initialState]=0;

            while(!pq.empty()){
                state src = pq.top();
                path.pb(src);
                pq.pop();

                if(isFinal(src)){
                    isFound = true;
                    finalState = src;
                    break;
                }

                if(visited.find(src)==visited.end()){
                    visited.insert(src);
                }
                

                //use getcost fn

                state temp;

                if(src.data.first!=0){
                    temp = src.emptyLeft();
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                    }
                }

                if(src.data.second!=0){
                    temp = src.emptyRight();
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }

                if(src.data.first<maxSize.first){
                    temp = src.fillLeft(maxSize.first);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }

                if(src.data.second<maxSize.second){
                    temp = src.fillRight(maxSize.second);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }


                if(src.data.second<maxSize.second&&src.data.first>0){
                    temp = src.pourLeft(maxSize.second);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }


                if(src.data.first<maxSize.first&&src.data.second>0){
                    temp = src.pourRight(maxSize.first);
                    if(getCost(temp,costs)>costs[src]+1){
                        costs[temp] = costs[src]+1;
                        pq.push(temp);
                        parent[temp] = src;
                        
                    }
                }
            }
        }

        void printTraversal(){
            for(state& s:path)
                cout<<s;
        }
};

int main(){
    Solver s;
    string choice;
    cin>>choice;

    if(choice=="bfs"){
        s.bfs();
    }

    else if(choice=="dfs"){
        s.dfs();
    }

    else if(choice=="ids"){
        s.ids();
    }

    else if(choice=="ibs"){
        s.ibs();
    }

    else if(choice=="astar"){
        s.astar();
    }

    else if(choice=="bfg"){
        s.bfg();
    }

    else if(choice=="ucs"){
        s.ucs();
    }

    else{
        cout<<"Invalid choice"<<endl;
        return 0;
    }
    
    cout<<"----------------PATH----------------"<<endl;
    s.printPath();

    if(choice!="ids"&&choice!="ibs"){
        cout<<"----------------TRAVERSAL----------------"<<endl;
        s.printTraversal();
    }
    return 0;
}