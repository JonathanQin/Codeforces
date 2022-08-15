#include <bits/stdc++.h>

using namespace std;

void solve(){
    string s; cin>>s;
    int n; cin>>n;
    vector<pair<int, string>> words;
    vector<pair<int, vector<int>>> dp (s.length()+1, make_pair(INT32_MAX-1, vector<int>()));
    dp[0].first = 0;
    for(int i = 0; i<n; i++){
        string temp; cin>>temp;
        words.push_back(make_pair(temp.length(), temp));
    }
    for(int i = 1; i<=s.length(); i++){
        for(int j = 0; j<words.size(); j++){
            if(i-words[j].first >= 0 && s.substr(i-words[j].first, words[j].first) == words[j].second){
                for(int k = i-words[j].first+1; k<=i; k++){
                    if(dp[i-words[j].first].first + 1 >= dp[k].first){
                        continue;
                    }
                    else{
                        dp[k].first = dp[i-words[j].first].first + 1;
                        dp[k].second = dp[i-words[j].first].second;
                        dp[k].second.push_back(j+1);
                        dp[k].second.push_back(i-words[j].first+1);
                    }
                }
            }
        }
    }
    if(dp[s.length()].second.empty()){
        cout<<-1<<"\n";
    }
    else{
        cout<<dp[s.length()].second.size()/2<<"\n";
        for(int i = 0; i<dp[s.length()].second.size(); i+=2){
            cout<<dp[s.length()].second[i]<<" "<<dp[s.length()].second[i+1]<<"\n";
        }
    }
}

int main(){
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    int t; cin>>t;
    for(int i = 0; i<t; i++){
        solve();
    }
    return 0;
}

