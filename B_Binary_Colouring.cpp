#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> ans;
    while(n>0){
        if(n&1){
            ans.push_back(1);
            // n=n-1;
        }
        else{
            ans.push_back(0);
        }
        n=n/2;
        if(n&1 and ans.back()==1){
            ans.back()=-1;
            n+=1;
        }
        // n+=1;
    }
    cout<<ans.size()<<'\n';
    for(auto index: ans){
        cout<<index<<" ";
    }
    cout<<'\n';

    
    
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
