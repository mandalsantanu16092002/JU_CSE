#include<iostream>
#include <bits/stdc++.h>
int main(){
std::vector<std::vector<int>>v{{0,-1},{0,1},{1,0},{-1,0}};
std::vector<std::vector<std::vector<int>>>states;
std::queue<std::vector<std::vector<std::vector<int>>>>q;
std::vector<std::vector<int>>initial{{1,2,3},{0,4,6},{7,5,8}};
std::vector<std::vector<int>>goal{{1,2,3},{4,5,6},{7,8,0}};
std::vector<std::vector<std::vector<int>>>temp;
temp.push_back(initial);
q.push(temp);
int count=1;
while(!q.empty()){
    // sleep(2);
    temp=q.front();
    q.pop();
    if(temp[temp.size()-1]==goal){
        int count=1;
        for(auto i:temp){
            std::cout<<"state "<<count++<<':'<<'\n';
            for(auto j:i){
                for(auto k:j){
                    std::cout<<k<<'\t';
                }
                std::cout<<'\n';
            }
            std::cout<<'\n';
        }
        break;
    }
    bool present=false;
    for(auto i:states){
        if(i==temp[temp.size()-1])
            present=true;
    }
    if(!present){
        states.push_back(temp[temp.size()-1]);
        // std::cout<<'\n'<<count++<<"state :"<<'\n';
        // for(auto i:temp[temp.size()-1]){
        //     for(auto j:i){
        //         std::cout<<j<<'\t';
        //     }
        //     std::cout<<endl;
        // }

        std::vector<std::vector<int>>state=temp[temp.size()-1];
        std::vector<std::vector<int>>state1;
        for(int i=0;i<state.size();i++){
            for(int j=0;j<state[0].size();j++){
                if(state[i][j]==0){
                    for(auto k:v){
                        state1=state;
                        if(i+k[0]>=0 && i+k[0]<3 && j+k[1]>=0 && j+k[1]<3){
                            state1[i][j]=state1[i+k[0]][j+k[1]];
                            state1[i+k[0]][j+k[1]]=0;
                            temp.push_back(state1);
                            q.push(temp);
                            temp.pop_back();
                        }
                    }
                }
            }
        }
    }
}
return 0;
}