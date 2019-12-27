#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

char c[10][10],v[10][10];
int i,j,x,p,cnt;
bitset <70000000> bio;
int d;
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};

void af(){
    for(i=1;i<=5;i++,cout<<"\n")
        for(j=1;j<=5;j++)
            cout<<c[i][j];
    cout<<"\n";
}

int main(){
    p=1;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++){
            fin>>c[i][j];
            if(c[i][j]=='#')
                x+=p;
            p*=2;
        }

    while(!bio[x]){

        bio[x]=1;
        for(i=1;i<=5;i++)
            for(j=1;j<=5;j++){
                cnt=0;
                for(d=0;d<4;d++)
                    if(c[i+di[d]][j+dj[d]]=='#')
                        cnt++;

                if(c[i][j]=='#'){
                    if(cnt==1)
                        v[i][j]='#';
                    else
                        v[i][j]='.';
                }else{
                    if(cnt==1 || cnt==2)
                        v[i][j]='#';
                    else
                        v[i][j]='.';
                }
            }

        x=0;
        p=1;
        for(i=1;i<=5;i++)
            for(j=1;j<=5;j++){
                c[i][j]=v[i][j];
                if(c[i][j]=='#')
                    x+=p;
                p*=2;
            }
    }

    cout<<x;

    return 0;
}
