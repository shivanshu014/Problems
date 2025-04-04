#include<bits/stdc++.h>
using namespace std;
int main(){ 
    string s; 
    cin>>s; 
    vector<int>res; 
    stringstream ss(s);
    string temp;
    while(getline(ss, temp, '#')) {
        res.push_back(stoi(temp));
    }
    for(int i=0; i<res.size(); i++) {
        cout<<res[i]<<" ";
    }
return 0;
}