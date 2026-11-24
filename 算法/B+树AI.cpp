
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class BPlusTree {
    struct Node {
        bool leaf;
        vector<int> keys;
        vector<Node*> children;
        Node* parent;
        Node* next;
        Node* prev;

        explicit Node(bool isLeaf)
            : leaf(isLeaf), parent(nullptr), next(nullptr), prev(nullptr) {}

        ~Node() {
            for (Node* child : children) {
                delete child;
            }
        }
    };

public:
    // 每个节点最多有 2 * degree - 1 个关键字。
    explicit BPlusTree(int minimumDegree) : root(nullptr), degree(minimumDegree) {
        if (degree < 2) {
            throw invalid_argument("minimum degree must be at least 2");
        }
    }

    ~BPlusTree() {
        delete root;
    }

    BPlusTree(const BPlusTree&) = delete;
    BPlusTree& operator=(const BPlusTree&) = delete;

    bool search(int key) const {
        Node* leaf = findLeaf(key);
        return leaf != nullptr &&
               binary_search(leaf->keys.begin(), leaf->keys.end(), key);
    }

    void insert(int key) {
        if (root == nullptr) {
            root = new Node(true);
            root->keys.push_back(key);
            return;
        }

        Node* leaf = findLeaf(key);
        vector<int>::iterator position =
            lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
        if (position != leaf->keys.end() && *position == key) {
            return;
        }

        leaf->keys.insert(position, key);
        if (leaf->keys.size() > static_cast<size_t>(2 * degree - 1)) {
            splitLeaf(leaf);
        }
        rebuildKeys(root);
    }

    void remove(int key) {
        Node* leaf = findLeaf(key);
        if (leaf == nullptr) {
            return;
        }

        vector<int>::iterator position =
            lower_bound(leaf->keys.begin(), leaf->keys.end(), key);
        if (position == leaf->keys.end() || *position != key) {
            return;
        }
        leaf->keys.erase(position);

        if (leaf == root) {
            if (leaf->keys.empty()) {
                delete root;
                root = nullptr;
            }
        } else if (leaf->keys.size() < static_cast<size_t>(degree)) {
            rebalanceLeaf(leaf);
        }

        if (root != nullptr) {
            rebuildKeys(root);
        }
    }

    void printLeaves() const {
        if (root == nullptr) {
            cout << "(empty)\n";
            return;
        }

        Node* leaf = root;
        while (!leaf->leaf) {
            leaf = leaf->children.front();
        }
        while (leaf != nullptr) {
            for (int key : leaf->keys) {
                cout << key << ' ';
            }
            leaf = leaf->next;
        }
        cout << '\n';
    }

private:
    Node* root;
    int degree;

    Node* findLeaf(int key) const {
        Node* node = root;
        while (node != nullptr && !node->leaf) {
            size_t index = 0;
            while (index < node->keys.size() && key >= node->keys[index]) {
                ++index;
            }
            node = node->children[index];
        }
        return node;
    }

    static int firstKey(const Node* node) {
        while (!node->leaf) {
            node = node->children.front();
        }
        return node->keys.front();
    }

    static void rebuildKeys(Node* node) {
        if (node->leaf) {
            return;
        }

        for (Node* child : node->children) {
            rebuildKeys(child);
        }
        node->keys.clear();
        for (size_t i = 1; i < node->children.size(); ++i) {
            node->keys.push_back(firstKey(node->children[i]));
        }
    }

    void addRightSibling(Node* node, Node* right) {
        Node* parent = node->parent;
        if (parent == nullptr) {
            root = new Node(false);
            root->children.push_back(node);
            root->children.push_back(right);
            node->parent = root;
            right->parent = root;
            return;
        }

        vector<Node*>::iterator position =
            find(parent->children.begin(), parent->children.end(), node);
        size_t index = static_cast<size_t>(position - parent->children.begin());
        parent->children.insert(parent->children.begin() + index + 1, right);
        right->parent = parent;

        if (parent->children.size() > static_cast<size_t>(2 * degree)) {
            splitInternal(parent);
        }
    }

    void splitLeaf(Node* leaf) {
        Node* right = new Node(true);
        right->keys.assign(leaf->keys.begin() + degree, leaf->keys.end());
        leaf->keys.resize(degree);

        right->next = leaf->next;
        right->prev = leaf;
        if (right->next != nullptr) {
            right->next->prev = right;
        }
        leaf->next = right;

        addRightSibling(leaf, right);
    }

    void splitInternal(Node* node) {
        Node* right = new Node(false);
        right->children.assign(
            node->children.begin() + degree, node->children.end());
        node->children.resize(degree);

        for (Node* child : right->children) {
            child->parent = right;
        }
        addRightSibling(node, right);
    }

    static size_t childIndex(const Node* parent, const Node* child) {
        vector<Node*>::const_iterator position =
            find(parent->children.begin(), parent->children.end(), child);
        return static_cast<size_t>(position - parent->children.begin());
    }

    void rebalanceLeaf(Node* leaf) {
        Node* parent = leaf->parent;
        size_t index = childIndex(parent, leaf);
        Node* left = index > 0 ? parent->children[index - 1] : nullptr;
        Node* right = index + 1 < parent->children.size()
                          ? parent->children[index + 1]
                          : nullptr;

        if (left != nullptr && left->keys.size() > static_cast<size_t>(degree)) {
            leaf->keys.insert(leaf->keys.begin(), left->keys.back());
            left->keys.pop_back();
        } else if (right != nullptr &&
                   right->keys.size() > static_cast<size_t>(degree)) {
            leaf->keys.push_back(right->keys.front());
            right->keys.erase(right->keys.begin());
        } else if (left != nullptr) {
            left->keys.insert(left->keys.end(), leaf->keys.begin(), leaf->keys.end());
            left->next = leaf->next;
            if (leaf->next != nullptr) {
                leaf->next->prev = left;
            }
            parent->children.erase(parent->children.begin() + index);
            leaf->parent = nullptr;
            delete leaf;
            rebalanceInternal(parent);
        } else {
            leaf->keys.insert(leaf->keys.end(), right->keys.begin(), right->keys.end());
            leaf->next = right->next;
            if (right->next != nullptr) {
                right->next->prev = leaf;
            }
            parent->children.erase(parent->children.begin() + index + 1);
            right->parent = nullptr;
            delete right;
            rebalanceInternal(parent);
        }
    }

    void rebalanceInternal(Node* node) {
        if (node == root) {
            if (node->children.size() == 1) {
                root = node->children.front();
                root->parent = nullptr;
                node->children.clear();
                delete node;
            }
            return;
        }
        if (node->children.size() >= static_cast<size_t>(degree)) {
            return;
        }

        Node* parent = node->parent;
        size_t index = childIndex(parent, node);
        Node* left = index > 0 ? parent->children[index - 1] : nullptr;
        Node* right = index + 1 < parent->children.size()
                          ? parent->children[index + 1]
                          : nullptr;

        if (left != nullptr &&
            left->children.size() > static_cast<size_t>(degree)) {
            Node* child = left->children.back();
            left->children.pop_back();
            node->children.insert(node->children.begin(), child);
            child->parent = node;
        } else if (right != nullptr &&
                   right->children.size() > static_cast<size_t>(degree)) {
            Node* child = right->children.front();
            right->children.erase(right->children.begin());
            node->children.push_back(child);
            child->parent = node;
        } else if (left != nullptr) {
            left->children.insert(
                left->children.end(), node->children.begin(), node->children.end());
            for (Node* child : node->children) {
                child->parent = left;
            }
            node->children.clear();
            parent->children.erase(parent->children.begin() + index);
            node->parent = nullptr;
            delete node;
            rebalanceInternal(parent);
        } else {
            node->children.insert(
                node->children.end(), right->children.begin(), right->children.end());
            for (Node* child : right->children) {
                child->parent = node;
            }
            right->children.clear();
            parent->children.erase(parent->children.begin() + index + 1);
            right->parent = nullptr;
            delete right;
            rebalanceInternal(parent);
        }
    }
};

int main() {
    BPlusTree tree(2);

    for (int key : {10, 20, 5, 6, 12, 30, 7, 17}) {
        tree.insert(key);
    }
    cout << "插入后: ";
    tree.printLeaves();

    tree.remove(6);
    tree.remove(20);
    cout << "删除 6 和 20 后: ";
    tree.printLeaves();
    cout << "查找 12: " << (tree.search(12) ? "存在" : "不存在") << '\n';
}
