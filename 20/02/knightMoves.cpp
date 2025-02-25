#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int minimumKnight(int x, int y) {
    vector<vector<bool>>vist(700, vector<bool>(700, false));
    x+=302;
    y+=302;
    queue<pair<int, int>>q;
    q.push({302, 302});
    int ans = 0;
    vector<vector<int>>dir = {{1,2}, {2, 1}, {1, -2}, {2, -1}, {-1, 2}, {-2, 1}, {-1, -2}, {-2, -1}};
    while(!q.empty()) {
        int sz = q.size();
        for(int k=0; k<sz; k++) {
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;

            if(i==x and j==y) return ans;

            for(auto d : dir) {
                int r = i+d[0];
                int c = j+d[1];
                if(!vist[r][c]){
                    q.push({r, c});
                    vist[r][c]=true;
                }
            }
        }
        ans++;
    }
    return -1;
}
int main(){
int x, y; 
cin>>x>>y;
 cout<<minimumKnight(x, y);
return 0;
}