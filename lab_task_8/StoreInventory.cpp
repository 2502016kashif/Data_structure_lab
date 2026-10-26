
#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
private:
    Node* root;

    Node* insertNode(Node* node, int value) {
        if (node == nullptr)
            return new Node(value);

        if (value < node->data)
            node->left = insertNode(node->left, value);
        else if (value > node->data)
            node->right = insertNode(node->right, value);
        else
            cout << "Duplicate product ID not allowed.\n";

        return node;
    }

    bool searchNode(Node* node, int value) {
        if (node == nullptr)
            return false;

        if (node->data == value)
            return true;

        if (value < node->data)
            return searchNode(node->left, value);

        return searchNode(node->right, value);
    }

    Node* findMin(Node* node) {
        while (node->left != nullptr)
            node = node->left;

        return node;
    }

    Node* deleteNode(Node* node, int value) {
        if (node == nullptr)
            return nullptr;

        if (value < node->data) {
            node->left = deleteNode(node->left, value);
        }
        else if (value > node->data) {
            node->right = deleteNode(node->right, value);
        }
        else {
            if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            }

            if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }

            Node* temp = findMin(node->right);
            node->data = temp->data;
            node->right = deleteNode(node->right, temp->data);
        }

        return node;
    }

    void inorderNode(Node* node) {
        if (node == nullptr) return;

        inorderNode(node->left);
        cout << node->data << " ";
        inorderNode(node->right);
    }

    void preorderNode(Node* node) {
        if (node == nullptr) return;

        cout << node->data << " ";
        preorderNode(node->left);
        preorderNode(node->right);
    }

    void postorderNode(Node* node) {
        if (node == nullptr) return;

        postorderNode(node->left);
        postorderNode(node->right);
        cout << node->data << " ";
    }

    void destroy(Node* node) {
        if (node == nullptr) return;

        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BST() {
        root = nullptr;
    }

    ~BST() {
        destroy(root);
    }

    void insert(int value) {
        root = insertNode(root, value);
    }

    void search(int value) {
        if (searchNode(root, value))
            cout << "Product Found.\n";
        else
            cout << "Product Not Found.\n";
    }

    void remove(int value) {
        if (!searchNode(root, value)) {
            cout << "Product Not Found.\n";
            return;
        }

        root = deleteNode(root, value);
        cout << "Product deleted successfully.\n";
    }

    void inorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        inorderNode(root);
        cout << endl;
    }

    void preorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        preorderNode(root);
        cout << endl;
    }

    void postorder() {
        if (root == nullptr) {
            cout << "Tree is empty.\n";
            return;
        }

        postorderNode(root);
        cout << endl;
    }
};

int main() {
    BST tree;
    int choice, id;

    do {
        cout << "\n--- Online Store Inventory ---\n";
        cout << "1. Insert Product ID\n";
        cout << "2. Search Product ID\n";
        cout << "3. Delete Product ID\n";
        cout << "4. Display In-order\n";
        cout << "5. Display Pre-order\n";
        cout << "6. Display Post-order\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter product ID: ";
            cin >> id;
            tree.insert(id);
            break;

        case 2:
            cout << "Enter product ID to search: ";
            cin >> id;
            tree.search(id);
            break;

        case 3:
            cout << "Enter product ID to delete: ";
            cin >> id;
            tree.remove(id);
            break;

        case 4:
            cout << "In-order: ";
            tree.inorder();
            break;

        case 5:
            cout << "Pre-order: ";
            tree.preorder();
            break;

        case 6:
            cout << "Post-order: ";
            tree.postorder();
            break;

        case 7:
            cout << "Exiting program.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 7);

    return 0;
}
