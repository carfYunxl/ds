#include "binarytree.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

binaryTree::binaryTree()
{
    cout << "构造函数调用" << endl;
}
binaryTree::~binaryTree()
{
    cout << "析构函数调用" << endl;
}
binaryTreeNode::~binaryTreeNode()
{

}
void binaryTree::createBinaryTree(binaryTreeNode **node)
{
    cout << "请输入结点的值:" << endl;
    char ch;
    cin >> ch;
    if(ch)
    {
        if(value == ch)
        {
            node = nullptr;
        }
        else{
            (*node) = new binaryTreeNode();//创建一个新的树结点,并进行了初始化
            (*node)->data = ch;
            createBinaryTree(&(*node)->lchild);//进一步创建左子树
            createBinaryTree(&(*node)->rchild);//进一步创建右子树
        }
    }

}
void binaryTree::preOrderBinaryTree(binaryTreeNode **node,int level)
{
    if((*node) == nullptr)//根节点为空
    {
        return;
    }else//根节点不空
    {
        //打印当前节点以及所造二叉树的层数
        cout << (*node)->data << "位于第" << level << "层" << endl;
        //遍历左子树
        preOrderBinaryTree(&(*node)->lchild,level+1);
        depth++;
        //遍历右子树
        preOrderBinaryTree(&(*node)->rchild,level+1);
    }
}
void binaryTree::getTreeDepth()
{
    //树的深度是遍历次数的一半向下取整
    cout << "the depth of the tree is: " << this->depth / 2 << endl;
}
