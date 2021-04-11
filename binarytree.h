/*------------------------------------------------------------------------------------------------------
 * binary definition
 * 1.binaryTreeNode struct
 * 2.binaryTree class
------------------------------------------------------------------------------------------------------*/

#ifndef BINARYTREE_H
#define BINARYTREE_H

class binaryTreeNode
{
public:
    binaryTreeNode(){
        lchild = nullptr;
        rchild = nullptr;
    };
    binaryTreeNode(int d){
        data = d;
        lchild = nullptr;
        rchild = nullptr;
    };
    ~binaryTreeNode();

    char data;//������
    binaryTreeNode *lchild;//����ָ��
    binaryTreeNode *rchild;//�Һ���ָ��
};
class binaryTree
{
public:
    binaryTree();//Ĭ�Ϲ��캯��
    ~binaryTree();//Ĭ����������
    //���ƹ��캯��
    //�ƶ����캯��
    //Ĭ������ת��
    //���������

    //����������
    void createBinaryTree(binaryTreeNode **node);
    //ǰ�����������
    void preOrderBinaryTree(binaryTreeNode **node,int level);
    //�����������
    void getTreeDepth();
private:
    //�����������
    int depth = 0;
    //Ҷ�ӽڵ��־
    char value = '1';
};

#endif // BINARYTREE_H
