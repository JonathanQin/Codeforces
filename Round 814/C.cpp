#include <bits/stdc++.h>

using namespace std;

int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin>>n;
        int q; cin>>q;
        vector<int> arr(n+1, 0);
        for(int j = 1; j<=n; j++){
            int temp; cin>>temp;
            arr[j] = temp;
        }
        for(int j = 0; j<q; j++){
            int idx; cin>>idx;
            int k; cin>>k;
            int cnt = 0;
            int dist = 0;
            bool largest = true;
            if(arr[idx] == n){
                if(idx == 1 || idx == 2){
                    cout<<k<<"\n";
                }
                else{
                    if(k <= idx-2){
                        cout<<0<<"\n";
                    }
                    else{
                        cout<<k-(idx-2)<<"\n";
                    }
                }
            }
            else{
                for(int l = 1; l<=n; l++){
                    if(l != idx && arr[l] < arr[idx]){
                        cnt++;
                    }
                    else if(l!= idx && arr[l] > arr[idx]){
                        largest = false;
                        break;
                    }
                }
                //cout<<cnt<<" "<<idx-1<<"\n";
                if(cnt == 0){
                    cout<<0<<"\n";
                }
                else if(cnt < idx - 1){
                    cout<<0<<"\n";
                }
                else{
                    if(k < idx-1){
                        cout<<0<<"\n";
                    }
                    
                    else{
                        if(idx == 1 || idx == 2){
                            cout<<min(k, cnt)<<"\n";
                        }
                        else{
                            if(cnt > k){
                                cout<<k-(idx-2)<<"\n";
                            }
                            else{
                                cout<<cnt-(idx-2)<<"\n";
                            }
                        }
                    }
                }
            }
        }
    }
    return 0;
}