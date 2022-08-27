#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        string s[2];
        cin >> s[0] >> s[1];
        set<char> ss;
        for(int j = 0; j<2; j++){
            for(int k =0; k<2; k++){
                ss.insert(s[j][k]);
            }
        }
        int m = ss.size();
        if(m == 1){
            cout<<0<<"\n";
        }
        if(m == 2){
            cout<<1<<"\n";
        }
        if(m == 3){
            cout<<2<<"\n";
        }
        if(m == 4){
            cout<<3<<"\n";
        }

    }
    return 0;
}