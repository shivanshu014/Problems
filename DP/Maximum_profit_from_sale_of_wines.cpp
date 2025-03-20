#include<iostream>
#include<vector>
using namespace std;
pair<int, string> f(vector<int>&prices, int start, int end, int i) {
    if(i==prices.size()+1) return {0, ""};
    
    auto front = f(prices, start+1, end, i+1);
    int fontval = prices[start]*i +front.first;

    auto back = f(prices, start, end-1, i+1);
    int backval = prices[end]*i + back.first;

    if(fontval>backval) {
        return {fontval, "beg " + front.second};
    }else{ 
        return {backval, "end " + back.second};
    }
}
int main(){
    int n; cin>>n; 
    vector<int>prices(n);
    for(int i=0; i<n; i++) cin>>prices[i];
    cout<<f(prices, 0, n-1, 1).first;
    cout<<f(prices, 0, n-1, 1).second;
return 0;
}