#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, m; 
    cin>>n>>m; 
    vector<vector<int>>graph(n+1);
    while(m--) {
        int a, b; cin>>a>>b; 
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    queue<int>q; 
    vector<int>parent(n+1, -1);
    vector<bool>visited(n+1, false);

    q.push(1);
    visited[1] = true;

    while(!q.empty()) {
        int node = q.front();  q.pop();

        for(auto negh : graph[node]) {
            if(!visited[negh]) {
                parent[negh] = node;
                visited[negh] = true;
                q.push(negh);
            }
        }
    }
    if(!visited[n]) {
        cout<<"IMPOSSIBLE";   
    }else{
        vector<int>path; 
        path.push_back(n);
        int cur = parent[n];
        while(cur!=-1) {
            path.push_back(cur);
            cur = parent[cur];
        }
        cout<<path.size()<<endl;
        for(int i=(int)path.size()-1; i>=0; i--) {
            cout<<path[i]<<" ";
        }
    }

    
return 0;
}


// better Solution
// #include<bits/stdc++.h>
// using namespace std;
// int main(){
//     int n, m; 
//     cin>>n>>m; 
//     vector<vector<int>>graph(n+1);
//     while(m--) {
//         int a, b; cin>>a>>b; 
//         graph[a].push_back(b);
//         graph[b].push_back(a);
//     }

//     queue<pair<int, pair<int, vector<int>>>>q; 
//     unordered_set<int>visited; 
//     vector<int>v;
//     v.push_back(1);
//     q.push({1, {1, v}});
//     visited.insert(1);

//     int flag = false;
//     while(!q.empty()) {
//         auto pp = q.front(); q.pop();
//         int node = pp.first;
//         int moves = pp.second.first;
//         vector<int>arr = pp.second.second;
//         if(node==n) {
//             cout<<moves<<endl;
//             flag = true;
//             for(int i=0; i<(int)arr.size(); i++) {
//                 cout<<arr[i]<<" ";
//             }
//              break;    
//         }

//         for(auto negh : graph[node]) {
//             if(visited.count(negh)==0) {
//                 arr.push_back(negh);
//                 q.push({negh, {moves+1, arr}});
//                 visited.insert(negh);
//                 arr.pop_back();
//             }
//         }
//     }
//     if(flag==false) {
//         cout<<"IMPOSSIBLE";
//     }
// return 0;
// }