#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main(){
    int t; cin>>t;
    for(int k = 0; k<t; k++){
        int n; cin>>n;
        vector<int>a; vector<int>b;
        vector<int>psums(n, 0);
        for(int j = 0; j<n; j++){
            int temp; cin>>temp; a.push_back(temp);
        }
        int counter = 0;
        for(int j = 0; j<n; j++){
            int temp; cin>>temp; b.push_back(temp);
            while(counter < n && a[counter] <= temp){
                psums[counter] = n-j; 
                counter++;
            }
        }
        for(int i = 0; i<n; i++){
            cout<<b[n-psums[i]]-a[i]<<" ";
        }
        cout<<"\n";
        int maxcounter = n;
        vector<int>res(n, 0);
        for(int i = 1; i<=n; i++){
            res[n-i] = b[maxcounter-1]-a[n-i];
            if(psums[n-i] == i){
                maxcounter = n-i;
            }
        }
        for(int i = 0; i<n; i++){
            cout<<res[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}