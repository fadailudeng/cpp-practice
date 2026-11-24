#include <iostream>
#include <vector>
using namespace std;

enum Color { RED, BLACK };

struct RBNode {
    int key;
    Color color;
    RBNode* left;
    RBNode* right;
    RBNode* parent;

    RBNode(int value, Color c = RED, RBNode* p = nullptr)
        : key(value), color(c), left(nullptr), right(nullptr), parent(p) {}
};

class RBTree {
private:
    RBNode* root;

    RBNode* grandparent(RBNode* node) const {
        if (node && node->parent) return node->parent->parent;
        return nullptr;
    }

    RBNode* uncle(RBNode* node) const {
        RBNode* g = grandparent(node);
        if (!g) return nullptr;
        return (node->parent == g->left) ? g->right : g->left;
    }

    RBNode* findNode(int key) const {
        RBNode* current = root;
        while (current && current->key != key) {
            current = key < current->key ? current->left : current->right;
        }
        return current;
    }

    RBNode* minimum(RBNode* node) const {
        while (node->left) node = node->left;
        return node;
    }

    Color colorOf(RBNode* node) const {
        return node ? node->color : BLACK;
    }

    void setColor(RBNode* node, Color color) {
        if (node) node->color = color;
    }

    void transplant(RBNode* oldNode, RBNode* newNode) {
        if (!oldNode->parent) root = newNode;
        else if (oldNode == oldNode->parent->left) oldNode->parent->left = newNode;
        else oldNode->parent->right = newNode;
        if (newNode) newNode->parent = oldNode->parent;
    }

    void rotateLeft(RBNode* x) {
        RBNode* y = x->right;
        if (!y) return;

        x->right = y->left;
        if (y->left) y->left->parent = x;

        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->left = x;
        x->parent = y;
    }

    void rotateRight(RBNode* x) {
        RBNode* y = x->left;
        if (!y) return;

        x->left = y->right;
        if (y->right) y->right->parent = x;

        y->parent = x->parent;
        if (!x->parent) root = y;
        else if (x == x->parent->left) x->parent->left = y;
        else x->parent->right = y;

        y->right = x;
        x->parent = y;
    }

    void fixViolation(RBNode* z) {
        while (z && z != root && z->parent && z->parent->color == RED) {
            RBNode* p = z->parent;
            RBNode* g = grandparent(z);

            if (!g) break;

            if (p == g->left) {
                RBNode* u = g->right;
                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->right) {
                        rotateLeft(p);
                        z = p;
                        p = z->parent;
                    }
                    p->color = BLACK;
                    g->color = RED;
                    rotateRight(g);
                }
            } else {
                RBNode* u = g->left;
                if (u && u->color == RED) {
                    p->color = BLACK;
                    u->color = BLACK;
                    g->color = RED;
                    z = g;
                } else {
                    if (z == p->left) {
                        rotateRight(p);
                        z = p;
                        p = z->parent;
                    }
                    p->color = BLACK;
                    g->color = RED;
                    rotateLeft(g);
                }
            }
        }

        root->color = BLACK;
    }

    void fixDeletion(RBNode* node, RBNode* parent) {
        while (node != root && colorOf(node) == BLACK) {
            if (!parent) break;

            if (node == parent->left) {
                RBNode* sibling = parent->right;
                if (colorOf(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateLeft(parent);
                    sibling = parent->right;
                }

                if (colorOf(sibling ? sibling->left : nullptr) == BLACK &&
                    colorOf(sibling ? sibling->right : nullptr) == BLACK) {
                    setColor(sibling, RED);
                    node = parent;
                    parent = node->parent;
                } else {
                    if (colorOf(sibling ? sibling->right : nullptr) == BLACK) {
                        setColor(sibling ? sibling->left : nullptr, BLACK);
                        setColor(sibling, RED);
                        if (sibling) rotateRight(sibling);
                        sibling = parent->right;
                    }

                    setColor(sibling, parent->color);
                    setColor(parent, BLACK);
                    setColor(sibling ? sibling->right : nullptr, BLACK);
                    rotateLeft(parent);
                    node = root;
                    parent = nullptr;
                }
            } else {
                RBNode* sibling = parent->left;
                if (colorOf(sibling) == RED) {
                    setColor(sibling, BLACK);
                    setColor(parent, RED);
                    rotateRight(parent);
                    sibling = parent->left;
                }

                if (colorOf(sibling ? sibling->right : nullptr) == BLACK &&
                    colorOf(sibling ? sibling->left : nullptr) == BLACK) {
                    setColor(sibling, RED);
                    node = parent;
                    parent = node->parent;
                } else {
                    if (colorOf(sibling ? sibling->left : nullptr) == BLACK) {
                        setColor(sibling ? sibling->right : nullptr, BLACK);
                        setColor(sibling, RED);
                        if (sibling) rotateLeft(sibling);
                        sibling = parent->left;
                    }

                    setColor(sibling, parent->color);
                    setColor(parent, BLACK);
                    setColor(sibling ? sibling->left : nullptr, BLACK);
                    rotateRight(parent);
                    node = root;
                    parent = nullptr;
                }
            }
        }

        setColor(node, BLACK);
    }

    void inorderHelper(RBNode* node) const {
        if (!node) return;
        inorderHelper(node->left);
        cout << node->key << (node->color == RED ? "(R) " : "(B) ");
        inorderHelper(node->right);
    }

    void freeTree(RBNode* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:
    RBTree() : root(nullptr) {}
    ~RBTree() { freeTree(root); }

    void insert(int key) {
        RBNode* z = new RBNode(key, RED, nullptr);
        if (!root) {
            root = z;
            root->color = BLACK;
            return;
        }

        RBNode* parent = nullptr;
        RBNode* current = root;

        while (current) {
            parent = current;
            if (key < current->key) current = current->left;
            else if (key > current->key) current = current->right;
            else {
                delete z;
                return;
            }
        }

        z->parent = parent;
        if (key < parent->key) parent->left = z;
        else parent->right = z;

        fixViolation(z);
    }

    bool remove(int key) {
        RBNode* node = findNode(key);
        if (!node) return false;

        RBNode* movedNode = node;
        Color removedColor = movedNode->color;
        RBNode* replacement = nullptr;
        RBNode* replacementParent = nullptr;

        if (!node->left) {
            replacement = node->right;
            replacementParent = node->parent;
            transplant(node, node->right);
            if (replacement) replacementParent = replacement->parent;
        } else if (!node->right) {
            replacement = node->left;
            replacementParent = node->parent;
            transplant(node, node->left);
            if (replacement) replacementParent = replacement->parent;
        } else {
            movedNode = minimum(node->right);
            removedColor = movedNode->color;
            replacement = movedNode->right;

            if (movedNode->parent == node) {
                replacementParent = movedNode;
                if (replacement) replacement->parent = movedNode;
            } else {
                replacementParent = movedNode->parent;
                transplant(movedNode, movedNode->right);
                movedNode->right = node->right;
                movedNode->right->parent = movedNode;
            }

            transplant(node, movedNode);
            movedNode->left = node->left;
            movedNode->left->parent = movedNode;
            movedNode->color = node->color;
        }

        delete node;
        if (removedColor == BLACK) {
            fixDeletion(replacement, replacement ? replacement->parent : replacementParent);
        }
        return true;
    }

    bool search(int key) const {
        return findNode(key) != nullptr;
    }

    void inorder() const {
        cout << "Inorder traversal: ";
        inorderHelper(root);
        cout << endl;
    }

    void printTree() const {
        cout << "Root = " << (root ? to_string(root->key) : "null") << endl;
        inorder();
    }
};

int main() {
    RBTree tree;
    int nums[] = {10, 18, 7, 15, 16, 30, 25, 40, 60, 2, 1, 70};

    for (int x : nums) {
        tree.insert(x);
    }

    tree.printTree();

    cout << "Search 16: " << (tree.search(16) ? "found" : "not found") << endl;
    cout << "Search 50: " << (tree.search(50) ? "found" : "not found") << endl;
    cout << "Remove 16: " << (tree.remove(16) ? "removed" : "not found") << endl;
    cout << "Search 16: " << (tree.search(16) ? "found" : "not found") << endl;
    tree.printTree();

    return 0;
}