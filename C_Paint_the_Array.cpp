#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    

    for(int i=0;i<n;i++)
    {
        cin>>v1[i];
    }
    int gcd_1=v1[0];
    int gcd_2=v1[1];
    for(int i=0;i<n;i++){
        if(i%2==0)
        {
            gcd_1=__gcd(gcd_1,v1[i]);
        }
        else{
            gcd_2=__gcd(gcd_2,v1[i]);

        }
        
    }    
    bool ans1 = true;
    bool ans2 = true;

    for(int i=0;i<n;i++){
        if(i%2==0){
            if(v1[i]%gcd_2==0){
                ans2=false;
                
            }
        }
        else{
            if(v1[i]%gcd_1==0){
                ans1=false;
                
            }

        }
    }
    if(ans1){
        cout<<gcd_1<<'\n';
        return;
    }
    else if(ans2){
        cout<<gcd_2<<'\n';
        return;
    }
    else{
        cout<<0<<'\n';
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
