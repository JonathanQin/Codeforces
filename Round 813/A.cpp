#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;


int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n, k;
        cin>>n>>k;
        vector<int> arr;
        int res = 0;
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        for(int l = 0; l<k; l++){
            if(arr[l] > k){
                res++;
            }
        }
        cout<<res<<"\n";
    }
    return 0;
}

