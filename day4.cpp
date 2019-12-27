#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int p,u,cnt,a,ok,i,duble,stk,nr;
int f[10];

bool check(int x){
    a=10;
    ok=1;
    duble=0;

    while(x){
        if(x%10>a){
            ok=0;
            break;
        }

        f[x%10]++;
        a=x%10;
        x/=10;
    }

    for(i=0;i<=9;i++){
        if(f[i]==2)
            duble++;
        f[i]=0;
    }

    if(ok==1 && duble!=0)
        return 1;
    else
        return 0;
}

int main(){
    fin>>p>>u;
    while(p<=u){
        if(check(p))
            cnt++;
        p++;
    }

    fout<<cnt;

    return 0;
}
