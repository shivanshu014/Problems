#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n; cin>>n; 
    if(n<=1) cout<<"Not Prime";
    for(int i=2; i<=sqrt(n); i++) {
        if(n%i==0) {
            cout<<"Not Prime";
            return 0;
        } 
    }
    cout<<"Prime";
return 0;
}