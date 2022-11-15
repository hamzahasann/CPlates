#include<bits/stdc++.h>
using namespace std;

const int N=1000;
vector<int>bit(N+1);
void update(int i,int k){
    while(i<=N){
        bit[i]+=k;
        i+=i&-i;
    }
}
int pref(int i){
    int res=0;
    while(i>0){
        res+=bit[i];
        i-=i&-i;
    }return res;
}
int query(int l,int r){
    return pref(r)-pref(l-1);
}
vector<int>a(N+1);
int brute(int l,int r){
    int res=0;
    for(int i=l;i<=r;i++)res+=a[i];
    return res;
}
int main(){
    // freopen("out.txt","r",stdin);//freopen("out.txt","w",stdout);
    // int n;cin>>n;
    // for(int i=1;i<=N;i++){
    //     cin>>a[i];
    //     update(i,a[i]);
    // }int q;cin>>q;
    // for(int i=0;i<q;i++){
    //     int l,r;cin>>l>>r;
    //     if(brute(l,r)!=query(l,r)){
    //         cout<<"NOT MATCH\n";
    //     }
    // }
}
