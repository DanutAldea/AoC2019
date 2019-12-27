#include <fstream>
#include <iostream>
#include <deque>
#define x first
#define y second
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

long long n,v[100000],w[100000],i,j,p1,p2,p3,base;
long long a[2002][2020],f[2002][2020],x,y,xs,ys;
int dx[]={0,-1,1,0,0};
int dy[]={0,0,0,-1,1};
long long d,next,dist;
long long F[2002][2002],m;

deque <pair<int,int> > q;
deque <int> com;

long long intcode(int input){

    while(i<=n){
        //cout<<"\n"<<i<<" "<<v[i];
        if(v[i]%100==99)
            return -1;

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
            if(v[i]/100%10==2) v[v[i+1]+base]=input;
            else v[v[i+1]]=input;

            i+=2;
            continue;
        }

        if(v[i]%100==4){
            if(v[i]/100%10==1) p1=v[i+1];
            else if(v[i]/100%10==2) p1=v[v[i+1]+base];
            else p1=v[v[i+1]];

            i+=2;
            return p1;
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
    while(fin>>v[n])
        n++;
    n--;

    q.push_back(make_pair(1000,1000));

    while(true){
        x=q.back().x; y=q.back().y;
        f[x][y]=1;

        for(d=1;d<=4;d++){
            if(f[x+dx[d]][y+dy[d]]==0){

                next=intcode(d);

                if(next==0){
                    a[x+dx[d]][y+dy[d]]=1;
                    f[x+dx[d]][y+dy[d]]=1;
                }else{
                    if(next==2){
                        q.push_back(make_pair(x+dx[d],y+dy[d]));
                        com.push_back(d);
                        dist++;

                        xs=x+dx[d];
                        ys=y+dy[d];

                        cout<<dist;
                        break;
                    }else{
                        q.push_back(make_pair(x+dx[d],y+dy[d]));
                        com.push_back(d);
                        dist++;
                        break;
                    }
                }
            }
        }
        ///am mers in ceva nevizitat
        if(d<=4)
            continue;

        ///daca nu, inseamna ca ne intoarcem
        dist--;
        if(com.empty()){
            break;
        }

        if(com.back()<3){
            intcode(3-com.back());
        }else{
            intcode(7-com.back());
        }
        q.pop_back();
        com.pop_back();
    }
    cout<<"\n";

    for(i=979;i<=1019;i++){
        for(j=979;j<=1019;j++)
            if(a[i][j]==0)
                fout<<" ";
            else
                fout<<a[i][j];
        fout<<"\n";
    }

    q.clear();
    q.push_back(make_pair(xs,ys));
    F[xs][ys]=1;

    while(!q.empty()){
        x=q.front().x; y=q.front().y;
        m=max(m,F[x][y]);

        for(d=1;d<=4;d++){
            if(F[x+dx[d]][y+dy[d]]==0 && a[x+dx[d]][y+dy[d]]==0){
                F[x+dx[d]][y+dy[d]]=F[x][y]+1;
                q.push_back(make_pair(x+dx[d],y+dy[d]));
            }
        }

        q.pop_front();
    }
    cout<<m-1;

    return 0;
}


