#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,x;
    cin>>n>>x;
    set<int> v1;
    for(int i=0;i<n;i++){
        int ele;
        cin>>ele;
        v1.insert(ele);
    }
    bool is = true;
    for(auto i:v1){
        if(v1.find(i+x)!=v1.end()){
            cout<<"YES"<<'\n';
            is = false;
            break;
        }
    }
    if(is){
        cout<<"NO"<<'\n';
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
