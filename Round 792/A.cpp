#include <iostream>

using namespace std;

pair<int, int> solve(int n){
    int cnt = 0;
    int min = 10;
    while(n > 0){
        min = (min < n%10 ? min : n%10);
        n/=10;
        cnt++;
    }
    return make_pair(cnt, min);
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int temp; cin>>temp;
        pair<int, int> res = solve(temp);
        if(res.first == 2){
            cout<<temp%10<<"\n";
        }
        else{
            cout<<res.second<<"\n";
        }
    }
    return 0;
}