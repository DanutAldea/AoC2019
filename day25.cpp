#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

long long n,v[100000],i,j,p1,p2,p3,base;
char c;

void intcode(){
    while(fin>>v[n])
        n++;
    n--;

    while(i<=n){
        //cout<<"\n"<<i<<" "<<v[i];
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
            cin>>c;
            if(c=='x')
                c=10;
            if(c==',')
                c=32;
            if(v[i]/100%10==2) v[v[i+1]+base]=c;
            else v[v[i+1]]=c;

            i+=2;
            continue;
        }

        if(v[i]%100==4){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];
            if(p1>=256)
                cout<<p1+0;
            else
                cout<<char(p1);
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
}

int main(){
    intcode();
/*
    obiecte:
    - jam
    - loom
    - mug
    - spool of cat6
    - prime number
    - food ration
    - fuel cell
    - manifold
*/

/**
    obiecte necesare:
    - prime number
    - food ration
    - mug
    - fuel cell

    cod: 5370020052

    Merry X-Mas!
**/

    return 0;
}

