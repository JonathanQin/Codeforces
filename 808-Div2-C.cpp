#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main(){
    int tests; cin >> tests;
    for(int i = 0; i < tests; i++){
        int n, q;
        cin >> n >> q;
        vector<int> arr;
        for(int j = n; j > 0; j--){
            int temp; cin >> temp;
            arr.push_back(temp);
        }
        stack<int> res;
        int rev_q = 0;
        for(int j = n-1; j >=0; j--){
            if(arr[j] <= rev_q){
                res.push(1);
                continue;
            }
            else if(arr[j] > rev_q){
                if(rev_q != q){
                    rev_q += 1;
                    res.push(1);
                    continue;
                }
                else{
                    res.push(0);
                    continue;
                }
            }
        }
        while(res.size()){
            cout << res.top();
            res.pop();
        }
        cout << "\n";
    }

    return 0;
}