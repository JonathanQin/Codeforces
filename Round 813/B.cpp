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
        if(n%2 == 0){
            for(int j = 1; j<=n; j+=2){
                cout<<j+1<<" "<<j<<" ";
            }
        }
        else{
            cout<<1<<" ";
            for(int j = 2; j<=n; j+=2){
                cout<<j+1<<" "<<j<<" ";
            }
        }
        cout<<"\n";
    }
    return 0;
}

