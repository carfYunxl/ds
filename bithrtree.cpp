#include "bithrtree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void biThrTree::createThrTree(biTreNode **node)
{
    cout << "��������ֵ:" << endl;
    ELEMTYPE ch;
    cin >> ch;
    if(ch)//�������Ϸ�
    {
        if(0 == ch)
        {
            //����1��������ΪҶ�ӽ��
            node = nullptr;
        }else//�����Ϸ����룬�ʹ������ռ�
        {
            (*node) = new biTreNode;
            (*node)->data = ch;
            (*node)->lTag = Link;
            (*node)->rTag = Link;

            //����������
            createThrTree(&(*node)->lchild);
            //����������
            createThrTree(&(*node)->rchild);
        }
    }
}
void biThrTree::inOrderThreading(biTreNode **p,biTreNode *T)
{
    (*p) = new biTreNode;//ͷָ�룬ʼ��ָ��*node֮ǰ
    if(*p)//thrt����Ŀռ䲻��
    {
        (*p)->lTag = Link;//���־Ϊָ�룬ָ������
        (*p)->rTag = thread;//�ұ�־Ϊ������ָ���Լ�
        (*p)->rchild = (*p);
    }
    if(!T)//����������գ�ͷָ������Ӿ�ָ���Լ�
    {
       (*p)->lchild = (*p);
    }
    else{//���������գ��ݹ�������
        (*p)->lchild = T;
        pre = (*p);

        //������
        inThreading(T);
        pre->rchild = (*p);
        pre->rTag = thread;
        (*p)->rchild = pre;
    }
}
void biThrTree::inThreading(biTreNode *T)
{
    if(T)
    {
        inThreading(T->lchild);
        //������ֵ
        cout << T->data << endl;
        if(!T->lchild)
        {
            T->lTag = thread;
            T->lchild = pre;
        }
        if(!pre->rchild)
        {
            pre->rTag = thread;
            pre->rchild = T;
        }
        pre = T;
        inThreading(T->rchild);
    }
}
