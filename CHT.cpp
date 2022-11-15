#include<bits/stdc++.h>
using namespace std;

// Line, x  -> Line useful x onwards
struct Line{
    long long m,c;
    Line(long long _m,long long _c){
        m=_m;c=_c;
    }long long eval(long long x){
        return m*x+c;
    }long long intersect(Line l2){
        return (l2.c-c+m-l2.m-1)/(m-l2.m);
    }
};
deque<pair<Line,long long>>dq;
void add(Line l){
    while(!dq.empty() && dq.back().second>=l.intersect(dq.back().first))dq.pop_back();
    if(dq.empty()){
        dq.push_back({l,0});
    }else{
        dq.push_back({l,dq.back().first.intersect(l)});
    }
}

int main(){

}
