
#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int val;
    Node *left, *right;
    Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Function to create a binary tree from level-order array
Node* buildTree(vector<int> &arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    Node* root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);
    int i = 1;

    while (!q.empty() && i < arr.size()) {
        Node* node = q.front();
        q.pop();

        // Left child
        if (arr[i] != -1) {
            node->left = new Node(arr[i]);
            q.push(node->left);
        }
        i++;

        // Right child
        if (i < arr.size() && arr[i] != -1) {
            node->right = new Node(arr[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}
vector<vector<int>>v;
void f(Node* root, vector<int>a) {
    if(root==NULL) return;
    a.push_back(root->val);
    if(root->left==NULL && root->right==NULL) {
        for(int i=0; i<a.size(); i++) {
            cout<<a[i]<<" ";
        }cout<<endl;
    }
    
    f(root->left, a);
    f(root->right, a);
    // a.pop_back();
}
// Helper function to print inorder traversal
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    int h; cin>>h;
    int n = (2<<h)-1; 
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    Node* root = buildTree(arr);

    // cout << "Inorder Traversal: ";
    vector<int>a;
    f(root, a);
    // inorder(root);
    return 0;
}


