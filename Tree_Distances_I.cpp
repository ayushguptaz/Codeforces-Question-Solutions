#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int maxm = -1;
int node = 0;
void dfs(int curr, vector<vector<int>> &tree, int parent, vector<int> &level1, int clevel){
    if(clevel>maxm){
        maxm = clevel;
        node = curr;
    }
    level1[curr]=clevel;
    for(auto nbr: tree[curr]){
        if(nbr!=parent){
            dfs(nbr,tree,curr,level1,clevel+1);
        }
    }
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> tree(n+1);
    for(int i=1;i<=n-1;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<int> level1(n+1,-1);
    dfs(1,tree,-1,level1,0);
    int A = node;
    maxm = -1;
    node = 0;
    dfs(A,tree,-1,level1,0);
    int B = node;
    vector<int> level2(n+1,-1);
    dfs(B,tree,-1,level2,0);
    for(int i=1;i<=n;i++){
        cout<<max(level1[i],level2[i])<<" ";
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
