#ifndef BST_H
#define BST_H

#include <memory>
#include <functional>
#include <vector>

// Generic binary search tree. Expects a key extractor for comparisons.

template <typename T>
class BST {
    struct Node {
        T data;
        std::unique_ptr<Node> left;
        std::unique_ptr<Node> right;
        Node(const T &d) : data(d), left(nullptr), right(nullptr) {}
    };

    std::unique_ptr<Node> root;
    std::function<bool(const T &, const T &)> comp;

public:
    BST(std::function<bool(const T &, const T &)> comparator)
        : root(nullptr), comp(comparator) {}

    void insert(const T &value) {
        root = insertRec(std::move(root), value);
    }

    void remove(const T &value) {
        root = removeRec(std::move(root), value);
    }

    T *search(const T &value) {
        Node *curr = root.get();
        while (curr) {
            if (comp(value, curr->data)) {
                curr = curr->left.get();
            } else if (comp(curr->data, value)) {
                curr = curr->right.get();
            } else {
                return &curr->data;
            }
        }
        return nullptr;
    }

    void inOrder(std::vector<T> &vec) {
        inOrderRec(root.get(), vec);
    }

private:
    std::unique_ptr<Node> insertRec(std::unique_ptr<Node> node,
                                    const T &value) {
        if (!node) return std::make_unique<Node>(value);
        if (comp(value, node->data))
            node->left = insertRec(std::move(node->left), value);
        else
            node->right = insertRec(std::move(node->right), value);
        return node;
    }

    std::unique_ptr<Node> removeRec(std::unique_ptr<Node> node,
                                    const T &value) {
        if (!node) return node;
        if (comp(value, node->data)) {
            node->left = removeRec(std::move(node->left), value);
        } else if (comp(node->data, value)) {
            node->right = removeRec(std::move(node->right), value);
        } else {
            if (!node->left) return std::move(node->right);
            if (!node->right) return std::move(node->left);
            Node *minNode = findMin(node->right.get());
            node->data = minNode->data;
            node->right = removeRec(std::move(node->right), minNode->data);
        }
        return node;
    }

    Node *findMin(Node *node) {
        while (node && node->left) node = node->left.get();
        return node;
    }

    void inOrderRec(Node *node, std::vector<T> &vec) {
        if (!node) return;
        inOrderRec(node->left.get(), vec);
        vec.push_back(node->data);
        inOrderRec(node->right.get(), vec);
    }
};

#endif // BST_H
