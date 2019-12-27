#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int v[10007],w[10007],n,i,j,x;
char c;

/**
    replacements:
    s-deal into new stack
    c-cut
    i-deal with increment
**/

int main(){
    n=10007;
    for(i=0;i<n;i++)
        v[i]=i;

    while(fin>>c){
        if(c=='s'){
            for(i=0;i<n;i++)
                w[n-1-i]=v[i];
        }

        if(c=='c'){
            fin>>x;
            if(x<0)
                x=n+x;

            for(i=x,j=0;i<n;i++,j++)
                w[j]=v[i];
            for(i=0;i<x;i++,j++)
                w[j]=v[i];
        }

        if(c=='i'){
            fin>>x;

            for(i=0,j=0;i<n;i++,j=(j+x)%n)
                w[j]=v[i];
        }

        for(i=0;i<n;i++)
            v[i]=w[i];
    }

//    for(i=0;i<n;i++)
//        cout<<v[i]<<" ";

    for(i=0;i<n;i++)
        if(v[i]==2019)
            cout<<i;

    return 0;
}

