#include "bithrtree.h"
#include <iostream>

using std::cin;
using std::cout;
using std::endl;

void biThrTree::createThrTree(biTreNode **node)
{
    cout << "请输入结点值:" << endl;
    ELEMTYPE ch;
    cin >> ch;
    if(ch)//如果输入合法
    {
        if(0 == ch)
        {
            //输入1，就令其为叶子结点
            node = nullptr;
        }else//其他合法输入，就创建结点空间
        {
            (*node) = new biTreNode;
            (*node)->data = ch;
            (*node)->lTag = Link;
            (*node)->rTag = Link;

            //遍历左子树
            createThrTree(&(*node)->lchild);
            //遍历右子树
            createThrTree(&(*node)->rchild);
        }
    }
}
void biThrTree::inOrderThreading(biTreNode **p,biTreNode *T)
{
    (*p) = new biTreNode;//头指针，始终指向*node之前
    if(*p)//thrt分配的空间不空
    {
        (*p)->lTag = Link;//左标志为指针，指向左孩子
        (*p)->rTag = thread;//右标志为线索，指向自己
        (*p)->rchild = (*p);
    }
    if(!T)//如果二叉树空，头指针的左孩子就指向自己
    {
       (*p)->lchild = (*p);
    }
    else{//二叉树不空，递归线索化
        (*p)->lchild = T;
        pre = (*p);

        //线索化
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
        //输出结点值
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
