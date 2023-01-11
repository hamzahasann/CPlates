#include<bits/stdc++.h>
using namespace std;

// find shortest augmenting path
bool bfs_hopcroft_karp(vector<vector<int>>&adj1,vector<int>&mt1,vector<int>&mt2,vector<int>&d){
    queue<int>q;for(int i=0;i<d.size();i++)d[i]=1e9;
    for(int i=1;i<mt1.size();i++){
        if(mt1[i]==0){
            d[i]=0;q.push(i);
        }
    }while(!q.empty()){
        int u=q.front();q.pop();
        if(d[u]<d[0]){
            for(auto v:adj1[u]){
                if(d[mt2[v]]==1e9){
                    d[mt2[v]]=d[u]+1;
                    q.push(mt2[v]);
                }
            }
        }
    }if(d[0]!=1e9)return true; // found augmenting path
    return false;
}

bool dfs_hopcroft_karp(int u,vector<vector<int>>&adj1,vector<int>&mt1,vector<int>&mt2,vector<int>&d){
    if(u!=0){
        for(auto v:adj1[u]){
            if(d[mt2[v]]==d[u]+1){
                if(dfs_hopcroft_karp(mt2[v],adj1,mt1,mt2,d)){
                    mt2[v]=u;mt1[u]=v;
                    return true;
                }
            }
        }d[u]=1e9;
        return false;
    }return true;
}
int hopcroft_karp(vector<vector<int>>&adj1,int n1,int n2){
    int cnt=0;
    vector<int>mt1(n1+1),mt2(n2+1),d(n1+1);
    while(bfs_hopcroft_karp(adj1,mt1,mt2,d)){
        for(int i=1;i<=n1;i++){
            if(mt1[i]==0){
                if(dfs_hopcroft_karp(i,adj1,mt1,mt2,d))
                cnt+=1;
            }
        }
    }return cnt;
}
int main(){
    cout<<hopcroft_karp(adj,n1,n2)<<endl;
}
