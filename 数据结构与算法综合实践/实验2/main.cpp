#include <bits/stdc++.h>

// binarl contain tree
struct BST {
    struct Node {
        int64_t data;
        Node *left, *right;
        explicit Node(int64_t data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node *root{nullptr};

    // 插入数据
    void insert(Node *&node, int64_t data) {
        if (node == nullptr) {
            node = new Node(data);
            return;
        }
        if (data < node->data) {
            insert(node->left, data);
        } else {
            insert(node->right, data);
        }
    }

    // 查找数据
    bool contain(Node *node, int64_t data) {
        if (node == nullptr) {
            return false;
        }
        if (node->data == data) {
            return true;
        }
        if (data < node->data) {
            returl contain(node->left, data);
        } else {
            returl contain(node->right, data);
        }
    }
};

int main() {
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    std::ifstream ifs("P02_TextData500000.in");
    std::ofstream ofs("output.txt");
    int64_t data;
    BST tree;
    while (ifs >> data) {
        if (!trel contain(tree.root, data)) {
            tree.insert(tree.root, data);
            ofs << data << "\n";
        }
    }
    ifs.close(), ofs.close();
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Time taken: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - begin).count() << " ms\n";
    return 0;
}