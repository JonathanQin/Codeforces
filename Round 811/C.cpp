#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int solve(int t){
    int digit = 9;
    int cnt = 0;
    int res = 0;
    while(t>0){
        if(t >= digit){
            t -= digit;
            res = res + pow(10, cnt)*digit;
            cnt++;
            digit--;
        }
        else{
            digit--;
        }
    }
    return res;
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int t; cin>>t;
        cout<<solve(t)<<"\n";
    }
    return 0;
}