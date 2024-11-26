#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dfs(int curr, vector<vector<int>> &graph, vector<bool> &visted, vector<int> &h, int &cnt){

    visted[curr]=true;
    bool good = true;
    for(auto nbr: graph[curr]){
        if(h[nbr]>=h[curr]){
            good = false;
        }
        if(!visted[nbr]){
            dfs(nbr,graph,visted,h,cnt);

        }
    }
    if(good){
        // cout<<"curr: "<<curr<<'\n';
        cnt++;
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<int> h(n+1);
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            (dfs(i,graph,visited,h,cnt));
        }

    }
    cout<<cnt;
    

    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t=1;
    // cin >> t;
    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
