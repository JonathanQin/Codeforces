#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n, k; cin>>n>>k;
        if(k%2 == 1){
            cout<<"YES\n";
            for(int j = 1; j<=n; j+=2){
                cout<<j<<" "<<j+1<<"\n";
            }
        }
        else if(k%4 == 2 && k!=0){
            cout<<"YES\n";
            for(int j = 1; j<=n; j+=2){
                if((j+1)%4 == 2){
                    cout<<j+1<<" "<<j<<"\n";
                }
                else{
                    cout<<j<<" "<<j+1<<"\n";
                }
            }
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}