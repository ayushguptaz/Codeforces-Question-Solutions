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
    int cnt=0;
    int i=n-2;
    while(i>=0){
        if(v1[i]==v1[n-1]){
            i--;
        }
        else{
            cnt++;
            int z = 0;
            i = i-(n-1-i);
        
        }
    }
    cout<<cnt<<'\n';

    
    
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
