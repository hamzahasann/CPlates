#include<bits/stdc++.h>
using namespace std;

long long gcd(long long a, long long b){
    if(a<b) swap(a,b);
    if(b==0) return a;
    return gcd(a%b,b);
}

struct Fraction{
    long long p,q;
    Fraction(){
        p=0;q=1;
    }Fraction(long long _p){
        p=_p;q=1;
    }Fraction(long long _p,long long _q){
        p=_p;q=_q;
        this->reduce();
    }void reduce(){
        long long g=gcd(abs(p),abs(q));
        p/=g;q/=g;
    }Fraction operator+(Fraction f){
        Fraction r;
        long long lcm=q/gcd(q,f.q)*f.q;
        r.p=p*lcm/q+f.p*lcm/f.q;
        r.q=lcm;
        r.reduce();
        return r;
    }Fraction operator-(Fraction f){
        f.p=-f.p;
        return *this+f;
    }Fraction operator*(Fraction f){
        Fraction r;
        r.p=p*f.p;
        r.q=q*f.q;
        r.reduce();
        return r;
    }Fraction operator/(Fraction f){
        swap(f.p,f.q);
        return *this*f;
    }Fraction& operator+=(Fraction f){
        *this=*this+f;
        return *this;
    }Fraction& operator-=(Fraction f){
        *this=*this-f;
        return *this;
    }Fraction& operator*=(Fraction f){
        *this=*this*f;
        return *this;
    }Fraction& operator/=(Fraction f){
        *this=*this/f;
        return *this;
    }bool operator==(Fraction f){
        return p==f.p && q==f.q;
    }bool operator!=(Fraction f){
        return !(*this==f);
    }bool operator<(Fraction f){
        Fraction r;
        r=*this-f;
        return r.p<0;
    }bool operator>(Fraction f){
        Fraction r;
        r=*this-f;
        return r.p>0;
    }bool operator<=(Fraction f){
        return !(*this>f);
    }bool operator>=(Fraction f){
        return !(*this<f);
    }
    friend ostream& operator<<(ostream& os,Fraction f){
        os<<f.p<<"/"<<f.q;
        return os;
    }
};
int main(){
    Fraction a(2,3),b(3);
}
