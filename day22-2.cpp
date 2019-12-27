#include <iostream>
#include <fstream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

typedef __int128_t ll;
int c,x;
ll n,exp;

/**
    replacements:
    s-deal into new stack
    c-cut
    i-deal with increment
**/

ll pow(ll base, ll exp){
    if(exp==0)
        return 1;
    ll a=pow(base, exp/2);
    a=a*a%n;
    if(exp%2==1)
        return (a*base)%n;
    else
        return a;
}

ll inv_mod(ll b){
    return pow(b, n-2);
}

struct Mat{
    ll a,b,c,d;

    Mat() {}
    Mat(ll a, ll b, ll c, ll d): a(a), b(b), c(c), d(d) {}

    Mat operator*(const Mat o) const{
        return Mat(
            ((a*o.a+b*o.c)%n+n)%n,
            ((a*o.b+b*o.d)%n+n)%n,
            ((c*o.a+d*o.c)%n+n)%n,
            ((c*o.b+d*o.d)%n+n)%n
        );
    }
};

Mat Cut(ll c){
    return Mat(1,c,0,1);
}

Mat Stack(){
    return Mat(-1,n-1,0,1);
}

Mat Increment(ll num){
    return Mat(inv_mod(num),0,0,1);
}

Mat pow(const Mat m, ll exp){
    if(exp==0)
        return Mat(1,0,0,1);
    Mat ans=pow(m, exp/2);
    ans=ans*ans;
    if(exp&1)
        return m*ans;
    else
        return ans;
}

ll part2;
char s;

int main(){
    n=119315717514047;
    exp=101741582076661;
    Mat m(1,0,0,1);

    while(fin>>s){
        if(s=='c'){
            fin>>c;
            m=m*Cut(c);
        }
        if(s=='s'){
            m=m*Stack();
        }
        if(s=='i'){
            fin>>x;
            m=m*Increment(x);
        }
    }

    m=pow(m,exp);
    part2=(m.a*2020+m.b)%n;

    cout<<(long long) part2;

    return 0;
}
