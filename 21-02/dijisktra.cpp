#include<bits/stdc++.h>
using namespace std;
vector<int> diji(int v, vector<vector<int>>adj[], int s) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>>pq;
    vector<int>dist(v, INT_MAX);
    pq.push({0, s});
    dist[s]=0;
    
    while(!pq.empty()) {
        auto curr = pq.top();pq.pop();
        int dis = curr.first;
        int node = curr.second;

        for(auto negh : adj[node]) {
            int adjNode = negh[0]; 
            int wt = negh[1];
            if(dis+wt<dist[adjNode]) {
                dist[adjNode]= dis+wt;
                pq.push({dis+wt, adjNode});
            }
        }
    }
    return dist;
}
int main(){
    int V = 3, E = 3, S = 2;
    vector<vector<int>> adj[V];
    vector<vector<int>> edges;
    vector<int> v1{1, 1}, v2{2, 6}, v3{2, 3}, v4{0, 1}, v5{1, 3}, v6{0, 6};
    int i = 0;
    adj[0].push_back(v1);
    adj[0].push_back(v2);
    adj[1].push_back(v3);
    adj[1].push_back(v4);
    adj[2].push_back(v5);
    adj[2].push_back(v6);
   vector<int>ans = diji(V, adj, S);
   for(int i=0; i<ans.size(); i++) {
    cout<<ans[i]<<" ";
   }
return 0;
}