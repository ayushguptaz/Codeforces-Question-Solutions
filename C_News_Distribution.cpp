#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dfs(int j, int curr, int parent, vector<vector<int>> &graph, vector<bool> &visited, int &cmp, vector<int> &part){

    visited[curr]=true;
    part[curr]=j;
    for(auto nbr: graph[curr]){
        if(!visited[nbr]){
            cmp++;
            dfs(j,nbr,curr,graph,visited,cmp,part);
        }
    }
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=m;i++){
        int ki;
        cin>>ki;
        int fn;
        if(ki>0){
            cin>>fn;
        }
        for(int j=1;j<ki;j++){
            int x;
            cin>>x;
            graph[fn].push_back(x);
            graph[x].push_back(fn);
        }
    }
    int cnt = 0;
    vector<bool> visited(n+1,false);
    map<int,int> m1;
    vector<int> part(n+1,-1);
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int cmp = 1;
            cnt++;
            dfs(i,i,-1,graph,visited, cmp, part);


            m1[i]=cmp;

        }
    }
    for(int i=1;i<=n;i++){
        cout<<m1[part[i]]<<" ";
    }
    // cout<<cnt;

    
    
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
