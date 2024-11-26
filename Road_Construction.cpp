#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) begin(x), end(x)
vector<int> parentt;
vector<int> sizee;
int totcmp;
int maxm = 1;
int find_parent(int a){
    if(a==parentt[a]){
        return a;
    }
    return parentt[a]=find_parent(parentt[a]);
}
void do_union(int a, int b){

    a = find_parent(a);
    b = find_parent(b);
    if(a!=b){
        totcmp--;
        if(sizee[a]< sizee[b]){
            parentt[a]=b;
            sizee[b]+=sizee[a];
            maxm=max(maxm,sizee[b]);
        }
        else {
            parentt[b]=a;
            sizee[a]+=sizee[b];
            maxm=max(maxm,sizee[a]);

        }
        
    }    
}
void check(int a, int b){
    a = find_parent(a);
    b = find_parent(b);
    if(a==b){
        cout<<"YES"<<'\n';
    }
    else{
        cout<<"NO"<<'\n';
    }

}
void solve()
{
    int n,m;
    cin>>n>>m;
    totcmp=n;
    parentt.resize(n+1);
    sizee.resize(n+1);
    for(int i=1;i<=n;i++){
        parentt[i]=i;
    }
    for(int i=1;i<=n;i++){
        sizee[i]=1;
    }

    // for(int i=)

    for(int i=1;i<=m;i++){
        int a,b;
        cin>>a>>b;
        do_union(a,b);
        cout<<totcmp<<" "<<maxm<<'\n';

    }

    
    

    
    
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
