#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int kthParent(int x, int k, vector<vector<int>> &parents){
    int m = x;
    if(k==0){
        return m;
    }
    int b = log2(k)+1;
    for(int i=0;i<b;i++){
        if(k&(1<<i)){
            m = parents[i][m];
            if(m==-1){
                return -1;
            }
        }
    }
    return m;
}
void dfs(int curr, int parent, vector<vector<int>> &edges,vector<int> &level, int currlvl,vector<vector<int>> &parents){
    level[curr]=currlvl;
    parents[0][curr]=parent;
    for(auto nbr: edges[curr]){
        if(nbr!=parent){
            dfs(nbr,curr,edges,level,currlvl+1,parents);
        }
    }
}
void solve()
{
    int n,q;
    
    cin>>n>>q;
    int maxP = log2(n)+1;
    vector<vector<int>> edges(n+1);
    vector<vector<int>> parents(maxP,vector<int>(n+1,-1));
    for(int i=2;i<=n;i++){
        int x,y;
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    vector<int> level(n+1,-1);
    dfs(1,0,edges,level,0,parents);
    for(int i=1;i<maxP;i++){
        for(int j=2;j<=n;j++){
            int temp = parents[i-1][j];
            if(temp!=-1){
                parents[i][j]=parents[i-1][temp];
            }
        }
    }
    
    for(int i=0;i<q;i++){
        int a,b;
        cin>>a>>b;   
        int q1 = a;
        int q2 = b;
        
        if(level[a]>level[b]){
                a = kthParent(a,(level[a]-level[b]),parents);
            }
            else{
                b = kthParent(b,(level[b]-level[a]),parents);
            }
        int ans = 0;
        if(a==b){

            int fans = level[q1]+level[q2]-2*level[a];
            cout<<fans<<'\n';


            
        }
        else{
            for(int i=maxP-1;i>=0;i--){
            if(parents[i][a]!=parents[i][b]){
                a = parents[i][a];
                b = parents[i][b];
            }

        }
            int fans = level[q1]+level[q2]-2*level[parents[0][a]];

            cout<<fans<<'\n';

        // cout<<"f: "<<parents[0][a]<<'\n';
        
        

        }
        
        
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
