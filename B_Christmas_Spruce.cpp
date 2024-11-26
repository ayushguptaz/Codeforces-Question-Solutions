#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    map<int,vector<int>> m1;
    for(int i=2;i<=n;i++){
        int ele;
        cin>>ele;
        m1[ele].push_back(i);
    }
    vector<int> degree(n+1,0);
    for(auto x:m1){
        int node = x.first;
        vector<int> nbr = x.second;
        degree[node]=nbr.size();
    }
    for(auto x:m1){
        int node = x.first;
        vector<int> nbr = x.second;
        int zdeg = 0;
        for(int j=0;j<nbr.size();j++){
            if(degree[nbr[j]]==0){
                zdeg++;
            }
        }
        if(zdeg<3){
            cout<<"No"<<'\n';
            return;
        }
    }
    cout<<"Yes"<<'\n';

    
    
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
