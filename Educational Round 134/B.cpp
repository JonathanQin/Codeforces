#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n;
int m;
int sx;
int sy;
int d; 

int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        cin>>n>>m>>sx>>sy>>d;
        int val = n+m-2;
        int dia = 2*d+1;
        /**if(dia >= min(n, m)){
            val = -1;
        }**/
        if(sx-d <= 1 && sy-d <=1){
            val = -1;
        }
        if(sx+d >= n && sy+d >=m){
            val = -1;
        }
        if(sx-d <= 1 && sx+d >=n){
            val = -1;
        }
        if(sy-d <=1 && sy+d >=m){
            val = -1;
        }
        cout<<val<<"\n";
    }
}