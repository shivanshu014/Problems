#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long
int main(){
    ll n, m, k; 
    cin>>n>>m>>k; 

    vector<ll>a(n), b(m);
    for(int i=0; i<n; i++) cin>>a[i];
    for(int i=0; i<m; i++) cin>>b[i];

    a.insert(a.begin(), 0);
    b.insert(b.begin(), 0);
    int x = b.size(), y =a.size();
    for(int i=1; i<x; i++) b[i]+=b[i-1];
    for(int i=1; i<y; i++) a[i]+=a[i-1];

    ll total = 0;
    for(int i=0; i<n+1; i++) {
        ll other = k-a[i];
        if(other<0) continue;
        ll j = upper_bound(b.begin(), b.end(), other)-b.begin()-1;

        // if(j>m+1 || b[j]>other){
        //     j--;
        // }

        total = max(total, i+j);
    }
    cout<<total;
return 0;
}