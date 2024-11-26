#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)


bool dfs(vector<vector<pair<int,int>>> &graphh, set<int> &s1,int curr, int parent, int broken){
    bool check = false;
    for(auto nbr: graphh[curr])
    {
        if(nbr.first!=parent)
        {
            check = check | dfs(graphh,s1,nbr.first,curr,nbr.second);
        }
    }
    // cout<<check<<" "<<curr<<" "<<parent<<" "<<graphh[curr].second<<'\n';
    if(check==false && broken==2){
        // cout<<curr<<" "<<parent<<'\n';
        s1.insert(curr);
        return true;
    }
    return check;
    
}

void solve(){
    int n;
    cin>>n;
    vector<int> v1(n+1);
    vector<vector<pair<int,int>>> graphh(n+1);
    for(int i=1;i<=n;i++){
        int x,y,z;
        cin>>x>>y>>z;
        graphh[x].push_back({y,z});
        graphh[y].push_back({x,z});
    }
    set<int> s1;
    bool check = false;
    dfs(graphh,s1,1,-1,0);
    cout<<s1.size()<<'\n';
    for(auto i: s1){
        cout<<i<<" ";
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
