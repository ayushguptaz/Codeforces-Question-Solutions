#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dfs(int curr, int parent, vector<vector<int>> &graph, vector<bool> &visited){
    visited[curr]=true;
    for(auto nbr: graph[curr]){
        if(!visited[nbr]){
            dfs(nbr,curr,graph,visited);
        }
    }

}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    int cnt = 0;
    vector<bool> visited(n+1,false);
    vector<int> road;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            road.push_back(i);
            cnt++;
            dfs(i,-1,graph,visited);
        }
    }
    cout<<cnt-1<<'\n';
    if(cnt==1){
        return;
    }
    for(int i=1;i<road.size();i++){
        cout<<road[i-1]<<" "<<road[i]<<'\n';
    }

    
    
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
