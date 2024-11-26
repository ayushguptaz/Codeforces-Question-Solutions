#include <bits/stdc++.h>
using namespace std;
#define int double
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> prob(n);
    for(int i=0;i<n;i++)
    {
        cin>>prob[i];
    }
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    dp[0][0]=1;
    for(int i=1;i<n+1;i++){
        dp[i][0]=dp[i-1][0]*(1-prob[i-1]);
    }
    for(int i=1;i<n+1;i++){
        for(int j=1;j<n+1;j++){
            dp[i][j] = prob[i-1]*(dp[i-1][j-1]) + (1-prob[i-1])*(dp[i-1][j]);
        }
    }
    
    int ans =0;
    for(int j=(n+1)/2;j<=n;j++){
        ans+=(dp[n][j]);
    }
    cout<<setprecision(10)<<ans;


    
    
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
