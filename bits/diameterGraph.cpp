#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1e6 + 5; // Max nodes limit

vector<int> graph[MAX_N]; // Adjacency list
int farthestNode, maxDist;

// Optimized BFS using array instead of unordered_map
void bfs(int src, int& diameter) {
    queue<int> q;
    vector<int> dist(MAX_N, -1); // Using vector instead of unordered_map

    q.push(src);
    dist[src] = 0;

    farthestNode = src;
    maxDist = 0;

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        for (int neighbor : graph[node]) {
            if (dist[neighbor] == -1) { // If not visited
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);

                if (dist[neighbor] > maxDist) {
                    maxDist = dist[neighbor];
                    farthestNode = neighbor;
                }
            }
        }
    }
    diameter = maxDist;
}

int main() {
    ios::sync_with_stdio(0); // Fast I/O
    cin.tie(0); 

    int q;
    cin >> q;

    int x = 2; // Next node to be added
    int root = 1; // Start from node 1

    int diameter = 0;
    
    while (q--) {
        int p;
        cin >> p;

        graph[p].push_back(x);
        graph[x].push_back(p);
        
        bfs(root, diameter);
        bfs(farthestNode, diameter);

        cout << "Current Diameter: " << diameter << '\n';

        x++; // Move to next node
    }

    return 0;
}
