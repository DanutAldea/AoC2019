#include <fstream>
#include <iostream>
#include <deque>
#include <bitset>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

long long n,v[60][2000000],i[60],j,p1,p2,p3,base,stop[60],send[60],cnt[60],lasty,idle;
deque<long long> pack[260];
long long q,x,y;

void intcode(long long calc, long long v[], long long &i){
    if(stop[calc])
        return;

    while(i<=n){

        if(v[i]%100==99)
            break;

        if(v[i]%100==1){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(v[i]/10000%10==2) v[v[i+3]+base]=p1+p2;
            else v[v[i+3]]=p1+p2;

            i+=4;
            continue;
        }

        if(v[i]%100==2){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(v[i]/10000%10==2) v[v[i+3]+base]=p1*p2;
            else v[v[i+3]]=p1*p2;

            i+=4;
            continue;
        }

        if(v[i]%100==3){
            if(pack[calc].empty()){
                p1=-1;
            }else{
                p1=pack[calc].front();
                pack[calc].pop_front();
            }

            if(v[i]/100%10==2) v[v[i+1]+base]=p1;
            else v[v[i+1]]=p1;

            i+=2;

            if(p1==-1){
                return;
            }else{
                continue;
            }
        }

        if(v[i]%100==4){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(cnt[calc]==0){
                send[calc]=p1;
            }else{
                if(send[calc]==255)
                    q++;

                if(send[calc]<50 | send[calc]==255)
                    pack[send[calc]].push_back(p1);
            }
            cnt[calc]=(cnt[calc]+1)%3;

            i+=2;
            continue;
        }

        if(v[i]%100==5){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(p1)
                i=p2;
            else
                i+=3;
            continue;
        }

        if(v[i]%100==6){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(!p1)
                i=p2;
            else
                i+=3;
            continue;
        }

        if(v[i]%100==7){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(p1<p2)
                if(v[i]/10000%10==2) v[v[i+3]+base]=1;
                else v[v[i+3]]=1;
            else
                if(v[i]/10000%10==2) v[v[i+3]+base]=0;
                else v[v[i+3]]=0;

            i+=4;
            continue;
        }

        if(v[i]%100==8){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            if(v[i]/1000%10==1) p2=v[i+2];
            else if(v[i]/1000%10==2) p2=v[v[i+2]+base];
            else p2=v[v[i+2]];

            if(p1==p2)
                if(v[i]/10000%10==2) v[v[i+3]+base]=1;
                else v[v[i+3]]=1;
            else
                if(v[i]/10000%10==2) v[v[i+3]+base]=0;
                else v[v[i+3]]=0;

            i+=4;
            continue;
        }

        if(v[i]%100==9){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            base+=p1;

            i+=2;
            continue;
        }
    }

    stop[calc]=1;
}

int main(){
    while(fin>>v[0][n]){
        for(j=1;j<50;j++)
            v[j][n]=v[0][n];

        n++;
    }
    n--;

    for(j=0;j<50;j++)
        pack[j].push_back(j);

    while(true){
        for(j=0;j<50;j++)
            intcode(j,v[j],i[j]);

        if(q==2)
            cout<<pack[255].back()<<" ",q++;

        for(j=0;j<50;j++)
            if(pack[j].size()!=0)
                break;

        if(j==50){
            idle++;

            if(idle==10){
                y=pack[255].back();
                pack[255].pop_back();
                x=pack[255].back();

                if(y==lasty){
                    cout<<y;
                    return 0;
                }

                lasty=y;

                pack[0].push_back(x);
                pack[0].push_back(y);
            }
        }else
            idle=0;
    }

    return 0;
}
