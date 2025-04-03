#include<iostream>
#include<string>
using namespace std;
int main(){
    string text = "abxabcabcaby";
    string pattern = "abcaby";
    if(text.find(pattern)!=string::npos) {
        cout<<"Yes";
    }else{
        cout<<"No";
    }
    
return 0;
}