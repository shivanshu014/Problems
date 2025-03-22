#include <bits/stdc++.h>
using namespace std;

bool isValidBFS(vector<vector<int>>& edges, vector<int>& v, int n) {
    vector<vector<int>> graph(n + 1);
    vector<bool> visited(n + 1, false);
    unordered_map<int, int> pos;

    // Construct adjacency list
    for (auto &ed : edges) {
        int a = ed[0], b = ed[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // Store positions of nodes in the given order `v`
    for (int i = 0; i < n; i++) {
        pos[v[i]] = i;
    }

    // Sort adjacency list based on appearance in `v`
    for (int i = 1; i <= n; i++) {
        sort(graph[i].begin(), graph[i].end(), [&](int x, int y) {
            return pos[x] < pos[y];
        });
    }

    queue<int> q;
    q.push(1);
    visited[1] = true;
    int idx = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (v[idx++] != node) return false; // Order mismatch

        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                q.push(neighbor);
            }
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<vector<int>> edges(n - 1);

    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        edges[i] = {a, b};
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    cout << (isValidBFS(edges, v, n) ? "true" : "false") << endl;
    return 0;
}
