#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dijkstra(int src, vector<vector<pair<int,int>>> &graph, vector<int> &dis, vector<int> &parent ){
    dis[src]=0;
    
    set<pair<int,int>> s1;
    s1.insert(make_pair(0,src));
    while(!s1.empty()){
        pair<int,int> p1 = *s1.begin();
        s1.erase(p1);
        int node = p1.second;
        int curr_wt = p1.first;
        for(auto nbr_wt: graph[node]){
            int nbr = nbr_wt.first;
            int nbrwt = nbr_wt.second;
            if(nbrwt+curr_wt<dis[nbr]){
                parent[nbr]=node;
                s1.erase({dis[nbr],nbr});
                dis[nbr] = nbrwt+curr_wt;
                s1.insert({dis[nbr],nbr});
            }
        }
    }
    
}
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=0;i<m;i++){
        int n1,n2,wt;
        cin>>n1>>n2>>wt;
        graph[n1].push_back({n2,wt});
        graph[n2].push_back({n1,wt});
    }
    vector<int> dis(n+1,   1e18);
    vector<int> parent(n+1,-1);
    dijkstra(1,graph,dis,parent);
    // for(int i=1;i<=n;i++){
    //     cout<<parent[i]<<" ";
    // }
    vector<int> ans;
    for(int i=n;i>=1;i=parent[i]){
        ans.push_back(i);
    }
    reverse(all(ans));
    if(ans.size()==1){
        cout<<-1<<'\n';
        return;
    }
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
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
