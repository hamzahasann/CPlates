#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
vector<int>P(N),S(N);

void create(int u){
    P[u]=u;S[u]=1;
}
int find(int u){
    if(u==P[u])return u;
    return P[u]=find(P[u]);
}
void merge(int u,int v){
    u=find(u);
    v=find(v);
    if(u!=v){
        if(S[u]<S[v]){
            P[u]=v;
            S[v]+=S[u];
        }else{
            P[v]=u;
            S[u]+=S[v];
        }
    }
}
void brute(int n,int m,vector<vector<int>>&adj){
    stack<int>st;
    vector<int> vis(n+1);int c=0;
    for(int i=1;i<=n;i++){
        if(!vis[i]){
            vis[i]=1;
            st.push(i);c++;
            while(!st.empty()){
                int u=st.top();st.pop();
                for(auto v:adj[u]){
                    if(vis[v])continue;
                    st.push(v);
                    vis[v]=1;
                }
            }
        }
    }cout<<"Components(brute): "<<c<<endl;
}
int main(){
    // TEST
    freopen("in.txt","r",stdin);
    // freopen("out.txt","w",stdout);
    int n,m;cin>>n>>m;
    vector<vector<int>>adj(n+1);
    for(int i=1;i<=n;i++)create(i);
    for(int i=0;i<m;i++){
        int u,v;cin>>u>>v;
        adj[u].push_back(v);adj[v].push_back(u);
        merge(u,v);
    }int c=0;
    for(int i=1;i<=n;i++)if(find(i)==i)c++;
    cout<<"Components: "<<c<<endl;
    brute(n,m,adj);

}
