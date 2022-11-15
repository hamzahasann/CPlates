#include<bits/stdc++.h>
using namespace std;

template<class T>
struct Point{
    T x,y;
    Point<T>(T a, T b){
        x=a;y=b;
    }Point<T>(){
        x=0;y=0;
    }
    Point<T> operator+(Point<T> &p){
        Point<T> r;
        r.x=x+p.x;
        r.y=y+p.y;
        return r;
    }Point<T> operator-(Point<T> &p){
        Point<T> r;
        r.x=x-p.x;
        r.y=y-p.y;
        return r;
    }friend ostream& operator<<(ostream&os, Point<T>&p){
        os<<p.x<<" "<<p.y;
        return os;
    }
};
int main(){
    Point<long long>p(1,2);
    Point<long long>q(3,4);
    Point<long long>a=p+q;
    cout<<a.x<<" "<<a.y;
}
