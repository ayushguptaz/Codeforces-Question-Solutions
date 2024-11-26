#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int nodes = 2e5+1;
vector<vector<int>> graph(nodes);
vector<int> cat(nodes);
vector<int> visited(nodes,0);
int n,m,ans;
int cnt = 0;
void dfs(int node, int cnt,vector<int> &visited){
    if(cnt>m){
        return;
    }
    visited[node]=1;
    int ok = 1;
    if(cat[node]==1){
        cnt++;
    }
    else{
        cnt=0;
    }
    for(auto nbr: graph[node]){
        if(visited[nbr]==0){
            ok=0;
            dfs(nbr,cnt,visited);
        }
    }
    if(cnt<=m){
        // cout<<node<<" "<<ok<<" "<<cnt<<'\n';
        ans+=ok;
    }
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i =1;i<=n;i++){
        cin>>cat[i];
    }
    for(int i=1;i<n;i++){
        int n1;
        int n2;
        cin>>n1>>n2;
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
    
    dfs(1,cnt,visited);
    cout<<ans;
    
    
    

    return 0;
}
