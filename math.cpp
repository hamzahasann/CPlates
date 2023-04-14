#include<bits/stdc++.h>
using namespace std;

// long long gcdEx(long long a,long long b,long long &x,long long &y){
//     int f=0;
//     if(a>b){swap(a,b);f=1;}
//     if(a==0){
//         x=0;y=1;
//         return b;
//     }long long x1,y1;
//     long long g=gcdEx(b%a,a,x1,y1);
//     x=y1-b/a*x1;
//     y=x1;
//     if(f)swap(x,y);
//     return g;
// }

long long gcdEx(long long a, long long b, long long &x, long long &y){
    if(!b)return x=1,y=0,a;
    long long d=gcdEx(b,a%b,y,x);
    return y-=a/b*x,d;
}
long long crt(long long a,long long m,long long b,long long n){
    if(n>m)swap(a,b),swap(m,n);
    long long x,y,g=gcdEx(m,n,x,y);
    assert((a-b)%g==0);
    x=(b-a)%n*x%n/g*m+a;
    return x<0 ? x+m*n/g:x;
}
long long inv(long long a,long long n){
    if(a==1)return 1;
    return (1-inv(n%a,a)*n)/a+n;
}
int gcd(int u, int v) { // faster
    int shift;
    if (u == 0) return v;
    if (v == 0) return u;
    shift = __builtin_ctz(u | v);
    u >>= __builtin_ctz(u);
    do{
        int m;
        v >>= __builtin_ctz(v);
        v -= u;
        m = v >> 31;
        u += v & m;
        v = (v + m) ^ m;
    } while (v != 0);
    return u << shift;
}
long long findInv(long long x,long long m){
    long long c1,c2;
    gcdEx(x,m,c1,c2);
    if(c1<0){
        c1+=((-c1+m-1)/m)*m;
    }return c1%m;
}
ll f[N],fi[N],inv[N];
void pre(){
    f[0]=fi[0]=f[1]=fi[1]=1;
    inv[0]=inv[1]=1;
    for(int i=2;i<N;i++){
        f[i]=f[i-1]*i%mod;
        inv[i]=inv[mod%i]*(mod-mod/i)%mod;
        fi[i]=fi[i-1]*inv[i]%mod;
    }
}

ll c(int n,int r){
    return f[n]*fi[n-r]%mod*fi[r]%mod;
}
int main(){
    long long x=2,m=1e9+7;
    cout<<findInv(x,m)<<endl;
    cout<<inv(x,m)<<endl;
}

/*

*/