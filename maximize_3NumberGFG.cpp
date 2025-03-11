#include<
using namespace std;
int dp[105][105][105];
int f(int i, int j, int k, vector<int>&arr, int x, int y, int z) {
    if(i>j || j>k || k>=arr.size()) return INT_MIN;
    if(i==arr.size()) return 0;

    if(dp[i][j][k]!=-1) return dp[i][j][k];

    int ch1 = f(i+1, j, k, arr, x, y, z);
    int ch2 = f(i, j+1, k, arr, x, y, z);
    int ch3 = f(i, j, k+1, arr, x, y, z);

    return dp[i][j][k] = max(x*arr[i]+y*arr[j]+z*arr[k], max({ch1, ch2, ch3}));
}
int maxi(vector<int>&arr, int x, int y, int z) {
    memset(dp, -1, sizeof(dp));
    return f(0, 0, 0, arr, x, y, z);
}
int main(){
    int n; cin>>n;
    vector<int>arr(n);
    // int a;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    int x, y, z; 
    cin>>x>>y>>z;

    cout<<maxi(arr, x, y, z);
return 0;
}