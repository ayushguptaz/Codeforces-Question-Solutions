#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int maxm = -1;
int dfs(vector<vector<int>> &v1, int curr, int parent, int &node,int parentlvl)
{
    int currlvl = parentlvl+1;
    if(currlvl>maxm){
        node = curr;
        maxm=currlvl;
    }
    for(auto nbr: v1[curr]){
        if(nbr!=parent){
            dfs(v1,nbr,curr,node,currlvl);

        }
    }
    return 0;
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v1(n+1);
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    if(n==1){
        cout<<0;
    }
    else{
        int node = 1;
        int far1 = dfs(v1,1,-1,node,0);
        // cout<<node<<" ";
        maxm=-1;

        int far2 = dfs(v1,node,-1,node,0);
        // cout<<node<<" ";
        // cout<<far1<<'\n';
        cout<<maxm-1<<'\n';
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
