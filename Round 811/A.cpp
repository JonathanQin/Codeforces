#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    int h, m, t;
    int res_a, res_b;
    for(int i = 0; i<n; i++){
        cin>>t>>h>>m;
        res_a = 24; res_b = 24;
        for(int j = 0; j<t; j++){
            int a, b;
            cin>>a>>b;
            int temp_a, temp_b;
            temp_a = (24-h+a)%24;
            temp_b = (60-m+b);
            if(temp_b < 60){
                if(temp_a == 0){
                    temp_a = 23;
                }
                else{
                    temp_a--;
                }
            }
            else{
                temp_b = temp_b%60;
            }
            if(temp_a < res_a){
                res_a = temp_a;
                res_b = temp_b;
            }
            else if(temp_a == res_a){
                if(temp_b < res_b){
                    res_b = temp_b;
                }
            }
        }
        cout<<res_a<< " " <<res_b<<"\n";
    }
    return 0;
}

