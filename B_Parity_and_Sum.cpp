#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> v1(n);
    int cntO=0;
    int cntE=0;
    for(int i=0;i<n;i++){
        cin>>v1[i];
        if(v1[i]%2){
            cntO++;
        }
        else{
            cntE++;
        }
    }
    if(cntE==n || cntO==n){
        cout<<0<<'\n';
        return;
    }
    sort(v1.begin(),v1.end());
    int largestodd=-1;
    int largestoddidx=-1;
    int cntEBeforeOdd = 0;
    int cntEAfterOdd = 0;
    int sum = 0;
    for(int i=n-1;i>=0;i--){
        if(v1[i]%2!=0){
            largestoddidx=i;
            break;
        }
    }
    if(largestoddidx==-1){
        cout<<0<<'\n';
        return;
    }
    for(int i=0;i<largestoddidx;i++){
        if(v1[i]%2==0){
            cntEBeforeOdd++;
            sum+=v1[i];
        }
    }
    sum+=v1[largestoddidx]; 
    int ans = 0;
    ans+=cntEBeforeOdd;
    for(int i=largestoddidx+1;i<n;i++){
        if(v1[i]<sum){
            ans++;
            sum+=v1[i];
        }
        else{
            ans+=(n-i);
            ans++;
            break;
        }
    }
    
    
    
    cout<<ans<<'\n';

    
    
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
