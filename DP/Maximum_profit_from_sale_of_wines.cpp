#include<bits/stdc++.h>
using namespace std;
int dp[305][305];
string s[305][305];
pair<int, string> f(vector<int>&prices, int start, int end, int i) {
    if(start>end) return {0, ""};

    if(dp[start][end]!=-1) return {dp[start][end], s[start][end]};

    auto front = f(prices, start+1, end, i+1);
    int fontval = prices[start]*i + front.first;

    auto back = f(prices, start, end-1, i+1);
    int backval = prices[end]*i + back.first;

    if(fontval>backval) {
        dp[start][end] = fontval;
        s[start][end] = "beg " + front.second;
    }else{ 
        dp[start][end] = backval;
        s[start][end] = "end " + back.second;
    }

    return {dp[start][end], s[start][end]};
}
int main(){
    int n; cin>>n; 
    memset(dp, -1, sizeof(dp));
    vector<int>prices(n);
    for(int i=0; i<n; i++) cin>>prices[i];
    cout<<f(prices, 0, n-1, 1).first;
    cout<<f(prices, 0, n-1, 1).second;
return 0;
}