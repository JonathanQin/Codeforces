#include <iostream>

using namespace std;

void solve(int a, int b, int c){
    int y = b;
    int cnt = 0;
    int x = a;
    if(x <= c){
        x += ((c-x)/y+1)*y;
    }
    int z = c;
    if(z <= b){
        z += ((b-z)/x+1)*x;
    }
    cout<<x<<" "<<y<<" "<<z<<"\n";
    return;
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int a, b, c;
        cin>>a>>b>>c;
        solve(a, b, c);
    }
    return 0;
}