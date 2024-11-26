#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,m,k,s;
    cin>>n>>m>>k>>s;
    vector<vector<int>> type(k+1);
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        type[x].push_back(i);
    }
    vector<vector<int>> graph(n+1);
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    vector<vector<int>> dis(n+1,vector<int>(k+1));
    for(int k1=1;k1<=k;k1++){
        queue<int> q1;
        vector<int> dista(n+1,INT_MAX);
        for(int node: type[k1]){
            // cout<<node<<" ";
            q1.push(node);
            dista[node]=0;
        }
        // cout<<'\n';
        while(!q1.empty()){
            int curr = q1.front();
            q1.pop();
            for(auto nbr: graph[curr]){
                if(dista[nbr]>dista[curr]+1){
                    dista[nbr]=dista[curr]+1;
                    q1.push(nbr);
                }
            }
        }
        for(int i=1;i<=n;i++){
            dis[i][k1] = dista[i];
        }
    }
    // cout<<"f";
    for(int i=1;i<=n;i++){
        sort(dis[i].begin(),dis[i].end());
        int ans = 0;
        for(int j=1;j<=s;j++){
            ans+=(dis[i][j]);
        }
        cout<<ans<<" ";
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
