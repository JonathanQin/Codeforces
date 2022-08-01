#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int m; cin>>m;
        vector<int> last (m+1, 0);
        /*for(int j=0; j<m; j++){
            cout<<last[j]<<"\n";
        }*/
        int res = 0;
        for(int j = 1; j<=m; j++){
            int pos; cin>>pos;
            if(last[pos] == 0){
                last[pos] = j;
            }
            else{
                if(last[pos] > res){
                    res = last[pos];
                }
                last[pos] = j;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}