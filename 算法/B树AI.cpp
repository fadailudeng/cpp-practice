#include <iostream>
#include <stdexcept>
#include <vector>

using namespace std;

class BTreeNode {
public:
    bool leaf;
    vector<int> keys;
    vector<BTreeNode*> children;

    explicit BTreeNode(bool isLeaf) : leaf(isLeaf) {}

    ~BTreeNode() {
        for (BTreeNode* child : children) {
            delete child;
        }
    }

    BTreeNode* search(int key) {
        size_t i = 0;
        while (i < keys.size() && key > keys[i]) {
            ++i;
        }

        if (i < keys.size() && keys[i] == key) {
            return this;
        }
        return leaf ? nullptr : children[i]->search(key);
    }

    void traverse() const {
        size_t i = 0;
        for (; i < keys.size(); ++i) {
            if (!leaf) {
                children[i]->traverse();
            }
            cout << keys[i] << ' ';
        }
        if (!leaf) {
            children[i]->traverse();
        }
    }

    void insertNonFull(int key, int degree) {
        int i = static_cast<int>(keys.size()) - 1;
        if (leaf) {
            while (i >= 0 && keys[i] > key) {
                --i;
            }
            keys.insert(keys.begin() + i + 1, key);
            return;
        }

        while (i >= 0 && keys[i] > key) {
            --i;
        }
        ++i;

        if (children[i]->keys.size() == static_cast<size_t>(2 * degree - 1)) {
            splitChild(i, degree);
            if (keys[i] < key) {
                ++i;
            }
        }
        children[i]->insertNonFull(key, degree);
    }

    void splitChild(int index, int degree) {
        BTreeNode* fullChild = children[index];
        BTreeNode* newChild = new BTreeNode(fullChild->leaf);
        const int median = fullChild->keys[degree - 1];

        newChild->keys.assign(fullChild->keys.begin() + degree, fullChild->keys.end());
        fullChild->keys.resize(degree - 1);

        if (!fullChild->leaf) {
            newChild->children.assign(
                fullChild->children.begin() + degree, fullChild->children.end());
            fullChild->children.resize(degree);
        }

        children.insert(children.begin() + index + 1, newChild);
        keys.insert(keys.begin() + index, median);
    }

    void remove(int key, int degree) {
        size_t index = 0;
        while (index < keys.size() && keys[index] < key) {
            ++index;
        }

        if (index < keys.size() && keys[index] == key) {
            if (leaf) {
                keys.erase(keys.begin() + index);
            } else {
                removeFromNonLeaf(index, degree);
            }
            return;
        }

        if (leaf) {
            return;
        }

        const bool wasLastChild = (index == keys.size());
        if (children[index]->keys.size() < static_cast<size_t>(degree)) {
            fill(index, degree);
        }

        if (wasLastChild && index > keys.size()) {
            children[index - 1]->remove(key, degree);
        } else {
            children[index]->remove(key, degree);
        }
    }

private:
    int getPredecessor(size_t index) const {
        const BTreeNode* current = children[index];
        while (!current->leaf) {
            current = current->children.back();
        }
        return current->keys.back();
    }

    int getSuccessor(size_t index) const {
        const BTreeNode* current = children[index + 1];
        while (!current->leaf) {
            current = current->children.front();
        }
        return current->keys.front();
    }

    void removeFromNonLeaf(size_t index, int degree) {
        const int key = keys[index];

        if (children[index]->keys.size() >= static_cast<size_t>(degree)) {
            const int predecessor = getPredecessor(index);
            keys[index] = predecessor;
            children[index]->remove(predecessor, degree);
        } else if (children[index + 1]->keys.size() >= static_cast<size_t>(degree)) {
            const int successor = getSuccessor(index);
            keys[index] = successor;
            children[index + 1]->remove(successor, degree);
        } else {
            merge(index);
            children[index]->remove(key, degree);
        }
    }

    void fill(size_t index, int degree) {
        if (index > 0 &&
            children[index - 1]->keys.size() >= static_cast<size_t>(degree)) {
            borrowFromPrevious(index);
        } else if (index < keys.size() &&
                   children[index + 1]->keys.size() >= static_cast<size_t>(degree)) {
            borrowFromNext(index);
        } else if (index < keys.size()) {
            merge(index);
        } else {
            merge(index - 1);
        }
    }

    void borrowFromPrevious(size_t index) {
        BTreeNode* child = children[index];
        BTreeNode* sibling = children[index - 1];

        child->keys.insert(child->keys.begin(), keys[index - 1]);
        if (!child->leaf) {
            child->children.insert(child->children.begin(), sibling->children.back());
            sibling->children.pop_back();
        }
        keys[index - 1] = sibling->keys.back();
        sibling->keys.pop_back();
    }

    void borrowFromNext(size_t index) {
        BTreeNode* child = children[index];
        BTreeNode* sibling = children[index + 1];

        child->keys.push_back(keys[index]);
        if (!child->leaf) {
            child->children.push_back(sibling->children.front());
            sibling->children.erase(sibling->children.begin());
        }
        keys[index] = sibling->keys.front();
        sibling->keys.erase(sibling->keys.begin());
    }

    void merge(size_t index) {
        BTreeNode* child = children[index];
        BTreeNode* sibling = children[index + 1];

        child->keys.push_back(keys[index]);
        child->keys.insert(child->keys.end(), sibling->keys.begin(), sibling->keys.end());
        if (!child->leaf) {
            child->children.insert(
                child->children.end(), sibling->children.begin(), sibling->children.end());
            sibling->children.clear();
        }

        keys.erase(keys.begin() + index);
        children.erase(children.begin() + index + 1);
        sibling->children.clear();
        delete sibling;
    }
};

class BTree {
public:
    explicit BTree(int minimumDegree) : root(nullptr), degree(minimumDegree) {
        if (degree < 2) {
            throw invalid_argument("B-tree minimum degree must be at least 2");
        }
    }

    ~BTree() {
        delete root;
    }

    BTree(const BTree&) = delete;
    BTree& operator=(const BTree&) = delete;

    bool search(int key) const {
        return root != nullptr && root->search(key) != nullptr;
    }

    void traverse() const {
        if (root != nullptr) {
            root->traverse();
        }
        cout << '\n';
    }

    void insert(int key) {
        if (search(key)) {
            return;
        }

        if (root == nullptr) {
            root = new BTreeNode(true);
            root->keys.push_back(key);
            return;
        }

        if (root->keys.size() == static_cast<size_t>(2 * degree - 1)) {
            BTreeNode* newRoot = new BTreeNode(false);
            newRoot->children.push_back(root);
            newRoot->splitChild(0, degree);
            root = newRoot;
        }
        root->insertNonFull(key, degree);
    }

    void remove(int key) {
        if (root == nullptr) {
            return;
        }

        root->remove(key, degree);
        if (root->keys.empty()) {
            BTreeNode* oldRoot = root;
            if (root->leaf) {
                root = nullptr;
            } else {
                root = root->children[0];
                oldRoot->children[0] = nullptr;
            }
            delete oldRoot;
        }
    }

private:
    BTreeNode* root;
    int degree;
};

int main() {
    BTree tree(3);  // 最小度数为 3，每个节点最多有 5 个关键字

    for (int key : {10, 20, 5, 6, 12, 30, 7, 17}) {
        tree.insert(key);
    }

    cout << "插入后（中序遍历）: ";
    tree.traverse();

    tree.remove(6);
    tree.remove(13);  // 删除不存在的关键字不会改变树

    cout << "删除 6 后: ";
    tree.traverse();
    cout << "查找 12: " << (tree.search(12) ? "存在" : "不存在") << '\n';

    return 0;
}
