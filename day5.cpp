#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

int n,v[1000],i,j,p1,p2,p3;

int main(){
    while(fin>>v[n])
        n++;
    n--;

    while(i<=n){
        //cout<<"\n"<<i<<" "<<v[i];
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
            cin>>v[v[i+1]];

            i+=2;
            continue;
        }

        if(v[i]%100==4){
            if(v[i]/100%10)
                cout<<v[i+1]<<" ";
            else
                cout<<v[v[i+1]]<<" ";

            i+=2;
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

            if(p1)
                i=p2;
            else
                i+=3;
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

            if(!p1)
                i=p2;
            else
                i+=3;
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


    return 0;
}
