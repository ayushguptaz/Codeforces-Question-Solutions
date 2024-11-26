#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> v1(n+1);
    vector<int> degree(n+1,0);    
    for(int i=0;i<n-1;i++){
        int x,y;
        cin>>x>>y;
        v1[x].push_back(y);
        v1[y].push_back(x);
        degree[x]++;
        degree[y]++;
    }
    bool flag = true;
    int d2 = 0;
    vector<int> leaf;
    int node = -1;
    for(int i=0;i<n+1;i++){
        if(degree[i]>2){
            d2++;
            node = i;
            flag = false;
        }
        if(degree[i]==1){
            leaf.push_back(i);
        }
    }
    if(d2>1){
        cout<<"No"<<'\n';
    }
    else{
        cout<<"Yes"<<'\n';
        if(flag){
            cout<<1<<'\n';
            for(auto n: leaf){
            cout<<n<<" ";
        }
        }
        else{
        
        cout<<leaf.size()<<'\n';
        for(auto n: leaf){
            cout<<node<<" "<<n<<'\n';
        }
        


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
