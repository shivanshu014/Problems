#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string manacher(const string &s) {
    string t = "#";
    for (char c : s) {
        t += c;
        t += "#";
    }
    int n = t.size();
    vector<int> p(n, 0);
    int c = 0, r = 0;
    
    for (int i = 0; i < n; ++i) {
        int mirror = 2 * c - i;
        
        if (i < r) {
            p[i] = min(r - i, p[mirror]);
        }
        
        while (i + p[i] + 1 < n && i - p[i] - 1 >= 0 && t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;
        }
        
        if (i + p[i] > r) {
            c = i;
            r = i + p[i];
        }
    }
    
    int max_len = 0, center_index = 0;
    for (int i = 0; i < n; ++i) {
        if (p[i] > max_len) {
            max_len = p[i];
            center_index = i;
        }
    }
    
    int start = (center_index - max_len) / 2;
    return s.substr(start, max_len);
}

int main() {
    string s = "babad";
    cout << manacher(s) << endl;  // Output: "bab" or "aba"
    return 0;
}

