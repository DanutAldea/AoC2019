#include <fstream>
#include <map>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int n,m,i,j,x,y,d,nr,sol,cnt;
char c[2000];
int dx[]={-1,0,1,0};
int dy[]={0,1,0,-1};

map <pair<int,int>,int > v;

int main(){
    sol=1000000;

    x=0, y=0, cnt=1;
    fin>>c;
    for(i=0;c[i]!=0;i++){
        if(c[i]=='U') d=0; if(c[i]=='R') d=1;
        if(c[i]=='D') d=2; if(c[i]=='L') d=3;
        i++;

        nr=0;
        while(c[i]>='0' && c[i]<='9'){
            nr=nr*10+c[i]-'0';
            i++;
        }

        for(j=1;j<=nr;j++,cnt++){
            x+=dx[d]; y+=dy[d];
            if(v[make_pair(x,y)]==0)
                v[make_pair(x,y)]=cnt;
        }
    }

    x=0, y=0, cnt=1;
    fin>>c;
    for(i=0;c[i]!=0;i++){
        if(c[i]=='U') d=0; if(c[i]=='R') d=1;
        if(c[i]=='D') d=2; if(c[i]=='L') d=3;
        i++;

        nr=0;
        while(c[i]>='0' && c[i]<='9'){
            nr=nr*10+c[i]-'0';
            i++;
        }

        for(j=1;j<=nr;j++,cnt++){
            x+=dx[d]; y+=dy[d];
            if(v[make_pair(x,y)]!=0)
                sol=min(sol,cnt+v[make_pair(x,y)]);
        }
    }

    fout<<sol;

    return 0;
}

