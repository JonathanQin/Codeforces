#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin>>n;
        vector<int> arr (n+1, 0);
        vector<int> v (n+1, 0);
        vector<int> visited;
        vector<int> z (n+1, 0);
        int res = 0;
        int ans = 0;
        for(int j = 1; j<=n; j++){
            int temp;
            cin>>temp;
            arr[j] = temp;
            if(z[temp] != 0){
                arr[j] = 0;
            }
            if(arr[j] < arr[j-1]){
                //ans = res;
                ans += visited.size();
                for(int k = 0; k<visited.size(); k++){
                    z[visited[k]] = 1;
                }
                visited.clear();
            }
            if(z[temp] == 0 && v[temp] == 0){
                //res++;
                visited.push_back(temp);
            }
            v[temp]++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}

