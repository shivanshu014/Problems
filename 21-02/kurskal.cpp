#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    vector<int>parent, rank, size;
public: 
    DisjointSet(int n) {
        parent.resize(n+1);
        rank.resize(n+1, 0);
        size.resize(n+1);
        for(int i=0; i<=n; i++) {
            parent[i]=i;
            size[i]=1;
        }
    }

    int findUpar(int x) {
        if(x==parent[x]) return x;
        return parent[x] = findUpar(parent[x]);
    }   

    void UnionbyRank(int a, int b) {
        a = findUpar(a);
        b = findUpar(b);
        if(a==b) return;
        if(rank[a]>rank[b]) {
            parent[b]=a;
        }else if(rank[a]<rank[b]) {
            parent[a]=b;
        }else{
            parent[b]=a;
            rank[a]++;
        }
    }

    void UnionbySize(int a, int b) {
        a = findUpar(a);
        b = findUpar(b);
        if(a==b) return;
        if(size[a]>size[b]) {
            parent[b]=a;
            size[a]+=size[b];
        }else if(size[a]<size[b]) {
            parent[a]=b;
            size[b]+=size[a];
        }
    }
};


int kurskal(int v, vector<vector<int>>graph[]) {
    vector<pair<int, pair<int, int>>>edges;
    for(int i=0; i<v; i++) {
        for(auto el : graph[i]){
            int adjNode = el[0];
            int wt = el[1];
            int node = i;
            edges.push_back({wt, {node, adjNode}});
        }
    }
    sort(edges.begin(), edges.end());
    int edgecount = 0;
    int wtcount = 0;
    int i=0;
    DisjointSet dj(v);
    while(i<edges.size()){
        int a = edges[i].second.first;
        int b = edges[i].second.second;
        if(dj.findUpar(a)!=dj.findUpar(b)) {
            dj.UnionbySize(a, b);
            edgecount++;
            wtcount+=edges[i].first;
        }
        if(edgecount==v-1) break;
    }
    return wtcount;
}
int main(){
    int v = 5;
    vector<vector<int>>edges = {{0, 1, 2}, {0, 2, 1}, {1, 2, 1}, {2, 3, 2}, {3, 4, 1}, {4, 2, 2}};
    vector<vector<int>>graph[v];
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0], v = edges[i][1], weight = edges[i][2];
        graph[u].push_back({v, weight});
        graph[v].push_back({u, weight});
    }
    cout<<kurskal(v, graph);
return 0;
}