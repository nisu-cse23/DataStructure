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

// Inorder Traversal: Left → Root → Right
void inorder_traversal(Node* root) {
    if (root == nullptr) return;

    inorder_traversal(root->left);
    cout << root->data << " ";
    inorder_traversal(root->right);
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

    cout << "Inorder traversal: ";
    inorder_traversal(root);
    cout << endl;

    return 0;
}
