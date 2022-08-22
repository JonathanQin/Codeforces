#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

vector<long long> currList;
vector<long long> prevList; 

long long query(){
    int len = prevList.size();
    if(len == 1){
        return prevList[0];
    }
    if(len == 2){
        cout<<"? "<<prevList[0]<<" "<<prevList[1]<<"\n";
        //cout.flush();
        int ans; cin>>ans;
        if(ans == 1){
            return prevList[0];
        }
        else{
            return prevList[1];
        }
    }
    else{
        for(int i = 0; i<len; i+=4){
            cout<<"? "<<prevList[i]<<" "<<prevList[i+2]<<"\n";
            //cout.flush();
            int res; cin>>res;
            int ans;
            int winner;
            if(res == 0){
                cout<<"? "<<prevList[i+1]<<" "<<prevList[i+3]<<"\n";
                //cout.flush();
                cin>>ans;
                if(ans == 1){
                    winner = prevList[i+1];
                }
                else{
                    winner = prevList[i+3];
                }
            }
            else if(res == 1){
                cout<<"? "<<prevList[i]<<" "<<prevList[i+3]<<"\n";
                //cout.flush();
                cin>>ans;
                if(ans == 1){
                    winner = prevList[i];
                }
                else{
                    winner = prevList[i+3];
                }
            }
            else{ //res = i+2
                cout<<"? "<<prevList[i+1]<<" "<<prevList[i+2]<<"\n";
                //cout.flush();
                cin>>ans;
                if(ans == 1){
                    winner = prevList[i+1];
                }
                else{
                    winner = prevList[i+2];
                }
            }
            currList.push_back(winner);
        }
        /**
        vector<long long>::iterator it = currList.begin();
        for(it; it!=currList.end(); it++){
            cout<<*it<<" ";
        }
        cout<<"\n";
        **/
       
        prevList = currList;
        currList.clear();
        return query();
    }
}


int main(){
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        int n; cin>>n;
        prevList.clear();
        currList.clear();
        for(long long j = 0; j<pow(2, n); j++){
            prevList.push_back(j+1);
        }   
        long long ans = query();
        cout<<"! "<<ans<<"\n";
        //cout.flush();
    }
    return 0;
}

