#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* left;
    Node* right;

    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

void preorder_traversal(Node* root) {
    if (root == nullptr) return;

    // Visit current node
    cout << root->data << " ";
    // Traverse left subtree
    preorder_traversal(root->left);
    // Traverse right subtree
    preorder_traversal(root->right);
}

int main() {
    // Creating a simple tree:
    //      A
    //     / \
    //    B   C
    //   / \
    //  D   E
    Node* root = new Node('A');
    root->left = new Node('B');
    root->right = new Node('C');
    root->left->left = new Node('D');
    root->left->right = new Node('E');

    cout << "Preorder traversal: ";
    preorder_traversal(root);

    return 0;
}
