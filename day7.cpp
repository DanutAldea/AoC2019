#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int n,i,out;
int v[5][3000],w[3000],p1,p2,p3,next,stop,m;
int f[15],x[15];
int sol;
int pozi[5];
int nr[5];

int intcode(int v[], int &i, int amp, int val){

    while(i<=n){
        if(v[i]%100==99)
            break;

        if(v[i]%100==1){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            v[v[i+3]]=p1+p2;
            i+=4;
            continue;
        }

        if(v[i]%100==2){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            v[v[i+3]]=p1*p2;
            i+=4;
            continue;
        }

        if(v[i]%100==3){
            ///cin>>v[v[i+1]];
            if(nr[amp]==0)
                v[v[i+1]]=x[amp];
            else
                v[v[i+1]]=val;
            nr[amp]++;
            i+=2;
            continue;
        }

        if(v[i]%100==4){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];
            i+=2;
            return p1;
            continue;
        }

        if(v[i]%100==5){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            if(p1!=0)
                i=p2;
            else
                i+=3;
            continue;
        }

        if(v[i]%100==6){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            if(p1==0)
                i=p2;
            else
                i+=3;
            continue;
        }

        if(v[i]%100==7){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            if(p1<p2)
                v[v[i+3]]=1;
            else
                v[v[i+3]]=0;
            i+=4;
            continue;
        }

        if(v[i]%100==8){
            if(v[i]/100%10)
                p1=v[i+1];
            else
                p1=v[v[i+1]];

            if(v[i]/1000%10)
                p2=v[i+2];
            else
                p2=v[v[i+2]];

            if(p1==p2)
                v[v[i+3]]=1;
            else
                v[v[i+3]]=0;
            i+=4;
            continue;
        }
    }

    return -1;
}

void bec(int pas){
    if(pas==5){
//        for(int i=0;i<5;i++)
//            cout<<x[i]<<" ";
//        cout<<"\n";

        for(i=0;i<=n;i++)
            v[0][i]=v[1][i]=v[2][i]=v[3][i]=v[4][i]=w[i];
        nr[0]=nr[1]=nr[2]=nr[3]=nr[4]=0;
        pozi[0]=pozi[1]=pozi[2]=pozi[3]=pozi[4]=0;
        out=0;

        while(true){
            out=intcode(v[0],pozi[0],0,out);
            if(out==-1)
                break;
            out=intcode(v[1],pozi[1],1,out);
            out=intcode(v[2],pozi[2],2,out);
            out=intcode(v[3],pozi[3],3,out);
            out=intcode(v[4],pozi[4],4,out);
            m=out;
        }

        sol=max(sol,m);

        return;
    }

    for(int i=5;i<10;i++){
        if(!f[i]){
            f[i]=1;
            x[pas]=i;
            bec(pas+1);
            f[i]=0;
        }
    }
}

int main(){
    while(fin>>w[n])
        n++;
    n--;

    sol=-1;
    bec(0);

    cout<<sol;

    return 0;
}

