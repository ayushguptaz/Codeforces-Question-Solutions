#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
int kthParent(int x, int k, vector<vector<int>> &parents){
    int b = log2(k)+1;
    for(int i=0;i<b;i++){
        if(k&(1<<i)){
            x = parents[i][x];
            if(x==-1){
                return -1;
            }
        }
    }
    return x;
}
void solve()
{
    int n,q;
    cin>>n>>q;
    int maxP = log2(n)+5;
    vector<vector<int>> parents(maxP,vector<int>(n+1,-1));
    for(int i=2;i<=n;i++){
        cin>>parents[0][i];
    }
    for(int i=1;i<maxP;i++){
        for(int j=2;j<=n;j++){
            int temp = parents[i-1][j];
            if(temp!=-1){
                parents[i][j]=parents[i-1][temp];
            }
        }
    }
    for(int i=0;i<q;i++){
        int x,k;
        cin>>x>>k;
        int ans = kthParent(x,k,parents);
        cout<<ans<<'\n';
        
    }
    // for(int i=0;i<maxP;i++){
    //     for(int j=1;j<n+1;j++){
    //         cout<<parents[i][j]<<" ";
    //     }
    //     cout<<'\n';
    // }


    
    
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
