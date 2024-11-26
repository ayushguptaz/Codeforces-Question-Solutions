#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
    cin>>n;
    vector<vector<int>> graph(n+1,vector<int>(n+1,0));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            cin>>graph[i][j];
        }
    }
    vector<int> dv(n+1);
    for(int i=1;i<=n;i++){
        cin>>dv[i];
    }
    
    vector<int> answ;
    vector<bool> added(n+1,false);

    for(int vis=n;vis>=1;vis--){
        int sum=0;
        added[dv[vis]]=true;

        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){

                graph[i][j] = min(graph[i][j], graph[i][dv[vis]]+graph[dv[vis]][j]);
                if(added[i] && added[j]){
                    sum+=(graph[i][j]);

                }

            }
        }
        answ.push_back(sum);

    }
    for(int i=n-1;i>=0;i--){
        cout<<answ[i]<<" ";
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

