#include<iostream>
using namespace std;

struct int128{
    long long H,L;
    int128(){
        H=0;L=0;
    }int128(long long _H,long long _L){
        H=_H;L=_L;
    }
    int128 operator+(int128 a){
        int128 r;
        r.L=L+a.L;
        r.H=H+a.H+(r.L<L);
        return r;
    }int128 operator-(int128 a){
        int128 r;
        r.L=L-a.L;
        r.H=H-a.H-(r.L>L);
        return r;
    }
};
int main(){
    int128 a(0,1LL<<61),b=a;
    a=a+b;
    cout<<a.H<<" "<<a.L<<endl;
}
