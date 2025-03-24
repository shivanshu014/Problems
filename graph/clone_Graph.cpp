#include<bits/stdc++.h>
using namespace std;

class Node {
public: 
    int data;
    vector<Node*>negh;
    Node(int data ) {
        this->data = data;
    }
};
vector<Node*>neghNode;
void dfs(Node* actual, Node* clone) {
    for(auto negh : actual->negh) {
        if(!neghNode[negh->data]) {
            Node* newNode = new Node(negh->data);
            neghNode[newNode->data] = newNode;
            clone->negh.push_back(newNode);
            dfs(negh, newNode);
        }
        else{
            clone->negh.push_back(neghNode[negh->data]);
        }
    }
}
class cloneGraph {
public:
    Node* cloneGraphFunction(Node* node) {
        if(node==NULL) return NULL;
        Node* clone = new Node(node->data);
        neghNode.resize(101, NULL);
        neghNode[clone->data] = clone;
        dfs(node, clone);
        return clone;
    }
};
void printGraph(Node* node, unordered_map<int, bool>& visited) {
    if (!node || visited[node->data]) return;

    visited[node->data] = true;
    cout << "Node " << node->data << " -> {";
    
    for (auto neighbor : node->negh) {
        cout << neighbor->data << " ";
    }
    cout << "}" << endl;

    for (auto neighbor : node->negh) {
        printGraph(neighbor, visited);
    }
}

int main() {
    // Creating a sample graph
    Node* node1 = new Node(1);
    Node* node2 = new Node(2);
    Node* node3 = new Node(3);
    Node* node4 = new Node(4);

    node1->negh.push_back(node2);
    node1->negh.push_back(node4);
    node2->negh.push_back(node1);
    node2->negh.push_back(node3);
    node3->negh.push_back(node2);
    node3->negh.push_back(node4);
    node4->negh.push_back(node1);
    node4->negh.push_back(node3);

    cloneGraph cl;
    Node* clonedGraph = cl.cloneGraphFunction(node1);

    // Printing the cloned graph
    unordered_map<int, bool> visited;
    cout << "Cloned Graph: " << endl;
    printGraph(clonedGraph, visited);

    return 0;
}