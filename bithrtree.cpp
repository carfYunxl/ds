/*----------------------------------------------------------------------------------------------------------------------------------
 * �����������㷨˼�룺
 * 1.ʹ�������������������������
 *   1.1 ���������Ч���������ռ�
 *   1.2 Ϊ���������ֵ����Ϊ�����ұ�־��ʼ����Ĭ�Ͼ�Ϊָ��:Link,��������������ʱ�޸�
 *   1.3 �ݹ鴴��������
 *   1.4 �ݹ鴴��������
 * 2.ʹ�������������������������
 *   2.1 �����µ�ͷ�ڵ�ռ�p���������־Ϊָ��Link���ұ�־Ϊ����Thread����ʹ�ұ�־��ָ
 *   2.2 �ж�����������T�Ƿ�Ϊ�գ���Ϊ�գ�ͷ�ڵ�p���־��Ϊ����Thread,����ָ���ָ
 *   2.3 ������������T���գ�ͷ�ڵ�p��ָ��ָ��T����ʹ��preΪT��ǰһ����㣬��pre = p;
 *   2.4 ������������T����������������Inthreading(T);
 *   2.5 ������������********************
 * 3.����������������
 *   3.1 ������������T����
 *   3.2 �ݹ���������ֱ�����������һ��Ҷ�ӽ��
 *   3.3 ����ý������Ϊ�գ������־Ϊ����Thread����ָ��ǰһ�����pre��
 *   3.4 ���ǰһ�����pre�Һ���Ϊ�գ����ұ�־����ΪThread����ָ��p********************
 * -------------------------------------------------------------------------------------------------------------------------------*/
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
