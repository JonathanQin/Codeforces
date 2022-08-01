#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int change(int a){
    return a + a%10;
}

bool compare(int a, int b){
    if(a == b){
        return true;
    }
    int counter = 0;
    while(counter < 12){
        if(a == b){
            return true;
        }
        else if(a < b){
            a = change(a);
        }
        else{
            b = change(b);
        }
        counter++;
    }
    return false;
}

bool compare_five(int a, int b){
    if(a%10 == 5 && b%10 == 0){
        if(a+5 == b){
            return true;
        }
        return false;
    }
    else if(a%10 == 0 && b%10 ==5){
        if(b+5 == a){
            return true;
        }
        return false;
    }
    else if(a == b){
        return true;
    }
    return false;
}

int main(){
    vector<vector<int>> check;
    for(int i = 0; i<20; i++){
        vector<int> temp;
        for(int j = 0; j<20; j++){
            temp.push_back(compare(i, j));
            //cout<<temp[j]<<" ";
        }
        //cout<<"\n";
        check.push_back(temp);
    }
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int m; cin>>m;
        vector<int> arr;
        bool res = true;
        for(int j = 0; j<m; j++){
            int temp; cin>>temp;
            arr.push_back(temp);
        }
        for(int j = 0; j<m-1; j++){
            if(arr[j]%5 == 0 && arr[j+1]%5 == 0){
                res = compare_five(arr[j], arr[j+1]);
            }
            else{
                res = check[arr[j]%20][arr[j+1]%20];
            }
            if(res == false){
                break;
            }
        }
        if(res == false){
            cout<<"No\n";
        }
        else{
            cout<<"Yes\n";
        }
    }
    return 0;
}
