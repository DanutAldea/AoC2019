#include <fstream>
#include <iostream>
#include <vector>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int n,cnt,d[2000],i,j,k,f[2000],you,san;
char x[4],y[4];
char v[2000][4];
vector <int> l[2000];
long long suma;
int niv[2000];

void dfs(int nod){
    cnt++;
    f[nod]=cnt;
    for(int i=0;i<l[nod].size();i++){
        int vec=l[nod][i];

        if(f[vec]==0)
            dfs(vec);
        d[nod]+=1+d[vec];
    }
    cnt--;
}

int main(){
    while(fin>>x[1]){
        fin>>x[2]>>x[3];
        fin>>y[1]>>y[1]>>y[2]>>y[3];

        for(i=1;i<=n;i++)
            if(x[1]==v[i][1] && x[2]==v[i][2] && x[3]==v[i][3])
                break;

        if(i>n){
            n++;
            v[n][1]=x[1];
            v[n][2]=x[2];
            v[n][3]=x[3];
        }

        for(j=1;j<=n;j++)
            if(y[1]==v[j][1] && y[2]==v[j][2] && y[3]==v[j][3])
                break;

        if(j>n){
            n++;
            v[n][1]=y[1];
            v[n][2]=y[2];
            v[n][3]=y[3];
        }

        l[i].push_back(j);
        l[j].push_back(i);
    }

    for(i=1;i<=n;i++){
        if(v[i][1]=='Y' && v[i][2]=='O' && v[i][3]=='U')
            you=i;
        if(v[i][1]=='S' && v[i][2]=='A' && v[i][3]=='N')
            san=i;
    }

    dfs(you);
    fout<<f[san]-3;

//    for(i=1;i<=n;i++)
//        cout<<v[i][1]<<v[i][2]<<v[i][3]<<" "<<f[i]<<"\n";

    return 0;
}

