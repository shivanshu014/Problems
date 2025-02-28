#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int  f(vector<int>&v, int i, int sum1, int sum, vector<vector<int>>&dp) {
    if(i==v.size()){
        return abs(sum1-(sum-sum1));
    }
    if(dp[i][sum1]!=-1) return dp[i][sum1];
    int in = f(v, i+1, sum1+v[i], sum, dp);
    int ex = f(v, i+1, sum1, sum, dp);

    return dp[i][sum1] = min(in, ex);
}
int main(){
    int n; cin>>n;
    vector<int>v(n);
    int sum = 0;
    for(int i=0; i<n; i++) {
        cin>>v[i];
        sum+=v[i];
    }
    vector<vector<int>>dp(105, vector<int>(100005, -1));
    cout<<f(v, 0, 0, sum, dp);
return 0;
}