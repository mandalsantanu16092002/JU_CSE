#include <iostream>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#include <chrono>
const int inf = (1e9) + 7;
#define pb push_back
#define pf push_front
#define mp make_pair

vector<tuple<int,int,int>> transitions = {
    {1,0,1},
    {2,0,1},
    {1,1,1},
    {0,2,1},
    {0,1,1}
};

struct state{
    int numMissionary;
    int numCannibal;
    int boat;

    state(int numMissionary, int numCannibal,int boat){
        this->numMissionary = numMissionary;
        this->numCannibal = numCannibal;
        this->boat = boat;
    }

    state(){
        this->numMissionary = 0;
        this->numCannibal = 0;
        this->boat = 1;
    }

    state applyOp(int ind){
        if(boat == 1){
            return state(numMissionary - get<0>(transitions[ind]), numCannibal - get<1>(transitions[ind]), 0);
        }

        return state(numMissionary + get<0>(transitions[ind]), numCannibal + get<1>(transitions[ind]), 1);
    }

    bool operator <(const state &other) const{
        if(numMissionary == other.numMissionary){
            if(numCannibal == other.numCannibal){
                return boat < other.boat;
            }

            return numCannibal < other.numCannibal;
        }

        return numMissionary < other.numMissionary;
    }

    bool operator ==(const state &other) const{
        return numMissionary == other.numMissionary && numCannibal == other.numCannibal && boat == other.boat;
    }

    bool operator !=(const state &other) const{
        return numMissionary != other.numMissionary || numCannibal != other.numCannibal || boat != other.boat;
    }

    
};

ostream& operator <<(ostream& os, const state& s){
    os << s.numMissionary << " " << s.numCannibal << " " << s.boat;
    return os;
}

istream& operator >>(istream& is, state& s){
    is >> s.numMissionary >> s.numCannibal >> s.boat;
    return is;
}

class Solver{
    public:
        set<state> visited;
        vector<state> traversal;
        state initialState;
        state finalState;
        map<state,state> parent;
        int maxMissionary, maxCannibal;
        bool isFound;

        Solver(){
            int numMissionary, numCannibal;
            cin>>numMissionary>>numCannibal;
            initialState = state(numMissionary, numCannibal, 1);
            finalState = state(0,0,0);
            maxMissionary = numMissionary;
            maxCannibal = numCannibal;
            isFound = false;
        }

        bool isValid(state s){
            if(s.numMissionary < 0 || s.numCannibal < 0 || s.numMissionary > maxMissionary || s.numCannibal > maxCannibal){
                return false;
            }

            if(s.numMissionary > 0 && s.numMissionary < s.numCannibal){
                return false;
            }

            if(maxMissionary - s.numMissionary > 0 && maxMissionary - s.numMissionary < maxCannibal - s.numCannibal){
                return false;
            }

            return true;
        }


        int heuristic(state s){
            return s.numMissionary + s.numCannibal;
        }

        void printPath(){

            if(!isFound){
                cout<<"No path found"<<endl;
                return;
            }

            cout<<endl<<"Path found"<<endl;

            state curr = finalState;
            vector<state> path;
            while(curr != initialState){
                path.pb(curr);
                curr = parent[curr];
            }
            path.pb(initialState);
            reverse(path.begin(), path.end());
            for(auto x: path){
                cout<<x<<endl;
            }
        }

        void printTraversal(){
            cout<<endl<<"Traversal"<<endl;
            for(auto x: traversal){
                cout<<x<<endl;
            }
        }

        void bfg(){
            
            auto comparator = [&](state a, state b){
                return heuristic(a) > heuristic(b);
            };

            priority_queue<state, vector<state>, decltype(comparator)> pq(comparator);
            pq.push(initialState);
            visited.insert(initialState);
            parent[initialState] = initialState;

            while(!pq.empty()){
                state curr = pq.top();
                pq.pop();
                traversal.push_back(curr);

                if(curr == finalState){
                    isFound = true;
                    return;
                }

                for(int i = 0; i < transitions.size(); i++){
                    state next = curr.applyOp(i);
                    if(isValid(next) && visited.find(next) == visited.end()){
                        visited.insert(next);
                        parent[next] = curr;
                        pq.push(next);
                    }
                }
            }

        }

        void dfsUtil(state curr){
            if(curr == finalState){
                isFound = true;
                return;
            }

            for(int i = 0; i < transitions.size(); i++){
                state next = curr.applyOp(i);
                if(isValid(next) && visited.find(next) == visited.end()){
                    traversal.push_back(next);
                    visited.insert(next);
                    parent[next] = curr;
                    dfsUtil(next);
                }
            }

            return;
        }

        void dfs(){
            traversal.pb(initialState);
            visited.insert(initialState);
            dfsUtil(initialState);
        }

        void bfs(){
            queue<state> q;

            q.push(initialState);
            visited.insert(initialState);
            parent[initialState] = initialState;

            while(!q.empty()){
                state curr = q.front();
                q.pop();
                traversal.push_back(curr);

                if(curr == finalState){
                    isFound = true;
                    return;
                }

                for(int i = 0; i < transitions.size(); i++){
                    state next = curr.applyOp(i);
                    if(isValid(next) && visited.find(next) == visited.end()){
                        visited.insert(next);
                        parent[next] = curr;
                        q.push(next);

                        if(next == finalState){
                            traversal.push_back(next);
                            isFound = true;
                            return;
                        }
                    }
                }
            }
        }

        void ucs(){
            map<state, int> dist;
            auto comparator = [&](state a, state b){
                return dist[a] > dist[b];
            };

            priority_queue<state, vector<state>, decltype(comparator)> pq(comparator);
            pq.push(initialState);

            dist[initialState] = 0;
            parent[initialState] = initialState;

            while(!pq.empty()){
                state curr = pq.top();
                pq.pop();
                traversal.push_back(curr);

                if(curr == finalState){
                    isFound = true;
                    return;
                }

                for(int i = 0; i < transitions.size(); i++){
                    state next = curr.applyOp(i);
                    if(isValid(next) && (dist.find(next)==dist.end()||dist[next] > dist[curr] + 1)){
                        parent[next] = curr;
                        dist[next] = dist[curr] + 1;
                        pq.push(next);

                        if(next == finalState){
                            traversal.push_back(next);
                            isFound = true;
                            return;
                        }
                    }
                }
            }
        }

        void astar(){
            map<state, int> dist;
            auto comparator = [&](state a, state b){
                return dist[a] + heuristic(a) > dist[b] + heuristic(b);
            };

            priority_queue<state, vector<state>, decltype(comparator)> pq(comparator);
            pq.push(initialState);

            dist[initialState] = 0;
            parent[initialState] = initialState;

            while(!pq.empty()){
                state curr = pq.top();
                pq.pop();
                traversal.push_back(curr);

                if(curr == finalState){
                    isFound = true;
                    return;
                }

                for(int i = 0; i < transitions.size(); i++){
                    state next = curr.applyOp(i);
                    if(isValid(next) && (dist.find(next)==dist.end()||dist[next] > dist[curr] + 1)){
                        parent[next] = curr;
                        dist[next] = dist[curr] + 1;
                        pq.push(next);

                        if(next == finalState){
                            traversal.push_back(next);
                            isFound = true;
                            return;
                        }
                    }
                }
            }
        }

};

int main(){
    Solver solver;
    string choice;

    cin>>choice;

    cout<<choice<<endl<<endl;

    if(choice == "bfs"){
        solver.bfs();

    }else if(choice == "dfs"){
        solver.dfs();
    }
    else if(choice == "bfg"){
        solver.bfg();
    }
    else if(choice == "ucs"){
        solver.ucs();
    }
    else if(choice == "astar"){
        solver.astar();
    }
    solver.printPath();
    solver.printTraversal();
}