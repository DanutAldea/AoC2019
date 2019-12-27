#include  <fstream>
#include <iostream>
#include <cmath>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

struct planet{
    long long x;
    long long y;
    long long z;

    long long vx;
    long long vy;
    long long vz;
} v[5],st[5];

unsigned long long i,j,k,sol,perx,pery,perz,g,d,dx,dy,dz;

long long gcd(long long a, long long b){
    while(b){
        a%=b;
        swap(a,b);
    }
    return a;
}

int main(){
    for(i=1;i<=4;i++)
        fin>>v[i].x>>v[i].y>>v[i].z,st[i]=v[i];

    ///part 1

    for(i=1;i<=1000;i++){

        for(j=1;j<4;j++){
            for(k=j+1;k<=4;k++){
                if(v[j].x>v[k].x)
                    v[j].vx--,v[k].vx++;
                if(v[j].x<v[k].x)
                    v[j].vx++,v[k].vx--;

                if(v[j].y>v[k].y)
                    v[j].vy--,v[k].vy++;
                if(v[j].y<v[k].y)
                    v[j].vy++,v[k].vy--;

                if(v[j].z>v[k].z)
                    v[j].vz--,v[k].vz++;
                if(v[j].z<v[k].z)
                    v[j].vz++,v[k].vz--;
            }
        }

        for(j=1;j<=4;j++){
            v[j].x+=v[j].vx;
            v[j].y+=v[j].vy;
            v[j].z+=v[j].vz;
        }
    }

//    for(j=1;j<=4;j++)
//        cout<<v[j].x<<" "<<v[j].y<<" "<<v[j].z<<"\n";
//    cout<<"\n";

    for(i=1;i<=4;i++)
        sol+=(abs(v[i].x)+abs(v[i].y)+abs(v[i].z))*(abs(v[i].vx)+abs(v[i].vy)+abs(v[i].vz));
    fout<<sol<<"\n";

    ///part 2
    for(i=1;i<=4;i++)
        v[i]=st[i];
    perx=pery=perz=1;

    do{
        perx++;
        for(i=1;i<4;i++){
            for(j=i+1;j<=4;j++){
                if(v[i].x>v[j].x)
                    v[i].vx--,v[j].vx++;
                if(v[i].x<v[j].x)
                    v[i].vx++,v[j].vx--;
            }
        }

        for(i=1;i<=4;i++)
            v[i].x+=v[i].vx;
    }while(v[1].x!=st[1].x || v[2].x!=st[2].x || v[3].x!=st[3].x || v[4].x!=st[4].x);

    do{
        pery++;
        for(i=1;i<4;i++){
            for(j=i+1;j<=4;j++){
                if(v[i].y>v[j].y)
                    v[i].vy--,v[j].vy++;
                if(v[i].y<v[j].y)
                    v[i].vy++,v[j].vy--;
            }
        }

        for(i=1;i<=4;i++)
            v[i].y+=v[i].vy;
    }while(v[1].y!=st[1].y || v[2].y!=st[2].y || v[3].y!=st[3].y || v[4].y!=st[4].y);

    do{
        perz++;
        for(i=1;i<4;i++){
            for(j=i+1;j<=4;j++){
                if(v[i].z>v[j].z)
                    v[i].vz--,v[j].vz++;
                if(v[i].z<v[j].z)
                    v[i].vz++,v[j].vz--;
            }
        }

        for(i=1;i<=4;i++)
            v[i].z+=v[i].vz;
    }while(v[1].z!=st[1].z || v[2].z!=st[2].z || v[3].z!=st[3].z || v[4].z!=st[4].z);

    cout<<perx<<" "<<pery<<" "<<perz;

    unsigned long long aux=perx*pery/gcd(perx,pery);
    fout<<aux*perz/gcd(aux,perz);

    return 0;
}
