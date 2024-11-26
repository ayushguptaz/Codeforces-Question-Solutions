#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
vector<int> dx = {0, 0, -1, 1};
vector<int> dy = {1, -1, 0, 0};

void dfs(vector<string> &v1, vector<vector<bool>> &visited, int x, int y, int fromX, int fromY, bool &flag, char needcolour, int n, int m)
{

    if (x >= n || x < 0 || y >= m || y < 0)
    {
        return;
    }
    if (v1[x][y] != needcolour)
    {
        return;
    }
    if (visited[x][y])
    {
        flag = true;
        return;
    }
    visited[x][y] = true;
    // cout << x << " " << y << '\n';
    for (int f = 0; f < 4; f++)
    {
        int nextX = x + dx[f];
        int nextY = y + dy[f];
        // if (nextX == fromX && nextY == fromY)
        // {
        //     continue;
        // }

        dfs(v1, visited, nextX, nextY, x, y, flag, needcolour, n, m);
    }
}
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> v1(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v1[i];
    }
    bool flag = false;
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    for (int x = 0; x < n; x++)
    {
        for (int y = 0; y < m; y++)
        {

            if (!visited[x][y])
            {
                dfs(v1, visited, x, y, -1, -1, flag, v1[x][y], n, m);
                if (flag)
                {
                    cout << "Yes" << '\n';
                    return;
                }
                
            }
        }
    }
    cout << "No" << '\n';
    return;
}
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t = 1;
    // cin >> t;
    for (long long i = 0; i < t; i++)
    {
        solve();
    }

    return 0;
}
