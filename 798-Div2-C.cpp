#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;

int trees;
map<int, vector<int>> graph;
vector<int> dp_child;
vector<int> visited;
vector<int> ivisited;

int dp(int n){
    visited[n] = 1;
    for(int i = 0; i < graph[n].size(); i++){
        if(visited[graph[n][i]] == 0){
           dp_child[n] += (dp(graph[n][i])+1);
        }
        //dp_child[n] += (dp(graph[n][i])+1);
    }
    return dp_child[n];
}

int infection(int n){
    ivisited[n] = 1;
    if(graph[n].size()==1){
        if(ivisited[graph[n][0]] == 1){
            return 0;
        }
        else{
            return dp_child[graph[n][0]];
        }
    }
    else{
        vector<int> res;
        vector<int> pos;
        for(int i = 0; i < graph[n].size(); i++){
            if(ivisited[graph[n][i]] == 0){
                res.push_back(dp_child[graph[n][i]]);
                pos.push_back(graph[n][i]);
            }
        }
        if(res.size() == 1){
            return res[0];
        }
        else{
            return max(res[0] + infection(pos[1]), res[1] + infection(pos[0]));
        }
    }
}

int solution(){
    int n;
    cin >> n;
    graph.clear(); 
    dp_child.clear(); visited.clear(); ivisited.clear();
    dp_child.resize(n+1); visited.resize(n+1); ivisited.resize(n+1);
    for(int i = 0; i < n-1; i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    for(int i = 0; i < n ; i++){
        dp_child[i+1] = 0;
        visited[i+1] = 0;
        ivisited[i+1] = 0;
    }
    int temp = dp(1);
    return infection(1);
}

int main(){
    cin >> trees;
    for(int i = 0; i < trees; i++){
        cout << solution() << "\n";
    }
    return 0;
}