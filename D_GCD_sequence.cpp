#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    vector<int> b1(n-1,0);
    for(int i=1;i<n;i++){
        b1[i]=__gcd(v1[i-1],v1[i]);
    }
    int change=0;
    for(int i=1;i<n-1;i++){
        if(b1[i]>=b1[i-1]){
            continue;
        }
        else{
            if(gcd__(v1[i-1],v1[i+1])>=b1[i-1]){
                change++;
                b1[i+1]=gcd__(v1[i-1])
            }
        }

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
