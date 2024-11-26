#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
const int MAXN = 200010;
const int INF = 1000000007;

void solve(){
    int num_points; 
    cin >> num_points;
    vector<pair<int, int>> coordinates(num_points);

    for(int i = 0; i < num_points; i++){
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    pair<int, int> start, end;
    cin >> start.first >> start.second >> end.first >> end.second;

    int distance_sq = (start.first - end.first) * (start.first - end.first)
                    + (start.second - end.second) * (start.second - end.second);

    for(int i = 0; i < num_points; i++){
        int dist_sq_to_point = (coordinates[i].first - end.first) * (coordinates[i].first - end.first)
                             + (coordinates[i].second - end.second) * (coordinates[i].second - end.second);

        if(dist_sq_to_point <= distance_sq){
            cout << "NO\n";
            return;
        }
    }

    cout << "YES\n";
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
