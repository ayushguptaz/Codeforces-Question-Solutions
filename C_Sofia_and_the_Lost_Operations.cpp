#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<int> a1(n);
    vector<int> b1(n);
    for(int i=0;i<n;i++){
        cin>>a1[i];
    }
    for(int i=0;i<n;i++){
        cin>>b1[i];
    }
    int m;
    cin>>m;
    map<int,int> d1;
    vector<int> d1d;
    for(int i=0;i<m;i++){
        int ele;
        cin>>ele;
        d1[ele]++;
        d1d.push_back(ele);
    }
    bool f = false;
    for(int i=0;i<n;i++){
        if(b1[i]==d1d[m-1]){
            f=true;
            break;
        }
    }
    for(int i=0;i<n;i++){
        if(a1[i]!=b1[i]){
            if(d1.find(b1[i])!=d1.end()){
                d1[b1[i]]--;
                if(d1[b1[i]]==0){
                    d1.erase(b1[i]);
                }
                b1[i]=a1[i];
            }
            else{
                cout<<"NO"<<'\n';
                return;
            }
        }
    }
    for(int i=0;i<n;i++){
        if(a1[i]!=b1[i]){
            cout<<"NO"<<'\n';
            return;
        }
    }
    
    if(f){
        cout<<"YES"<<'\n';
        return;
    }
    cout<<"NO"<<'\n';


    
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
