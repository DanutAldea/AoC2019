#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

long long n,v[100000],i,j,p1,p2,p3,base;
char c;
int is,js,m,sum;
int a[60][60];
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};
int d;

void solve(){
    n=51;
    m=39;
    for(i=1;i<=n;i++,cout<<"\n")
        for(j=1;j<=m;j++){
            fin>>c;
            cout<<c;
            if(c=='.'){
                a[i][j]=-1;
                continue;
            }
            if(c=='#')
                continue;

            is=i; js=j;
        }

    for(i=1;i<=n;i++)
        for(j=1;j<=m;j++)
            if(a[i][j]==0){
                for(d=0;d<4;d++)
                        if(i+di[d]<=0 || j+dj[d]<=0 || i+di[d]>n || j+dj[d]>m || a[i+di[d]][j+dj[d]]==-1)
                            break;

                if(d==4){
                    sum+=(i-1)*(j-1);
                    ///cout<<i-1<<" "<<j-1<<"\n";
                }
            }

    cout<<sum<<"\n";
}

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
            if(v[i]/100%10==2) v[v[i+1]+base]=c;
            else v[v[i+1]]=c;

            i+=2;
            continue;
        }

        if(v[i]%100==4){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];
            if(p1>=128){
                if(v[0]==1)
                    fout<<p1+0;
                else
                    cout<<p1+0;
            }else{
                if(v[0]==1)
                    fout<<char(p1);
                else
                    cout<<char(p1);
            }
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
//  part 1

    ///obtin matricea
    ///intcode();

    ///cu matricea obtinuta rezolv p1
    ///solve();


//  part 2
/**
    un traseu care viziteaza toata schela
    L4,L6,L8,L12,L8,R12,L12,L8,R12,L12,L4,L6,L8,L12,L8,R12,L12,R12,L6,L6,L8,L4,L6,L8,L12,R12,L6,L6,L8,L8,R12,L12,R12,L6,L6,L8

    main - A,B,B,A,B,C,A,C,B,C
    A - L,4,L,6,L,8,L,12
    B - L,8,R,12,L,12
    C - R,12,L,6,L,6,L,8

    P.S.: trebuie introdus x dupa fiecare linie(nu stiu sa citesc enter-uri ups)
**/

    intcode();

    return 0;
}
