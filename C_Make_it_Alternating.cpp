#include <bits/stdc++.h>
using namespace std;
#define int long long
unsigned long long factorial(int n) {
    if (n == 0 || n == 1) {
        return 1;
    } else {
        unsigned long long result = 1;
        for (int i = 2; i <= n; ++i) {
            result = (result*i)%998244353;
        }
        return result;
    }
}

void solve()
{
    string A;
    int m = 998244353;
    cin>>A;
    int n=A.size();
    vector<int> alt;
    int i=0;
    int pro=1;
    while(i<n){
        char ele = A[i];
        int l =0;
        while(ele==A[i]){
            l++;
            i++;
        }
        pro=(pro*l)%m;
        alt.push_back(l);
    }
    int k = alt.size();
    cout<<n-k<<" ";
    int ans = (factorial(n-k)*pro)%m;
    cout<<ans<<endl;

    
    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    string as = "ab";
    string y = "b";
    vector<string> v;
    v.push_back(as);
    v.push_back(y);
    cout<<v[0]<<endl;
    // long long t;
    // cin >> t;
    // for (long long i = 0; i < t; i++)
    // {
    //     solve();
    // }

    return 0;
}
