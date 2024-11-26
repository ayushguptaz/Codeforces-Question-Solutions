#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int dfs2(int curr, int parent, vector<vector<int>> &tree, vector<int>&sum ){

    for(auto nbr: tree[curr]){
        if(nbr!=parent){
            int d = dfs2(nbr,curr, tree, sum);
            sum[curr]+=(d);

        }
    }
    return sum[curr];
}
void dfs(int curr, int parent, vector<vector<int>> &tree, vector<int> &fparent, vector<int> &level, int currl){
    level[curr] = currl;
    fparent[curr]=parent;
    for(auto nbr: tree[curr]){
        if(nbr!=parent){
            dfs(nbr,curr,tree,fparent,level,currl+1);
        }
    }
}
int kthParent(int k, int x, vector<vector<int>>&parents){
    int m = x;
    if(k==0){
        return m;
    }
    else{
        for(int i=0;i<(log2(k)+1);i++){
            if(((1<<i))&k){
                x = parents[i][x];
                if(x==-1){
                    return x;
                }
            }

        }
        return x;
    }
    
}
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<vector<int>> tree(n+1);
    int maxP = log2(n)+2;
    vector<vector<int>> parents(maxP,vector<int>(n+1,-1));
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        tree[x].push_back(y);
        tree[y].push_back(x);
    }
    vector<int> level(n+1,-1);
    dfs(1,-1,tree,parents[0],level,0);
    for(int i=1;i<maxP;i++){
        for(int j=1;j<=n;j++){
            int temp = parents[i-1][j];
            if(temp!=-1){
                parents[i][j] = parents[i-1][temp];
            }
        }
    }
    vector<int> sum(n+1,0);
    for(int i=0;i<q;i++){
        int p1,p2;
        cin>>p1>>p2;
        sum[p1]++;
        sum[p2]++;
        // find lca of p1,p2;
        // cout<<level[p1]<<" "<<level[p2]<<'\n';
        if(level[p1]>level[p2]){
            p1 = kthParent(level[p1]-level[p2], p1, parents);
            
        }
        
        else{
            p2 = kthParent(level[p2]-level[p1], p2, parents);
        }
        int lca;
        if(p1==p2){
            lca = p1;

        }
        
        else{
            for(int i=maxP-1;i>=0;i--){
            if(parents[i][p1]!=parents[i][p2])
            {
                p1 = parents[i][p1];
                p2 = parents[i][p2];
            }
            }
            lca = parents[0][p1];
        }
        // cout<<"sumLca1 "<<sum[lca]<<'\n';
        sum[lca]--;
        // cout<<"sumLca2 "<<sum[lca]<<'\n';

        if(lca!=1){
            // cout<<"f";
            sum[parents[0][lca]]--;
        }
        
        
        
        // sum[parents[0][p1]]--;
        // sum[parents[0][parents[0][p1]]]--;
    }
    int fd = dfs2(1,-1,tree,sum);
    // cout<<"f";
    for(int i=1;i<=n;i++){
        cout<<sum[i]<<" ";
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
