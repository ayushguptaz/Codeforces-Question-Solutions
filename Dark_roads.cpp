#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve(int m, int n)
{
    // int m,n;
    // cin>>m>>n;
    int totcost = 0;
    vector<vector<pair<int,int>>> graph(m);
    for(int i=0;i<n;i++){
        int n1,n2,wt;
        cin>>n1>>n2>>wt;
        graph[n1].push_back({n2,wt});
        graph[n2].push_back({n1,wt});
        totcost+=wt;
    }
    // int tm,tn;
    // cin>>tm>>tn;
    // cout<<"f";
    int mst = 0;

    // wt , node ;
    priority_queue<pair<int,int>> q1;

    q1.push({0,0});

    vector<bool> visited(m,false);

    while(!q1.empty())
    {
        pair<int,int> p1 = q1.top();
        q1.pop();
        if(visited[p1.second])
        {
            continue;
        }

        visited[p1.second]=true;

        mst+=(-1*p1.first);

        for(auto nbr: graph[p1.second]){
            if(!visited[nbr.first]){
            q1.push({-1*nbr.second,nbr.first});

            }
        }


    }
    // cout<<i<<'\n';
    // cout<<totcost<<'\n';
    // cout<<mst<<'\n';
    cout<<totcost-mst<<'\n';


    

    
    
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    // long long t=1;
    // cin >> t;
    int m, n;
    while(cin >> m >> n, m != 0 || n != 0) {
        solve(m, n);
    }

    return 0;
}
