#include <bits/stdc++.h>
 
using namespace std;
 
map<int, vector<int>> tree;
//vector<int> p;
vector<long long> a, b, r, dist, path;


int binary_search(int val){
    //cout<<val<<"\n";
    int low = 0; int high = path.size()-1;
    while(low<high){
        int idx = low + (high-low)/2;
        //cout<<idx<<"\n";
        if(val >= path[idx]){
            /**
            if(idx == path.size()-1){
                return idx;
            }
            if(val < path[idx+1]){
                return idx;
            }**/
            low = idx + 1;
        }
        else{
            high = idx;
        }
    }
    if(low < path.size() && path[low] <= val){
        low++;
    }
    return low;
}
 
void calculate(int node){
    //cout<<node<<"\n";
    for(int i = 0; i<tree[node].size(); i++){
        long long child = tree[node][i];
        //cout<<child<<"\n";
        //dist[child] = dist[node] + 1;
        a[child]+=a[node];
        b[child]+=b[node];
        path.push_back(b[child]);
        //r[child] = binary_search(a[child])-1;
        r[child] = upper_bound(path.begin(), path.end(), a[child])-path.begin()-1;
        calculate(child);
        path.pop_back();
    }
    return;
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin>>n;
        r = vector<long long>(n+1, 0);
        a = vector<long long>(n+1, 0);
        b = vector<long long>(n+1, 0);
        dist = vector<long long>(n+1, 0);
        tree.clear();
        for(int j = 2; j<=n; j++){
            int temp; cin>>temp;
            tree[temp].push_back(j);
            cin>>temp; a[j] = temp;
            cin>>temp; b[j] = temp;
        }
        path = vector<long long>(1, 1);
        calculate(1);
        for(int j = 2; j<=n; j++){
            cout<<r[j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}
