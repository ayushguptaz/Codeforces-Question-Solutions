#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,m;
    cin>>n>>m;
    string A;
    cin>>A;
    map<char,int> m1;
    int ans=0;
    for(char c='A';c<='G';c++){
        m1[c]=0;
    }
    for(int i=0;i<n;i++){
        m1[A[i]]++;
    }
    for(auto it: m1){
        if(it.second<m){
            ans+=(m-it.second);

        }
        // cout<<it.first<<" "<<it.second<<'\n';
    }
    cout<<ans<<'\n';

    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
