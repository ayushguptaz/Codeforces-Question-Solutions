#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)


void dfs(vector<int> &child, vector<vector<int>> &v1, int parent, int curr){
    for(auto nbr: v1[curr]){
        if(nbr!=parent){            
            dfs(child,v1,curr,nbr);
            child[curr]+=(child[nbr]+1);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v1(n+1);
    for(int i=2;i<=n;i++){
        int node;
        cin>>node;
        v1[i].push_back(node);
        v1[node].push_back(i);
    }
    vector<int> child(n+1,0);
    dfs(child,v1,0,1);
    for(int i=1;i<=n;i++){
        cout<<child[i]<<" ";
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
