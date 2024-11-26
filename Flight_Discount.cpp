#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> graph(n+1);
    for(int i=1;i<=m;i++){
        int a,b,x;
        cin>>a>>b>>x;
        graph[a].push_back({b,x});
    }
    set<vector<int>> s1;
    // ticket price with discount, int node, ticket price total, int maxm
    s1.insert({0,1,0,0});
    vector<int> distance(n+1,1e18);
    distance[1]=0;
    while(!s1.empty()){
        vector<int> v = *s1.begin();
        s1.erase(v);
        int node = v[1];
        int ticketp = v[2];
        int maxm = v[3];
        for(auto nbr: graph[node]){
            if(  ticketp+nbr.second - max(maxm,nbr.second)/2 - 1 <distance[nbr.first])
            {
                
                // s1.erase({distance[nbr.first],nbr.first,ticketp+nbr.second,max(maxm,nbr.second)});
                distance[nbr.first] = ticketp+nbr.second - max(maxm,nbr.second)/2 - 1;
                // cout<<distance[nbr.first]<<'\n';
                s1.insert({distance[nbr.first],nbr.first,ticketp+nbr.second,max(maxm,nbr.second)/2 + 1});

            }
            
        }

    }
    cout<<distance[n]<<'\n';

    
    
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
