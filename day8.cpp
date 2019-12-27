#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("aoc.in");
ofstream fout("aoc.out");

char c[1000][6][25];
int cnt[1000][3];
int n,i,j,k,z,sol;

int main(){
    while(fin>>c[++n][1][1]){
        cnt[n][c[n][1][1]-'0']++;
        for(i=2;i<=25;i++){
            fin>>c[n][1][i];
            cnt[n][c[n][1][i]-'0']++;
        }

        for(i=2;i<=6;i++)
            for(j=1;j<=25;j++){
                fin>>c[n][i][j];
                cnt[n][c[n][i][j]-'0']++;
            }
    }
    n--;
//    cout<<n<<" ";
//
//    z=1000;
//    for(i=1;i<=n;i++)
//        if(z>cnt[i][0]){
//            z=cnt[i][0];
//            sol=cnt[i][1]*cnt[i][2];
//        }
//
//    cout<<sol;

    for(i=1;i<=6;i++){
        for(j=1;j<=25;j++){
            k=1;
            while(c[k][i][j]=='2')
                k++;

            if(k>n){
                cout<<" ";
            }else{
                if(c[k][i][j]=='0')
                    cout<<" ";
                else
                    cout<<"*";
            }
        }
        cout<<"\n";
    }

    return 0;
}
