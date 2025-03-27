#include<bits/stdc++.h>
using namespace std;
vector<int>lps;
void preKMP(string &pattern) {
    int n = pattern.size();
    lps.assign(n, 0);
    int i = 0;
    for(int j=1; j<n; j++) {
        while(i>0 and pattern[i]!=pattern[j]) {
            i = lps[i-1];
        }
        if(pattern[i]==pattern[j]) {
            lps[j] = i+1;
            i++;
        }
    }
}
int KMP(string &text, string &pattern) {
    preKMP(pattern);
    int j=0; 
    int n = pattern.size();
    for(int i=0; i<text.size(); i++) {
        while(j>0 and pattern[j]!=text[i]) {
            j = lps[j-1];
        }
        if(text[i]==pattern[j]) {
            j++;
        }
        if(j==n) return i-j+1;
    }
    return -1;
}
int main(){
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    cout<<KMP(text, pattern);
return 0;
}