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

// Postorder Traversal: Left → Right → Root
void postorder_traversal(Node* root) {
    if (root == nullptr) return;

    postorder_traversal(root->left);
    postorder_traversal(root->right);
    cout << root->data << " ";
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

    cout << "Postorder traversal: ";
    postorder_traversal(root);
    cout << endl;

    return 0;
}
