#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,q;
    cin>>n>>q;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    vector<int> q1(q);
    for(int i=0;i<q;i++){
        cin>>q1[i];
    }
    vector<bool> ai(31,false);
    for(auto x:q1){
        if(ai[x]==true){
            continue;
        }
        else{
            ai[x]=true;
            int update = (1<<(x-1));
            for(int j=0;j<n;j++){
                if(v1[j]%(2*update)==0){
                    
                    v1[j]=v1[j]+ update;
                }
            }
            
        }

    }
    for(auto i: v1){
        cout<<i<<" ";
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
