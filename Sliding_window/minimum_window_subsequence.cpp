#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;
string minWindow(string s1, string s2)
{
	int n = s1.size(), m = s2.size();
	int minlen = INT_MAX;
	string ans = "";
	int j=0;
	for(int i=0; i<n; i++) {
		if(s1[i]==s2[j]) {
			j++;
			if(j==m) {
				int end = i;
				j--;

				while(j>=0) {
					if(s1[i]==s2[j]) j--;
					i--;
				}
				i++;
				j++;

				if(end-i+1<minlen) {
					minlen = end-i+1;
					ans = s1.substr(i, minlen);
				}
			}
		}
	}
	return ans;
}
int main(){
cout<<minWindow("abcdebdde", "bde")<<endl; // Output: "bcde"
return 0;
}