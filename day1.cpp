#include <fstream>
using namespace std;

ifstream fin("date.in");
ofstream fout("date.out");

int sum,x,sol;

int main(){
    while(fin>>x){
        x=x/3-2;
        while(x>=0){
            sum+=x;
            x=x/3-2;
        }
    }

    fout<<sum;

    return 0;
}
