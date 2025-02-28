#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lcm(int a, int b) {
    return a*b/__gcd(a, b);
}
int main(){
   int a, b, c, n; 
   cin>>a>>b>>c>>n;

    int low = 1, high = 1e9;
    int ans = 1;
    while(low<=high) {
        int mid = low + (high-low)/2;
        
        int cnt = (mid/a)+(mid/b)+(mid/c)-(mid/lcm(a, b))-(mid/lcm(b, c))-(mid/lcm(a, c))+(mid/lcm(a, lcm(b, c)));

        if(cnt>=n) {
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout<<ans;
return 0;
}