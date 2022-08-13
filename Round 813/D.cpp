#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n, k;
        cin>>n>>k;
        vector<int> arr;
        for(int j=0; j<n; j++){
            int temp;
            cin>>temp;
            arr.push_back(temp);
        }
        sort(arr.begin(), arr.end());
        for(int j = 0; j<k; j++){
            arr[j] = pow(10, 9);
        }
        //dijkstras here
        vector<int> dist(n, INT32_MAX);
        vector<int> visited(n, 0);
        dist[0] = 0;
        for(int j = 1; j<n; j++){
            dist[j] = min(arr[0], arr[j]);
        }
        
        int idx = 0;
        for(int j = 1; j<n; j++){
            visited[idx] = 1;
            int smallest = INT32_MAX;
            for(int l = 1; l<n; l++){
                if(visited[l] == 0){
                    dist[l] = min(dist[l], dist[idx] + min(arr[idx], arr[l]));
                    if(dist[l] < smallest){
                        smallest = dist[l];
                        idx = l;
                    }
                }
            }
            /**
            for(int k = 0; k<n; k++){
                cout<<dist[k]<<" ";
            }
            cout<<"\n";
            **/
        }
        int res = 0;
        for(int j = 1; j<n; j++){
            res = max(res, dist[j]);
        }
        cout<<res<<"\n";
        /**
        priority_queue<int, pair<int, int>, greater<int>> pq;
        pq.push(make_pair(0, 0));
        for(int j = 1; j<n; j++){
            pq.push(make_pair(min(arr[0], arr[j]), j));
            //dist[j] = min(arr[0], arr[j]);
        }
        while(!pq.empty()){
            int m = pq.top().second;
            visited[n] = 1;
            vector<pair<int, int>> vec = Container(pq);
            vector<pair<int, int>>::iterator it = vec.begin();
        }**/
    }
    return 0;
}

