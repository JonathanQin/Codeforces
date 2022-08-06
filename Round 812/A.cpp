#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    int n; cin>>n;
    for(int i = 0; i<n; i++){
        int b; cin>>b;
        int max_x = 0;
        int min_x = 0; 
        int max_y = 0;
        int min_y = 0;
        int skipposx = 0;
        int skipnegx = 0;
        int skipposy = 0;
        int skipnegy = 0;
        for(int j = 0; j<b; j++){
            int x, y;
            cin>>x>>y;
            if(x > skipposx){
                skipposx = x;
            }
            else if(x < skipnegx){
                skipnegx - x;
            }
            if(y > skipposy){
                skipposy = y;
            }
            else if(y < skipnegy){
                skipnegy = y;
            }
            if(x > max_x){
                max_x = x;
            }
            else if(x < min_x){
                min_x = x;
            }
            if(y > max_y){
                max_y = y;
            }
            else if(y < min_y){
                min_y = y;
            }
        }
        //int maxx = (abs(skipnegx) > skipposx ? abs(skipnegx) : skipposx);
        //int maxy = (abs(skipnegy) > skipposy ? abs(skipnegy) : skipposy);
        //int skipmax = (maxx > maxy ? maxx : maxy);
        int res = 2*(max_x-min_x+max_y-min_y); //- skipmax;
        cout<<res<<"\n";
    }
    return 0;
}

