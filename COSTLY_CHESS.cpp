#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
vector<int> dx = {-2,-2,-1,-1,1,1,2,2};
vector<int> dy = {-1,1,-2,2,-2,2,1,-1};
bool valid(int nX, int nY){
    if(nX>7 || nX<0 || nY >7 || nY<0){
        return false;
    }
    return true;
}
void solve(int a, int b, int c, int d)
{
    
    set<vector<int>> s1;
    s1.insert({0,a,b});
    vector<vector<int>> dis(9,vector<int>(9,INT_MAX));
    while(!s1.empty()){
        vector<int> v1 = *s1.begin();
        s1.erase(v1);
        int cost = v1[0];
        int x1 = v1[1];
        int y1 = v1[2];
        // if(x1==3 && y1==3){
        //     cout<<"x1: "<<x1<<" y1: "<<y1<<'\n';
        // }
        for(int k = 0;k<8;k++){
            int nX = x1+dx[k];
            int nY = y1+dy[k];
            if(valid(nX,nY)){
                if(cost+nX*x1+nY*y1<dis[nX][nY]){
                    
                    s1.erase({dis[nX][nY],nX,nY});
                    // cout<<nX<<" "<<nY<<'\n';
                    dis[nX][nY] = cost+nX*x1+nY*y1;
                    // cout<<dis[nX][nY]<<'\n';
                    s1.insert({dis[nX][nY],nX,nY});
                }
            }
        }
        

    }
    if(dis[c][d]==INT_MAX){
        cout<<-1<<'\n';
    }
    else{
        cout<<dis[c][d]<<'\n';
    }
    

    
    
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);


    int a,b,c,d;
    while(cin>>a>>b>>c>>d){
        solve(a,b,c,d);
    }

    return 0;
}
