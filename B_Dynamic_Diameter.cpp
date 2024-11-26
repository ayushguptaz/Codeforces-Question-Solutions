#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int maxm =-1;
void dfs2(vector<vector<int>> &v1, int curr,int parent, vector<int> &far ){
    far[curr]=max(far[parent]+1,far[curr]);
    for(auto nbr: v1[curr]){
        if(nbr!=parent){
            dfs2(v1,nbr,curr,far);
        }
    }
}
void dfs(vector<vector<int>> &v1, int curr, int parent, int &node,int parentlvl)
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
    // return 0;
}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v1(n+1);
    for(int i=1;i<=n-1;i++)
    {
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
    }
    vector<int> far(n+1,-1);
    int node = 1;
    dfs(v1,1,-1,node,0);
    dfs2(v1,node,0,far);
    
    maxm=-1;
    dfs(v1,node,-1,node,0);
    int dia = maxm;
    vector<int> far2(n+1,-1);
    int constt = 1;
    dfs2(v1,node,0,far2);
    for(int i=1;i<=n;i++){
        cout<<max(dia,max(far[i],far2[i])+constt)<<'\n';
    }

    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t=1;
    
    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
