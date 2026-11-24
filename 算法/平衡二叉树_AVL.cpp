#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode{
    int val;
    int height;  // 节点的高度
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x):val(x),height(1),left(nullptr),right(nullptr){}
};

int getHeight(TreeNode *node)
{
    return node==nullptr ? 0 : node->height;//从下往上依次更新高度
}

void updateHeight(TreeNode *node)
{
    node->height=1+max(getHeight(node->left),getHeight(node->right));//更新节点高度，看看左右子树的高度，取最大值加1
}

// 平衡因子定义为左子树高度减去右子树高度
int getBalanceFactor(TreeNode *node)
{
    if(node==nullptr)
    {
        return 0;
    }
    return getHeight(node->left)-getHeight(node->right);
}

TreeNode *create(const vector<int> &nums)
{
    TreeNode *root = nullptr;
    for(int value : nums)
    {
        if(root==nullptr)
        {
            root=new TreeNode(value);
        }
        else{
            TreeNode *cur=root;
            vector<TreeNode*> path;//存储每个节点
            while(true)
            {
                path.push_back(cur);
                if(value<cur->val)
                {
                    if(cur->left==nullptr)
                    {
                        cur->left=new TreeNode(value);
                        break;
                    }
                    else
                    {
                        cur=cur->left;
                    }
                }
                else
                {
                    if(cur->right==nullptr)
                    {
                        cur->right=new TreeNode(value);
                        break;
                    }
                    else
                    {
                        cur=cur->right;
                    }
                }
            }
            // 从新节点的父节点一路向根节点更新高度
            for(int i=static_cast<int>(path.size())-1;i>=0;i--)
            {
                updateHeight(path[i]);
            }
        }
    }
    return root;
}
int main()
{
    
}