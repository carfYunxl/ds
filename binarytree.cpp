#include "binarytree.h"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

binaryTree::binaryTree()
{
    cout << "���캯������" << endl;
}
binaryTree::~binaryTree()
{
    cout << "������������" << endl;
}
binaryTreeNode::~binaryTreeNode()
{

}
void binaryTree::createBinaryTree(binaryTreeNode **node)
{
    cout << "���������ֵ:" << endl;
    char ch;
    cin >> ch;
    if(ch)
    {
        if(value == ch)
        {
            node = nullptr;
        }
        else{
            (*node) = new binaryTreeNode();//����һ���µ������,�������˳�ʼ��
            (*node)->data = ch;
            createBinaryTree(&(*node)->lchild);//��һ������������
            createBinaryTree(&(*node)->rchild);//��һ������������
        }
    }

}
void binaryTree::preOrderBinaryTree(binaryTreeNode **node,int level)
{
    if((*node) == nullptr)//���ڵ�Ϊ��
    {
        return;
    }else//���ڵ㲻��
    {
        //��ӡ��ǰ�ڵ��Լ�����������Ĳ���
        cout << (*node)->data << "λ�ڵ�" << level << "��" << endl;
        //����������
        preOrderBinaryTree(&(*node)->lchild,level+1);
        depth++;
        //����������
        preOrderBinaryTree(&(*node)->rchild,level+1);
    }
}
void binaryTree::getTreeDepth()
{
    //��������Ǳ���������һ������ȡ��
    cout << "the depth of the tree is: " << this->depth / 2 << endl;
}
