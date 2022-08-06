#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int arr[100005];

void perm(int p){
    int root = (int)pow(p, 0.5);
    if(pow(root, 2) == p){
        for(int i = 0; i<= p; i++){
            arr[i] = p-i;
        }
        return;
    }
    else{
        int diff = pow(root+1, 2) - p;
        for(int i = diff; i<=p; i++){
            arr[i] = p-(i-diff); 
        }
        perm(diff-1);
    }
}

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int p; cin>>p;
        perm(p-1);
        for(int i = 0; i<p; i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}

