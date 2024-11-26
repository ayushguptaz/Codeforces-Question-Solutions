#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)
void solve()
{
    int n;
        cin >> n;
        vector<int> a(n), b(n);
        
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        int i = 0, i1 = 0;
        int j = n - 1, j1 = n - 1;
        bool fl = true;
        
        while (i <= j) {
            if (a[i] == b[i1] && a[j] == b[j1]) {
                i++;
                i1++;
            } else if (a[i] == b[j1] && a[j] == b[i1]) {
                i++;
                j1--;
            } else {
                fl = false;
                break;
            }
        }
        
        if (fl) {
            cout << "Bob" << endl;
        } else {
            cout << "Alice" << endl;
        }
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


 


