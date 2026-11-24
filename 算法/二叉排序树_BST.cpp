#include <iostream>
#include <vector>
using namespace std;

struct TreeNode{
    int val;          // 节点保存的值
    TreeNode *left;   // 指向左子节点
    TreeNode *right;  // 指向右子节点
    // 创建节点时初始化数值，并将左右子节点设为空
    TreeNode(int x):val(x),left(nullptr),right(nullptr){}
};
// 根据数组中的数据创建二叉排序树
TreeNode *create(vector<int> &nums)
{
   TreeNode *root = nullptr;
   for(int i=0;i<nums.size();i++)
   {
     if(root==nullptr)
     {
        root = new TreeNode(nums[i]);  // 第一个数作为根节点
     }
     else
     {
        TreeNode*cur = root;
        while(true)
        {
            // 比当前节点小，往左子树寻找空位置
            if(nums[i]<cur->val)
            {
                if(cur->left==nullptr)
                {
                    cur->left = new TreeNode(nums[i]);
                    break;
                }
                else
                {
                    cur = cur->left;
                }
            }
            else
            {
                // 大于或等于当前节点，往右子树寻找空位置
                if(cur->right==nullptr)
                {
                    cur->right = new TreeNode(nums[i]);
                    break;
                }
                else
                {
                    cur = cur->right;
                }
            }
        }
     }
   }
   return root;
}
// 查找指定值，找到时返回对应节点，找不到时返回空指针
TreeNode *Find(TreeNode *root, int val)
{
    TreeNode *cur=root;
    while(cur!=nullptr)
    {
        if(cur->val==val)
        {
            return cur;
        }
        else if(val<cur->val)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }
    return nullptr;
}
// 向已有的二叉排序树中插入新值；重复值不插入
TreeNode *Insert(TreeNode *root, int val)
{
    if(root==nullptr)
    {
        return new TreeNode(val);  // 空树时，新节点成为根节点
    }
    TreeNode *cur=root;
    while(true)
    {
        if(cur->val==val)
        {
            return root;
        }
        else if(val<cur->val)
        {
            // 找到左侧空位后插入，否则继续向左查找
            if(cur->left==nullptr)
            {
                cur->left=new TreeNode(val);
                break;
            }
            else
            {
                cur=cur->left;
            }
        }
        else
        {
            // 找到右侧空位后插入，否则继续向右查找
            if(cur->right==nullptr)
            {
                cur->right=new TreeNode(val);
                break;
            }
            else
            {
                cur=cur->right;
            }
        }
    }
    return root;
}
// 删除指定值的节点，并返回删除后的树根
TreeNode *Delete(TreeNode *root,int val)
{
    TreeNode *parent=nullptr;
    TreeNode *cur=root;

    // 从根节点开始查找目标节点，同时记录它的父节点
    while(cur!=nullptr && cur->val!=val)
    {
        parent=cur;
        if(val<cur->val)
        {
            cur=cur->left;
        }
        else
        {
            cur=cur->right;
        }
    }

    if(cur==nullptr)
    {
        return root;  // 没找到目标值，树保持不变
    }

    // 若目标节点有两个孩子，用右子树中最小的节点（中序后继）替换它
    if(cur->left!=nullptr && cur->right!=nullptr)
    {
        TreeNode *successorParent=cur;
        TreeNode *successor=cur->right;
        // 后继节点是右子树中最靠左的节点
        while(successor->left!=nullptr)
        {
            successorParent=successor;
            successor=successor->left;
        }

        cur->val=successor->val;
        parent=successorParent;
        cur=successor;
    }

    // 此时待删除节点最多只有一个孩子，让这个孩子接替它的位置
    TreeNode *child=(cur->left!=nullptr) ? cur->left : cur->right;
    if(parent==nullptr)
    {
        root=child;  // 删除的是根节点，更新根指针
    }
    else if(parent->left==cur)
    {
        parent->left=child;
    }
    else
    {
        parent->right=child;
    }

    delete cur;  // 释放被删除节点占用的内存
    return root;
}
// 中序遍历二叉排序树，按升序输出所有节点的值
TreeNode *Print(TreeNode *root)
{
    if(root==nullptr)
    {
        return nullptr;
    }
    if(root->left!=nullptr)
    {
        root->left=Print(root->left);
    }
    cout<<root->val<<" ";
    if(root->right!=nullptr)
    {
        root->right=Print(root->right);
    }
    return root;
}
int main()
{
    vector<int> nums = {5, 3, 7, 2, 4, 6, 8};
    TreeNode *root = create(nums);
    Print(root);

}