#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    char data; 
    bool terminal; 
    unordered_map<char, Node*>children;
    int countWordsEnd;
    int countWordsStarting;
    Node(char data) {
        this->data = data;
        this->terminal = false;
        this->countWordsEnd = this->countWordsStarting = 0;
    }
    void makeTerminal() {
        this->terminal = true;
    }
};
class Trie {
    Node* root;
public:
    Trie () {
        root = new Node('\0');
    }

    void insert(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
                curr->countWordsStarting++;
            }else{
                Node* child = new Node(ch);
                curr->children[ch] = child;
                curr = curr->children[ch];
                curr->countWordsStarting++;
            }
        }
        curr->makeTerminal();
        curr->countWordsEnd++;
    }

    int countWordsEqualTo(string word) {
        Node* curr = root;
        for(int  i=0; i<word.size(); i++) {
            char ch = word[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsEnd;
    }

    int countWordsStartingWith(string prefix) {
        Node* curr = root;
        for(int  i=0; i<prefix.size(); i++) {
            char ch = prefix[i];
            if(curr->children.count(ch)) {
                curr = curr->children[ch];
            }else{
                return 0;
            }
        }
        return curr->countWordsStarting;
    }

    void erase(string word) {
        Node* curr = root;
        for(int i=0; i<word.size(); i++) {
            char ch = word[i];
            curr = curr->children[ch];
            curr->countWordsStarting--;
        }
        curr->countWordsEnd--;
    }
};
int main(){
    Trie trie;
trie.insert("apple");               // Inserts "apple".
trie.insert("apple");               // Inserts another "apple".
cout<<trie.countWordsEqualTo("apple");    // There are two instances of "apple" so return 2.
cout<<trie.countWordsStartingWith("app"); // "app" is a prefix of "apple" so return 2.
trie.erase("apple");                // Erases one "apple".
cout<<trie.countWordsEqualTo("apple");    // Now there is only one instance of "apple" so return 1.
cout<<trie.countWordsStartingWith("app"); // return 1
trie.erase("apple");                // Erases "apple". Now the trie is empty.
cout<<trie.countWordsStartingWith("app"); // return 0
return 0;
}