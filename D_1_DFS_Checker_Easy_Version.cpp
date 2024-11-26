#include <bits/stdc++.h>
using namespace std;
#define int long long
#define all(x) begin(x), end(x)

const int MAXN = 2e5 + 10;
const int INF = 1e9 + 7;

int parent[MAXN];
vector<int> children[MAXN];

int leafLevel, nodeCount = 0;

void treeDFS(int parentNode, int depth) {
    int currentNode = nodeCount++;
    parent[currentNode] = parentNode;
    if (parentNode != -1) children[parentNode].push_back(currentNode);
    if (depth == leafLevel) return;
    treeDFS(currentNode, depth + 1);
    treeDFS(currentNode, depth + 1);
}

void initialize(int n) {
    for (int i = 0; i <= n; i++) {
        parent[i] = 0;
        children[i].clear();
    }
    int depth = 0;
    while (n) {
        n >>= 1;
        depth++;
    }
    leafLevel = depth;
    nodeCount = -1;
    treeDFS(-1, 0);
}

void solve() {
    int n, q;
    cin >> n >> q;
    initialize(n);

    vector<int> parentMapping(n + 1, 0);
    vector<vector<int>> childList(n + 1);
    for (int i = 2; i <= n; i++) {
        cin >> parentMapping[i];
        childList[parentMapping[i]].push_back(i);
    }

    vector<int> permutation(n);
    for (int i = 0; i < n; i++) {
        cin >> permutation[i];
    }

    int correctCount = 0;
    for (int i = 1; i < n; i++) {
        int parentIndex = parent[i];
        if (permutation[parentIndex] == parentMapping[permutation[i]]) correctCount++;
    }

    for (int i = 0; i < q; i++) {
        int indexA, indexB;
        cin >> indexA >> indexB;
        indexA--; indexB--;
        if (indexB < indexA) swap(indexB, indexA);

        if (indexA) {
            int parentIndex = parent[indexA];
            if (permutation[parentIndex] == parentMapping[permutation[indexA]]) correctCount--;
        }
        if (indexB && parent[indexB] != indexA) {
            int parentIndex = parent[indexB];
            if (permutation[parentIndex] == parentMapping[permutation[indexB]]) correctCount--;
        }
        if (children[indexA].size()) {
            int childIndexA = children[indexA][0];
            if (permutation[indexA] == parentMapping[permutation[childIndexA]]) correctCount--;
            childIndexA = children[indexA][1];
            if (permutation[indexA] == parentMapping[permutation[childIndexA]]) correctCount--;
        }
        if (children[indexB].size()) {
            int childIndexB = children[indexB][0];
            if (permutation[indexB] == parentMapping[permutation[childIndexB]]) correctCount--;
            childIndexB = children[indexB][1];
            if (permutation[indexB] == parentMapping[permutation[childIndexB]]) correctCount--;
        }

        swap(permutation[indexA], permutation[indexB]);

        if (indexA) {
            int parentIndex = parent[indexA];
            if (permutation[parentIndex] == parentMapping[permutation[indexA]]) correctCount++;
        }
        if (indexB && parent[indexB] != indexA) {
            int parentIndex = parent[indexB];
            if (permutation[parentIndex] == parentMapping[permutation[indexB]]) correctCount++;
        }
        if (children[indexA].size()) {
            int childIndexA = children[indexA][0];
            if (permutation[indexA] == parentMapping[permutation[childIndexA]]) correctCount++;
            childIndexA = children[indexA][1];
            if (permutation[indexA] == parentMapping[permutation[childIndexA]]) correctCount++;
        }
        if (children[indexB].size()) {
            int childIndexB = children[indexB][0];
            if (permutation[indexB] == parentMapping[permutation[childIndexB]]) correctCount++;
            childIndexB = children[indexB][1];
            if (permutation[indexB] == parentMapping[permutation[childIndexB]]) correctCount++;
        }

        assert(correctCount < n);
        if (correctCount == n - 1) cout << "YES"<<'\n';
        else {
        cout << "NO"<<'\n';
        }
        
    }
}

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    long long t;
    cin >> t;
    for (long long i = 0; i < t; i++) {
        solve();
    }

    return 0;
}
