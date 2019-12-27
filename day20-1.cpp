#include <iostream>
#include <fstream>
#include <deque>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

char c[1000][1000],vec;
int n,m,i,j,v[1000][1000],cnt,is,js,iv,jv;
pair<pair<int,int>,pair<int,int> > portal[30][30],gate;
pair<int,int> x,p[1000][1000];
bool f[1000][1000];

int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
int d;

deque <pair<int,int> > q;

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
//            cout<<char(i+'A')<<char(j+'A')<<" "<<gate.x.x<<" "<<gate.x.y<<" | "<<gate.y.x<<" "<<gate.y.y<<"\n";

            p[gate.x.x][gate.x.y]=gate.y;
            f[gate.x.x][gate.x.y]=1;
            p[gate.y.x][gate.y.y]=gate.x;
            f[gate.y.x][gate.y.y]=1;
        }

    v[portal[0][0].x.x][portal[0][0].x.y]=1;
    q.push_back(make_pair(portal[0][0].x.x,portal[0][0].x.y));
    is=portal[25][25].x.x;
    js=portal[25][25].x.y;

//    cout<<is<<" "<<js;

    while(!q.empty()){
        i=q.front().x; j=q.front().y;
        q.pop_front();
        for(d=0;d<4;d++){
            iv=i+di[d]; jv=j+dj[d];
            if(c[iv][jv]=='.' && v[iv][jv]==0){
                v[iv][jv]=v[i][j]+1;
                q.push_back(make_pair(iv,jv));
            }
        }

        if(f[i][j]){
            iv=p[i][j].x;
            jv=p[i][j].y;

            if(v[iv][jv]==0){
                v[iv][jv]=v[i][j]+1;
                q.push_back(make_pair(iv,jv));
            }
        }
    }

    cout<<v[is][js]-1;

    return 0;
}

