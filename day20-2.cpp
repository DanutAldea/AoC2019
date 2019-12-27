#include <iostream>
#include <fstream>
#include <deque>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

struct poz{
    int i;
    int j;
    int lvl;
};

char c[200][200],vec;
int n,m,i,j,v[200][200][30],cnt,is,js,iv,jv,lvl;
pair<pair<int,int>,pair<int,int> > portal[30][30],gate;
pair<int,int> x,p[200][200];
int f[200][200];

int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
int d;

deque <poz > q;

inline poz make_poz(int i, int j, int lvl){
    poz x;
    x.i=i;
    x.j=j;
    x.lvl=lvl;
    return x;
}

int main(){
    n=135;
    m=129;

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            fin>>c[i][j];

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++){

            if(c[i][j]>='A' && c[i][j]<='Z'){

                vec=0; x=make_pair(0,0);
                for(d=0;d<4;d++){
                    if(c[i+di[d]][j+dj[d]]>='A' && c[i+di[d]][j+dj[d]]<='Z')
                        vec=c[i+di[d]][j+dj[d]]-'A';
                    if(c[i+di[d]][j+dj[d]]=='.')
                        x=make_pair(i+di[d],j+dj[d]);
                }

                if(x==make_pair(0,0))
                    continue;

                if(vec>c[i][j]-'A'){
                    if(portal[c[i][j]-'A'][vec].x==make_pair(0,0))
                        portal[c[i][j]-'A'][vec].x=x;
                    else
                        portal[c[i][j]-'A'][vec].y=x;
                }else{
                    if(portal[vec][c[i][j]-'A'].x==make_pair(0,0))
                        portal[vec][c[i][j]-'A'].x=x;
                    else
                        portal[vec][c[i][j]-'A'].y=x;
                }
            }
        }

    for(i=0;i<26;i++)
        for(j=i;j<26;j++){
            if((i==0 && j==0) || (i==25 && j==25))
                continue;

            gate=portal[i][j];
            if(portal[i][j].x!=make_pair(0,0))
            cout<<char(i+'A')<<char(j+'A')<<" "<<gate.x.x<<" "<<gate.x.y<<" | "<<gate.y.x<<" "<<gate.y.y<<"\n",cnt++;

            p[gate.x.x][gate.x.y]=gate.y;
            if(gate.x.x==3 || gate.x.x==n-2 || gate.x.y==3 || gate.x.y==m-2)
                f[gate.x.x][gate.x.y]=-1;
            else
                f[gate.x.x][gate.x.y]=1;

            p[gate.y.x][gate.y.y]=gate.x;
            if(gate.y.x==3 || gate.y.x==n-2 || gate.y.y==3 || gate.y.y==m-2)
                f[gate.y.x][gate.y.y]=-1;
            else
                f[gate.y.x][gate.y.y]=1;
        }

    cout<<cnt<<"\n\n";

    v[portal[0][0].x.x][portal[0][0].x.y][0]=1;
    q.push_back(make_poz(portal[0][0].x.x, portal[0][0].x.y, 0));
    is=portal[25][25].x.x;
    js=portal[25][25].x.y;

    for(i=1;i<=n;i++,fout<<"\n")
        for(j=1;j<=m;j++)
            if(f[i][j]==0)
                fout<<c[i][j];
            else
                if(f[i][j]==-1)
                    fout<<"i";
                else
                    fout<<"o";

    while(!v[is][js][0] && !q.empty()){
        i=q.front().i; j=q.front().j; lvl=q.front().lvl;
        fout<<i<<" "<<j<<" "<<lvl<<"\n";
        q.pop_front();
        for(d=0;d<4;d++){
            iv=i+di[d]; jv=j+dj[d];
            if(c[iv][jv]=='.' && v[iv][jv][lvl]==0){
                v[iv][jv][lvl]=v[i][j][lvl]+1;
                q.push_back(make_poz(iv,jv,lvl));
            }
        }

        if(f[i][j]!=0){
            iv=p[i][j].x;
            jv=p[i][j].y;

            if(lvl+f[i][j]<30 && lvl+f[i][j]>=0)
                if(v[iv][jv][lvl+f[i][j]]==0){
                    v[iv][jv][lvl+f[i][j]]=v[i][j][lvl]+1;
                    q.push_back(make_poz(iv,jv,lvl+f[i][j]));
                }
        }
    }

    cout<<v[is][js][0]-1;

    return 0;
}
