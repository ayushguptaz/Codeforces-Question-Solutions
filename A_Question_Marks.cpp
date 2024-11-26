#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    string A;
    cin>>A;
    map<char,int> m1;
    for(int i=0;i<A.size();i++){
        m1[A[i]]++;
    }
    int maxC = 0;
    for(auto i: m1){
        if(i.first=='?'){
            continue;
        }
        else{
            int m = 0;
            m = min(n,i.second);
            maxC+=m;
        }
    }
    cout<<maxC<<'\n';

    
    
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
