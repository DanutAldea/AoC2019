#include <fstream>
#include <iostream>
#define st 5973857
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

char c[1000];
int v[10000000],w[10000000],n,i,j,cnt,x;
int p[]={0,1,0,-1};

int main(){
    fin>>c+1;
    for(i=1;c[i]!=0;i++)
        v[++n]=c[i]-'0';

    /// part 1
    for(int t=100;t;t--){
        for(i=1;i<=n;i++){
            cnt=1; x=0;
            for(j=1;j<=n;j++,cnt++){
                if(cnt==i)
                    x=(x+1)%4,cnt=0;

                w[i]+=v[j]*p[x];
            }
        }

        for(i=1;i<=n;i++)
            v[i]=max(w[i],-w[i])%10,w[i]=0;
    }

    for(i=1;i<=8;i++)
        cout<<v[i];
    cout<<"\n";

    /// part 2
    for(i=0;i<10000;i++)
        for(j=1;j<=n;j++)
            w[i*n+j]=c[j]-'0';
    n*=10000;

    for(i=st+1;i<=n;i++)
        v[i-st]=w[i];
    n=n-st;

    for(int t=100;t;t--){
        cnt=0;
        for(i=n;i;i--){
            cnt+=v[i];
            v[i]=cnt%10;
        }
    }

    for(i=1;i<=8;i++)
        cout<<v[i];

    return 0;
}
