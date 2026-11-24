#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct treeNode{
    int val;
    int height;
    int balanceFactor;
    treeNode *left;
    treeNode *right;
    treeNode(int x):val(x),height(1),balanceFactor(0),left(nullptr),right(nullptr){}
};
//打印
void Print(treeNode *node)
{
    if(node==nullptr)
    {
        return;
    }
    Print(node->left);
    cout<<node->val<<" ";
    Print(node->right);
}
int getHeight(treeNode *node)
{
    return node==nullptr ? 0 : node->height;//从下往上依次更新高度
}

void updateHeight(treeNode *node)
{
    node->height=1+max(getHeight(node->left),getHeight(node->right));//更新节点高度，看看左右子树的高度，取最大值加1
}
// 平衡因子定义为左子树高度减去右子树高度
void getBalanceFactor(treeNode *node)
{
    if(node==nullptr)
    {
        return;
    }
    node->balanceFactor=getHeight(node->left)-getHeight(node->right);

}
//调整
treeNode *Rotate(treeNode *node)
{
    if(node->balanceFactor==2)
    {
        if(node->left->balanceFactor>=0)//LL
        {
            treeNode *A=node,*B=node->left;
            A->left=B->right;
            B->right=A;
            updateHeight(A);
            getBalanceFactor(A);
            updateHeight(B);
            getBalanceFactor(B);
            node=B;
            return node;
        }
        
        else if(node->left->balanceFactor<=0)//LR
        {
            treeNode *A=node, *B=node->left, *C=node->left->right;
            B->right=C->left;
            C->left=B;
            A->left=C->right;
            C->right=A;
            updateHeight(A);
            getBalanceFactor(A);
            updateHeight(B);
            getBalanceFactor(B);
            updateHeight(C);
            getBalanceFactor(C);
            node=C;
            return node;
        }
    }
    else if(node->balanceFactor==-2)//node->balanceFactor==-2,node->right->balanceFactor==1 RL
    {
        if(node->right->balanceFactor<=0)//RR
        {
            treeNode *A=node,*B=node->right;
            A->right=B->left;
            B->left=A;
            updateHeight(A);
            getBalanceFactor(A);
            updateHeight(B);
            getBalanceFactor(B);
            node=B;
            return node;
        }
        else if(node->right->balanceFactor>=0)//RL
        {
        treeNode *A=node,*B=node->right,*C=B->left;
        B->left=C->right;
        C->right=B;
        A->right=C->left;
        C->left=A;
        updateHeight(A);
        getBalanceFactor(A);
        updateHeight(B);    
        getBalanceFactor(B);
        updateHeight(C);
        getBalanceFactor(C);
        node=C;
        return node;
        }
    }
  
}
//创建AVL树
treeNode *create(vector<int> &nums)
{
    int i=0;
    treeNode *root=nullptr;
    for(i;i<nums.size();i++)
    {
        vector<treeNode*> path;
        if(root==nullptr)
        {
            root=new treeNode(nums[i]);
        }
        else
        {
            path.push_back(root);
            treeNode *cur=root;
            
            while(true)
            {
                if(nums[i]<cur->val)
                {
                    if(cur->left==nullptr)
                    {
                        cur->left=new treeNode(nums[i]);
                        path.push_back(cur->left);
                        break;
                    }
                    else
                    {
                        cur=cur->left;
                        path.push_back(cur);
                    }
                }
                else
                {
                    if(cur->right==nullptr)
                    {
                        cur->right=new treeNode(nums[i]);
                        path.push_back(cur->right);
                        break;
                    }
                    else
                    {
                        cur=cur->right;
                        path.push_back(cur);
                    }
                }
            }
            for(int i=static_cast<int>(path.size())-1;i>=0;i--)
            {
                updateHeight(path[i]);
                getBalanceFactor(path[i]);
                if(path[i]->balanceFactor>1||path[i]->balanceFactor<-1)
                {
                    treeNode *old = path[i];                    // ★ 先存旧根
                    path[i] = Rotate(path[i]);
                    if (i == 0)
                        root = path[i];              // 根
                    else if (path[i-1]->left  == old) 
                        path[i-1]->left  = path[i];  // 挂左
                    else                              
                        path[i-1]->right = path[i];  // 挂右
                    break;           
                }
            }
        }
    }
    return root;
}
int main()
{
    vector<int> nums={1,3,6,4,9,2,5,7,8};
    treeNode *root=create(nums);
    Print(root);
    return 0;
}