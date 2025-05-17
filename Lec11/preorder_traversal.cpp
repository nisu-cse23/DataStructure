#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
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
    //      1
    //     / \
    //    2   3
    //   / \
    //  4   5
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Preorder traversal: ";
    preorder_traversal(root);

    return 0;
}
