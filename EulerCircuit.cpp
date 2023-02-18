#include<bits/stdc++.h>
using namespace std;

void dfs(int u,vector<queue<pair<int,int>>>&adj,vector<int>&ans,vector<int>&used){
    // adj[u] -> {v,edge_id}
    while(!adj[u].empty()){
        auto [v,id]=adj[u].front();adj[u].pop();
        if(used[id]==1)continue;
        used[id]=1;
        dfs(v,adj,ans,used);
    }ans.push_back(u);
    // ans = u v u
}

int main(){

}