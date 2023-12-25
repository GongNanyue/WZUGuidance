#include <iostream>

template <typename T, typename Compare = std::less<T>>
class BinarySearchTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;
        Node(const T& data) : data(data), left(nullptr), right(nullptr) {}
    };
    Node* root;
    Compare cmp;

public:
    BinarySearchTree() : root(nullptr) {}

    void insert(const T& data) {
        Node** curr = &root;
        while (*curr) {
            if (cmp(data, (*curr)->data)) {
                curr = &((*curr)->left);
            } else {
                curr = &((*curr)->right);
            }
        }
        *curr = new Node(data);
    }

    bool search(const T& data) const {
        Node* curr = root;
        while (curr) {
            if (cmp(data, curr->data)) {
                curr = curr->left;
            } else if (cmp(curr->data, data)) {
                curr = curr->right;
            } else {
                return true;
            }
        }
        return false;
    }

    void inorderTraversal() const {
        inorderTraversal(root);
    }

private:
    void inorderTraversal(Node* node) const {
        if (node) {
            inorderTraversal(node->left);
            std::cout << node->data << " ";
            inorderTraversal(node->right);
        }
    }
};
