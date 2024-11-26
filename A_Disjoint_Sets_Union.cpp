#include <bits/stdc++.h>
using namespace std;
// #define int long long
#define all(x) begin(x), end(x)
vector<int> parentt;
vector<int> rankk;
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
        if(rankk[a]< rankk[b]){
            swap(a,b);
        }
        parentt[b]=a;
        if(rankk[a]==rankk[b]){
            rankk[a]++;
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
    parentt.resize(n+1);
    rankk.resize(n+1);
    for(int i=1;i<=n;i++){
        parentt[i]=i;
    }
    for(int i=1;i<=n;i++){
        rankk[i]=0;
    }

    // for(int i=)

    for(int i=1;i<=m;i++){
        string q;
        int a,b;
        cin>>q>>a>>b;
        if(q=="union"){
            do_union(a,b);
        }
        else{
            check(a,b);
        }
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
