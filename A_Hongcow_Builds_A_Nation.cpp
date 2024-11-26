#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dfs(int parent, int curr, vector<bool> &visited, vector<vector<int>> &graph, int &edge, int &cmp, bool &flag, set<int> &gov){
    if(gov.find(curr)!=gov.end()){
        flag = true;
    }
    visited[curr]=true;
    edge+=(graph[curr].size());
    cmp++;
    for(auto nbr: graph[curr])
    {
         
        if(!visited[nbr]){
            dfs(curr,nbr,visited,graph,edge,cmp, flag,gov);   
            
        }
        
    }

}
void solve()
{
    int n,m,k;
    cin>>n>>m>>k;
    set<int> gov;
    for(int i=1;i<=k;i++){
        int x;
        cin>>x;
        gov.insert(x);
    }
    // sort(gov.begin(),gov.end());
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    vector<bool> visited(n+1,false);
    int ans = 0;
    int zeroedge = 0;
    int maxmNode = 0;
    vector<int> f1;
    for(int i=1;i<=n;i++){
        if(!visited[i]){
            int edge = 0;
            int cmp = 0;
            bool flag = false;
            // cout<<"i: "<<i<<'\n';
            dfs(-1,i,visited,graph,edge,cmp,flag,gov);
            if(!flag){
                f1.push_back(cmp);
            }
            else{
                maxmNode = max(maxmNode,cmp);
            }      
            edge=edge/2;
            // cout<<"cmp: "<<cmp<<'\n';
            // cout<<"edge: "<<edge<<'\n';
            int maxT = cmp*(cmp-1)/2;
            int add = maxT-edge;
            
            ans+=add;
        }
    }
    sort(f1.begin(),f1.end());
    reverse(all(f1));
    for(int i=0;i<f1.size();i++){
        ans = ans + (f1[i]*maxmNode);
        maxmNode = maxmNode + f1[i];
    }
    cout<<ans;

    
    
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
