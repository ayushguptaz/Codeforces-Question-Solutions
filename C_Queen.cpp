#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void dfs(vector<vector<int>> &graph,int curr, int parent,vector<int> &ci,vector<int> &ans){
    bool check = true;
    for(auto nbr: graph[curr]){
        if(nbr!=parent){
            if(ci[nbr]==0)
            {
                check=false;
            }
        dfs(graph,nbr,curr,ci,ans);

        }
    }
    if(check && ci[curr]==1){
        ans.push_back(curr);
        
    }
    


}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    vector<int> ci(n+1);
    int root = -1;
    for(int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        if(x==-1){
            root = i;
            // graph[root].push_back
            continue;
        }
        graph[i].push_back(x);
        graph[x].push_back(i);
        ci[i]=y;
    }
    vector<int> ans;
    dfs(graph,root,-1,ci,ans);
    sort(ans.begin(),ans.end());
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    if(ans.size()==0){
        cout<<-1;
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
