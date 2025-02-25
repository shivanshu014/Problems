#include<iostream>
#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;
vector<vector<int>>graph;
vector<int> toplogy(int numCourse, vector<vector<int>>&v) {
    vector<int>indegree(numCourse, 0);
    unordered_set<int>vist;
    for(int i=0; i<numCourse; i++) {
        for(auto neg : graph[i]){
            indegree[neg]++;
        }
    }
    queue<int>q;
    for(int i=0; i<numCourse; i++) {
        if(indegree[i]==0) {
            q.push(i);
            vist.insert(i);
        }
    }
    vector<int>res;
    while(!q.empty()) {
        auto curr = q.front(); q.pop(); v    
        res.push_back(curr);
        for(auto neg : graph[curr]) {
            if(!vist.count(neg)) {
                indegree[neg]--;
                if(indegree[neg]==0) {
                    q.push(neg);
                    vist.insert(neg);
                }
            }
        }
    }
    if(res.size()!=numCourse) return {};
    return res;
}
vector<int> course(int numCourse, vector<vector<int>>&v) {
    graph.resize(numCourse, vector<int>());
    for(int i=0; i<v.size(); i++) {
        int a = v[i][1], b = v[i][0];
        graph[a].push_back(b);
    }
    return toplogy(numCourse, v);
}
int main(){
    int numCourse; cin>>numCourse;
    int n; cin>>n;
    vector<vector<int>>v;
    for(int i=0; i<n; i++) {
        int a , b;
        cin>>a>>b;
        v.push_back({a, b});
    }
 

    vector<int>ans = course(numCourse, v);
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i]<<" ";
    }
return 0;
}