#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,m;
    cin>>n>>m;
    if(n-m>=0 && (n-m)%2==0){
        cout<<"Yes"<<'\n';
    }
    else{
        cout<<"No"<<'\n';
    }

    
    
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
