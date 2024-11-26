#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n,f,k;
    cin>>n>>f>>k;
    vector<int> v1(n);
    for(int i=0;i<n;i++){
        cin>>v1[i];
    }
    int fav = v1[f-1];
    sort(v1.begin(),v1.end());
    reverse(v1.begin(),v1.end());
    if(k==n){
        cout<<"YES"<<'\n';
    }
    else{
        if(v1[k]>fav){
            cout<<"NO"<<'\n';
        }
        else if(v1[k]<fav){
            cout<<"YES"<<'\n';
        }
        else{
            if(v1[k-1]==fav){
                cout<<"MAYBE"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
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
