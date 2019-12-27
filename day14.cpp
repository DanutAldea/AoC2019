#include <fstream>
#include <iostream>
#include <cstring>
#define inf 1000000000000
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

long long n,m,i,j,k,r,react[100][100],x,stop,sol,st,dr,mid;
char c[100][10],s[1000],e[10];
long long obt[100],cnt[100],rest[100];
bool ok;

void af(){
    for(int i=1;i<=n;i++)
        cout<<c[i]<<" ";
    cout<<"\n";

    for(int i=1;i<=r;i++){
        for(int j=1;j<=n;j++)
            if(react[i][j]){
                cout<<c[j]<<":"<<react[i][j]<<" ";
            }
        cout<<"\n";
    }

    for(int i=1;i<=n;i++)
        cout<<obt[i]<<" ";
}

bool test(int p){
    for(i=3;i<=n;i++)
        cnt[i]=0;
    cnt[1]=inf;
    cnt[2]=-p;

    do{
        for(i=2;i<=n;i++)
            if(cnt[i]<0){
///                x=1;
///                while(cnt[i]+x*react[obt[i]][i]<0)
///                    x++;
                if(-cnt[i]%react[obt[i]][i]==0)
                    x=-cnt[i]/react[obt[i]][i];
                else
                    x=-cnt[i]/react[obt[i]][i]+1;

                for(j=1;j<=n;j++)
                    cnt[j]+=react[obt[i]][j]*x;
            }


        ok=0;
        for(i=2;i<=n;i++)
            if(cnt[i]<0)
                ok=1;
    }while(ok);


    if(cnt[1]>=0)
        return 1;
    else
        return 0;
}

void elem(long long semn){
    long long nr=0;
    while(s[i]>='0' && s[i]<='9'){
        nr=nr*10+s[i]-'0';
        i++;
    }

    i++;

    j=0;
    while(s[i]>='A' && s[i]<='Z')
        e[j++]=s[i++];
    e[j]=NULL;

    for(j=1;j<=n;j++)
        if(strcmp(e,c[j])==0)
            break;
    if(j>n)
        strcpy(c[++n],e);

    react[k][j]=nr*semn;

    if(semn==1){
        obt[j]=k;
    }
}

int main(){
    n++;
    c[n][0]='O'; c[n][1]='R'; c[n][2]='E';
    n++;
    c[n][0]='F'; c[n][1]='U'; c[n][2]='E'; c[n][3]='L';

    r=59;
    for(k=1;k<=r;k++){
        fin.get(s,1000);
        fin.get();

        i=0;

        elem(-1);
        while(s[i]==','){
            i+=2;
            elem(-1);
        }
        i+=4;

        elem(1);
        while(s[i]==','){
            i+=2;
            elem(1);
        }
    }

//    cnt[1]=inf;
//    cnt[2]=-1;
//    do{
//        for(i=1;i<=n;i++)
//            if(cnt[i]<0){
//                if((-cnt[i])%react[obt[i]][i]==0)
//                    x=(-cnt[i])/react[obt[i]][i];
//                else
//                    x=(-cnt[i])/react[obt[i]][i]+1;
//
//                for(j=1;j<=n;j++)
//                    cnt[j]+=react[obt[i]][j]*x;
//            }
//
//
//        ok=0;
//        for(i=1;i<=n;i++)
//            if(cnt[i]<0)
//                ok=1;
//    }while(ok);
//
//    cout<<inf-cnt[1]<<"\n";

//    cin>>i;
//    cout<<test(i);

    st=1; dr=100000000;

    bool q;
    while(st<=dr){
        mid=(st+dr)/2;

        q=test(mid);

        if(q)
            st=mid+1;
        else
            dr=mid-1;
    }
    cout<<dr;

    return 0;
}

