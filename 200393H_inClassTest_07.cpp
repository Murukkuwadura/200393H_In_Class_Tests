#include <iostream>
using namespace std;

struct Node {
    int data;
    struct Node* left, * right;
};

// Inorder traversal
void traverseInOrder(struct Node* root) {
    if (root != NULL) {
        traverseInOrder(root->left);
        cout << root->data << " ";
        traverseInOrder(root->right);
    }
}

// Insert a node
struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = new Node;
        newNode->data = data;
        newNode->left = newNode->right = NULL;
        return newNode;
    }
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

// Find the node with the minimum data value in a BST
struct Node* findMinNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

// Deleting a node
struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL)
        return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            delete root;
            return temp;
        }
        struct Node* temp = findMinNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Driver code
int main() {
    struct Node* root = NULL;

    int operation;
    int operand;
    cin >> operation;

    while (operation != -1) {
        switch (operation) {
        case 1: // insert
            cin >> operand;
            root = insertNode(root, operand);
            cin >> operation;
            break;
        case 2: // delete
            cin >> operand;
            root = deleteNode(root, operand);
            cin >> operation;
            break;
        default:
            cout << "Invalid Operator!\n";
            return 0;
        }
    }

    traverseInOrder(root);
    cout << endl;
    return 0;
}
