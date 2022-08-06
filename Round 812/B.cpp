#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int len; cin>>len;
        int prev = 0;
        int increasing = 0;
        int decreasing = 0;
        int curr = 0;
        bool res = true;
        for(int j = 0; j<len; j++){
            int x; cin>>x;
            if(j>0){
                if(x > prev){
                    if(decreasing == 0){
                        increasing = 1;
                        curr = 1;
                    }
                    else{
                        res = false;
                    }
                }
                if(x < prev){
                    if(decreasing == 0){
                        decreasing = 1;
                        curr = -1;
                    }
                    else if(decreasing == 1 && curr == 1){
                        res = false;
                    }
                }
            }
            prev = x;
        }
        if(res){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}

