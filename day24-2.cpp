#include <fstream>
#include <iostream>
#include <bitset>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

char c[2][10][10][410];
int i,j,x,p,cnt[10][10],lvl,stop,t,st,dr,sus,jos,bugs;
int d;
int di[]={-1,0,1,0};
int dj[]={0,-1,0,1};

//void af(){
//    for(i=1;i<=5;i++,cout<<"\n")
//        for(j=1;j<=5;j++)
//            cout<<c[][i][j][];
//    cout<<"\n";
//}

int main(){
    p=1;
    for(i=1;i<=5;i++)
        for(j=1;j<=5;j++)
            fin>>c[0][i][j][200];

    while(stop++<200){
        t=1-t;

        for(lvl=1;lvl<=400;lvl++){

            for(i=1;i<=5;i++)
                for(j=1;j<=5;j++){
                    cnt[i][j]=0;
                    for(d=0;d<4;d++)
                        if(c[1-t][i+di[d]][j+dj[d]][lvl]=='#')
                            cnt[i][j]++;
                }

            st=dr=sus=jos=0;
            for(i=1;i<=5;i++){
                if(c[1-t][i][1][lvl+1]=='#')
                    st++;
                if(c[1-t][i][5][lvl+1]=='#')
                    dr++;
            }
            for(j=1;j<=5;j++){
                if(c[1-t][1][j][lvl+1]=='#')
                    sus++;
                if(c[1-t][5][j][lvl+1]=='#')
                    jos++;
            }

            cnt[2][3]+=sus;
            cnt[3][2]+=st;
            cnt[4][3]+=jos;
            cnt[3][4]+=dr;

            if(c[1-t][2][3][lvl-1]=='#')
                for(j=1;j<=5;j++)
                    cnt[1][j]++;
            if(c[1-t][4][3][lvl-1]=='#')
                for(j=1;j<=5;j++)
                    cnt[5][j]++;
            if(c[1-t][3][2][lvl-1]=='#')
                for(i=1;i<=5;i++)
                    cnt[i][1]++;
            if(c[1-t][3][4][lvl-1]=='#')
                for(i=1;i<=5;i++)
                    cnt[i][5]++;

            for(i=1;i<=5;i++)
                for(j=1;j<=5;j++){
                    if(i==3 && j==3){
                        c[t][i][j][lvl]='.';
                        continue;
                    }

                    if(c[1-t][i][j][lvl]=='#'){
                        if(cnt[i][j]==1)
                            c[t][i][j][lvl]='#';
                        else
                            c[t][i][j][lvl]='.';
                    }else{
                        if(cnt[i][j]==1 || cnt[i][j]==2)
                            c[t][i][j][lvl]='#';
                        else
                            c[t][i][j][lvl]='.';
                    }
                }
        }
    }

    for(lvl=0;lvl<=410;lvl++)
        for(i=1;i<=5;i++)
            for(j=1;j<=5;j++)
                if(c[t][i][j][lvl]=='#')
                    bugs++;
    cout<<bugs;

    return 0;
}
