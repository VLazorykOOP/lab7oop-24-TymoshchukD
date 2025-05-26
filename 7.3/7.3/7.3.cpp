#include <iostream>

template <typename T>
class BinaryTree {
private:
    struct Node {
        T data;
        Node* left;
        Node* right;

        Node(T value) : data(value), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // Helper to insert recursively
    Node* insert(Node* node, T value) {
        if (node == nullptr)
            return new Node(value);
        if (value < node->data)
            node->left = insert(node->left, value);
        else
            node->right = insert(node->right, value);
        return node;
    }

    // In-order traversal (ascending)
    void inOrder(Node* node) {
        if (node != nullptr) {
            inOrder(node->left);
            std::cout << node->data << " ";
            inOrder(node->right);
        }
    }

    // Reverse in-order traversal (descending)
    void reverseInOrder(Node* node) {
        if (node != nullptr) {
            reverseInOrder(node->right);
            std::cout << node->data << " ";
            reverseInOrder(node->left);
        }
    }

    // Search recursively
    bool search(Node* node, T value) {
        if (node == nullptr)
            return false;
        if (value == node->data)
            return true;
        else if (value < node->data)
            return search(node->left, value);
        else
            return search(node->right, value);
    }

    // Cleanup
    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

public:
    BinaryTree() : root(nullptr) {}

    ~BinaryTree() {
        destroyTree(root);
    }

    void insert(T value) {
        root = insert(root, value);
    }

    void printInOrder() {
        std::cout << "Ascending order: ";
        inOrder(root);
        std::cout << std::endl;
    }

    void printReverseInOrder() {
        std::cout << "Descending order: ";
        reverseInOrder(root);
        std::cout << std::endl;
    }

    bool search(T value) {
        return search(root, value);
    }
};

// Example usage
int main() {
    BinaryTree<int> tree;
    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);
    tree.insert(40);
    tree.insert(60);
    tree.insert(80);

    tree.printInOrder();
    tree.printReverseInOrder();

    int key = 60;
    if (tree.search(key))
        std::cout << "Found " << key << " in the tree." << std::endl;
    else
        std::cout << key << " not found in the tree." << std::endl;

    return 0;
}
