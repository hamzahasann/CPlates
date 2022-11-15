#include<bits/stdc++.h>
using namespace std;

long long gcdEx(long long a,long long b,long long &x,long long &y){
    int f=0;
    if(a>b){swap(a,b);f=1;}
    if(a==0){
        x=0;y=1;
        return b;
    }long long x1,y1;
    long long g=gcdEx(b%a,a,x1,y1);
    x=y1-b/a*x1;
    y=x1;
    if(f)swap(x,y);
    return g;
}
long long inv(long long a,long long n){
    if(a==1)return 1;
    return (1-inv(n%a,a)*n)/a+n;
}
long long findInv(long long x,long long m){
    long long c1,c2;
    gcdEx(x,m,c1,c2);
    if(c1<0){
        c1+=((-c1+m-1)/m)*m;
    }return c1%m;
}
int main(){
    long long x=2,m=1e9+7;
    cout<<findInv(x,m)<<endl;
    cout<<inv(x,m)<<endl;
}

/*

*/