#include<bits/stdc++.h>
using namespace std;

template<class T>
struct BIT{
    int n;vector<T>t;
    BIT(int _n){
        n=_n;t.resize(n);
    }void update(int i,T k){
        while(i<n){
            t[i]+=k;
            i+=i&-i;
        }
    }T pref(int i){
        int res=0;
        while(i>0){
            res+=t[i];
            i-=i&-i;
        }return res;
    }T query(int l,int r){
        return pref(r)-pref(l-1);
    }
};
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
    // BIT<int> b(10+1);
    // b.update(1,1);
    // b.update(2,3);
    // b.update(7,2);
    // cout<<b.query(1,10);
    // cout<<b.query(1,6);
    // cout<<b.query(2,6);
}
