#include <fstream>
#include <iostream>
#include <map>
#include <deque>
#include <bitset>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

struct poz{
    int i;
    int j;
    int stare;
};

poz make_poz(int i, int j, int stare){
    poz x;
    x.i=i;  x.j=j;
    x.stare=stare;

    return x;
}

map<int,int> v[82][82];
char c[82][82];
int n,i,j,iv,jv,d,stare;
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
deque <poz> q;

int key[5],k,cnt;
bitset <26> f;

int bfs(){
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        stare=q.front().stare;
        q.pop_front();

        for(d=0;d<4;d++){
            iv=i+di[d];
            jv=j+dj[d];

            if(c[iv][jv]!='#'){

                if(c[iv][jv]>='A' && c[iv][jv]<='Z'){
                    if((stare & (1<<(c[iv][jv]-'A')))!=0){
                        if(v[iv][jv].find(stare) == v[iv][jv].end()){
                            v[iv][jv][stare]=1+v[i][j][stare];
                            q.push_back(make_poz(iv,jv,stare));
                        }
                    }
                }

                if(c[iv][jv]=='.' || c[iv][jv]=='@'){
                    if(v[iv][jv].find(stare) == v[iv][jv].end()){
                        v[iv][jv][stare]=1+v[i][j][stare];
                        q.push_back(make_poz(iv,jv,stare));
                    }
                }

                if(c[iv][jv]>='a' && c[iv][jv]<='z'){
                    if(v[iv][jv].find( (stare|(1<<(c[iv][jv]-'a'))) ) == v[iv][jv].end()){
                        v[iv][jv][stare|(1<<(c[iv][jv]-'a'))]=1+v[i][j][stare];
                        q.push_back(make_poz(iv,jv,stare|(1<<(c[iv][jv]-'a'))));
                    }
                }
            }
        }
    }

    int sol=1000000000;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(v[i][j].find( key[k] )!=v[i][j].end())
                sol=min(sol,v[i][j][ key[k] ]);
    return sol;
}

int main(){
    n=81;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++){
            fin>>c[i][j];
            /**
            part 1

            if(c[i][j]=='@'){
                q.push_back(make_poz(i,j,0));
                v[i][j][0]=0;
                cout<<i<<" "<<j<<"\n";
            }

            **/
        }

/*
    while(!q.empty()){
        i=q.front().i;
        j=q.front().j;
        stare=q.front().stare;
        q.pop_front();

        for(d=0;d<4;d++){
            iv=i+di[d];
            jv=j+dj[d];

            if(c[iv][jv]!='#'){

                if(c[iv][jv]>='A' && c[iv][jv]<='Z'){
                    if((stare & (1<<(c[iv][jv]-'A')))!=0){
                        if(v[iv][jv].find(stare) == v[iv][jv].end()){
                            v[iv][jv][stare]=1+v[i][j][stare];
                            q.push_back(make_poz(iv,jv,stare));
                        }
                    }
                }

                if(c[iv][jv]=='.' || c[iv][jv]=='@'){
                    if(v[iv][jv].find(stare) == v[iv][jv].end()){
                        v[iv][jv][stare]=1+v[i][j][stare];
                        q.push_back(make_poz(iv,jv,stare));
                    }
                }

                if(c[iv][jv]>='a' && c[iv][jv]<='z'){
                    if(v[iv][jv].find( (stare|(1<<(c[iv][jv]-'a'))) ) == v[iv][jv].end()){
                        v[iv][jv][stare|(1<<(c[iv][jv]-'a'))]=1+v[i][j][stare];
                        q.push_back(make_poz(iv,jv,stare|(1<<(c[iv][jv]-'a'))));
                    }
                }
            }
        }
    }

    int sol=1000000000;
    for(i=1;i<=n;i++)
        for(j=1;j<=n;j++)
            if(v[i][j].find( (1<<26)-1 )!=v[i][j].end())
                sol=min(sol,v[i][j][(1<<26)-1]);
    cout<<sol<<"\n";
*/

    ///vault 1
    k=1;
    for(i=1;i<=n/2;i++)
        for(j=1;j<=n/2;j++)
            if(c[i][j]>='a' && c[i][j]<='z'){
                f[c[i][j]-'a']=1;
                key[k]|=(1<<(c[i][j]-'a'));
            }

    for(i=1;i<=n/2;i++)
        for(j=1;j<=n/2;j++)
            if(c[i][j]>='A' && c[i][j]<='Z')
                if(!f[c[i][j]-'A'])
                    c[i][j]='.'; ///cheia va fi recuperata de alt robotzel

    for(i=1;i<=n/2;i++,cout<<"\n")
        for(j=1;j<=n/2;j++)
            cout<<c[i][j];

    v[40][40][0]=0;
    q.push_back(make_poz(40,40,0));
    cnt+=bfs();

    ///vault 2
    k=2; f.reset();
    for(i=1;i<=n/2;i++)
        for(j=n/2+1;j<=n;j++)
            if(c[i][j]>='a' && c[i][j]<='z'){
                f[c[i][j]-'a']=1;
                key[k]|=(1<<(c[i][j]-'a'));
            }

    for(i=1;i<=n/2;i++)
        for(j=n/2+1;j<=n;j++)
            if(c[i][j]>='A' && c[i][j]<='Z')
                if(!f[c[i][j]-'A'])
                    c[i][j]='.'; ///cheia va fi recuperata de alt robotzel
    v[40][42][0]=0;
    q.push_back(make_poz(40,42,0));
    cnt+=bfs();

    ///vault 3
    k=3; f.reset();
    for(i=n/2+1;i<=n;i++)
        for(j=1;j<=n/2;j++)
            if(c[i][j]>='a' && c[i][j]<='z'){
                f[c[i][j]-'a']=1;
                key[k]|=(1<<(c[i][j]-'a'));
            }

    for(i=n/2+1;i<=n;i++)
        for(j=1;j<=n/2;j++)
            if(c[i][j]>='A' && c[i][j]<='Z')
                if(!f[c[i][j]-'A'])
                    c[i][j]='.'; ///cheia va fi recuperata de alt robotzel
    v[42][40][0]=0;
    q.push_back(make_poz(42,40,0));
    cnt+=bfs();

    ///vault 4
    k=4; f.reset();
    for(i=n/2+1;i<=n;i++)
        for(j=n/2+1;j<=n;j++)
            if(c[i][j]>='a' && c[i][j]<='z'){
                f[c[i][j]-'a']=1;
                key[k]|=(1<<(c[i][j]-'a'));
            }

    for(i=n/2+1;i<=n;i++)
        for(j=n/2+1;j<=n;j++)
            if(c[i][j]>='A' && c[i][j]<='Z')
                if(!f[c[i][j]-'A'])
                    c[i][j]='.'; ///cheia va fi recuperata de alt robotzel
    v[42][42][0]=0;
    q.push_back(make_poz(42,42,0));
    cnt+=bfs();

    cout<<cnt;

    return 0;
}
