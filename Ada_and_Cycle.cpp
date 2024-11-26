#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void bfs(int curr, vector<vector<int>> &graph, vector<bool> &visited, bool &flag, int &cnt){

    queue<pair<int,int>> q1;
    q1.push(make_pair(curr,0));
    visited[curr]=true;
    while(!q1.empty())
    {

        pair<int,int> p1 = q1.front();
        int node = p1.first;
        int dis  = p1.second;
        q1.pop(); 
        for(auto nbr: graph[node]){
            if(!visited[nbr]){
                q1.push(make_pair(nbr,dis+1));
                
                visited[nbr]=true;
            }
            if(nbr==curr){
                flag=true;
                cnt = dis+1;
                return;

            }
        }
    }

    

}
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1);
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            int x;
            cin>>x;
                if(x==1){
                    graph[i].push_back(j);
                    
                }
                
        
        }
    }
    for(int i=1;i<=n;i++)
    {
        vector<bool> visited(n+1,false);
        bool flag = false;
        int cnt = 0;
         
        bfs(i,graph,visited, flag, cnt);
        if(flag){
            cout<<cnt<<'\n';
        }
        else{
            cout<<"NO WAY"<<'\n';
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
