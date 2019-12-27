#include <fstream>
#include <iostream>
#include <algorithm>
#include <deque>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int n,m,i,j,isol,jsol,g,cnt;
char c[100][100],a[100][100];
bool f[100][100];
deque <pair<int,int> > q;
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
int d;
pair<int,int> v[1000];
int r[1000];

int gcd(int a, int b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int bfs(int x, int y){
    int i,j,iv,jv,nexti,nextj;
    int cnt=0;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            f[i][j]=0,a[i][j]=c[i][j];
    q.push_back(make_pair(x,y));
    f[x][y]=1;

    while(!q.empty()){
        i=q.front().x; j=q.front().y;
        q.pop_front();

        for(d=0;d<4;d++){
            iv=i+di[d]; jv=j+dj[d];

            if(iv>=0 && jv>=0 && iv<n && jv<m && f[iv][jv]==0){
                f[iv][jv]=1;
                q.push_back(make_pair(iv,jv));

                if(a[iv][jv]=='#'){
                    cnt++;
                    nexti=iv-x;
                    nextj=jv-y;

                    g=gcd(max(nexti,-nexti),max(nextj,-nextj));
                    nexti/=g;
                    nextj/=g;

                    iv=nexti+x; jv=nextj+y;
                    while(iv>=0 && jv>=0 && iv<n && jv<m){
                        a[iv][jv]='.';
                        iv+=nexti;
                        jv+=nextj;
                    }
                }
            }
        }
    }

    return cnt;
}

int det(pair<int,int> a, pair<int,int> b){
    return a.x*b.y-b.x*a.y;
}

int dist(pair<int,int> a){
    return a.x*a.x+a.y*a.y;
}

inline int cadran(pair<int,int>a){
    if(a.x>=0 && a.y>=0)
        return 1;
    if(a.x>=0 && a.y<=0)
        return 2;
    if(a.x<=0 && a.y<=0)
        return 3;
    if(a.x<=0 && a.y>=0)
        return 4;
}

bool cmp(const pair<int,int> &a, const pair<int,int> &b){
    if(cadran(a)!=cadran (b))
        return cadran(a)<cadran (b);

    if(det(a,b)!=0)
        return det(a,b)<0;
    else
        return dist(a)<dist(b);
}

int main(){
    n=26;
    m=26;

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            fin>>c[i][j];

    int M=0;
    int aux;
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if(c[i][j]=='#'){
                aux=bfs(i,j);

                if(aux>M){
                    isol=i; jsol=j;
                    M=aux;
                }
            }

    cout<<M<<" "<<jsol<<" "<<isol<<"\n";

    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            if((i!=isol || j!=jsol) && c[i][j]=='#')
                v[++cnt]=make_pair(j-jsol,-i+isol);
    n=cnt;
    sort(v+1,v+n+1,cmp);

    cnt=0;
    while(true){
        for(i=1;i<=n;i++){
            if(r[i]==0){
                cnt++;
//                if(cnt<=3 || cnt==10 || cnt==20 || cnt==50 || cnt==100 || cnt==199)
//                    cout<<v[i].x+jsol<<" "<<-(v[i].y-isol)<<"\n";
                if(cnt==200){
                    fout<<(v[i].x+jsol)*100+-(v[i].y-isol);
                    return 0;
                }

                r[i]=1;
                while(det(v[i],v[i+1])==0 && i<n)
                    i++;
            }
        }
    }

    return 0;
}

