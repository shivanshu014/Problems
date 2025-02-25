// Input: num = "1432219", k = 3
// Output: "1219"

#include<bits/stdc++.h>
using namespace std;
string f(string s, int k) {
    stack<char>st;
    for(int i=0; i<s.size(); i++) {
        while(!st.empty() && k>0 && s[i]<st.top()) {
            st.pop();
            k--;
        }
        st.push(s[i]);
    }
    string ans = "";
    while(k-->0) {
        st.pop();
    }
    while(!st.empty()) {
        ans+=st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());

    int step = 0;
    while(ans[step]=='0') {
        step++;
    }
    ans = ans.substr(step);
    return ans.empty() ? "0" : ans;
}
int main(){
    string s; 
    cin>>s;
    int k; cin>>k;
    cout<<f(s, k);
return 0;
}