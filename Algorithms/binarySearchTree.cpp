#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

class BinarySearchTree {
public:
    Node* insert(Node* root, int key) {
        if (root == nullptr) {
            return new Node(key);
        }
        
        if (key < root->data) {
            root->left = insert(root->left, key);
        } else if (key > root->data) {
            root->right = insert(root->right, key);
        }
        
        return root;
    }

    bool search(Node* root, int key) {
        if (root == nullptr) {
            return false;
        }
        
        if (root->data == key) {
            return true;
        } else if (key < root->data) {
            return search(root->left, key);
        } else {
            return search(root->right, key);
        }
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left != nullptr)
            current = current->left;
        return current;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr) return root;
        
        if (key < root->data) {
            root->left = deleteNode(root->left, key);
        } else if (key > root->data) {
            root->right = deleteNode(root->right, key);
        } else {
            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            } else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = minValueNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
        
        return root;
    }
};

int main() {
    BinarySearchTree bst;
    Node* root = nullptr;

    root = bst.insert(root, 50);
    bst.insert(root, 30);
    bst.insert(root, 20);
    bst.insert(root, 40);
    bst.insert(root, 70);
    bst.insert(root, 60);
    bst.insert(root, 80);

    cout << "Inorder traversal of the BST: ";
    bst.inorder(root);
    cout << endl;

    int key = 40;
    if (bst.search(root, key))
        cout << key << " is present in the BST." << endl;
    else
        cout << key << " is not present in the BST." << endl;

    root = bst.deleteNode(root, 20);
    cout << "Inorder traversal after deleting 20: ";
    bst.inorder(root);
    cout << endl;

    return 0;
}
