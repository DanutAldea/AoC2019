#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int v[200],w[200],n,i,ok,j,k;

int main(){
    while(fin>>w[n])
        n++;

    for(j=0;j<=99;j++){
        for(k=0;k<=99;k++){
            for(i=0;i<n;i++)
                v[i]=w[i];

            v[1]=j; v[2]=k;

            i=0;
            while(i<n){
                if(v[i]==99)
                    break;

                if(v[i]==1)
                    v[v[i+3]]=v[v[i+1]]+v[v[i+2]];
                else if(v[i]==2)
                    v[v[i+3]]=v[v[i+1]]*v[v[i+2]];

                i+=4;
            }

            if(v[0]==19690720){
                fout<<100*j+k;
                return 0;
            }
        }
    }

//    for(j=0;j<n;j++)
//        fout<<v[j]<<" ";
//    fout<<"\n";


    return 0;
}
