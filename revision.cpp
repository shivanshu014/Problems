#include<iostream>
#include<vector>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node( int val) {
        this->val = val;
        this->next = NULL;
    }
};

Node* contruct(vector<int>&v) {
    if(v.empty()) return NULL;
    Node* head = new Node(v[0]);
    Node* temp = head;
    for(int i=1; i<v.size(); i++) {
        temp->next = new Node(v[i]);
        temp = temp->next;
    }
    return head;
}

void print(Node* head) {
    Node* temp = head;
    while(temp) {
        cout<<temp->val<<"->";
        temp = temp->next;
    }
}
int main(){
    vector<int>v = {1, 2, 4, 5, 5};
    Node* head = contruct(v);
    print(head);
return 0;
}