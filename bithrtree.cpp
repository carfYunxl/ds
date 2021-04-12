/*----------------------------------------------------------------------------------------------------------------------------------
 * 线索二叉树算法思想：
 * 1.使用先序遍历法创建线索二叉树
 *   1.1 如果输入有效，则分配结点空间
 *   1.2 为结点数据域赋值，并为其左右标志初始化，默认均为指针:Link,后续将在线索化时修改
 *   1.3 递归创建左子树
 *   1.4 递归创建右子树
 * 2.使用中序遍历法遍历线索二叉树
 *   2.1 分配新的头节点空间p，令其左标志为指针Link，右标志为线索Thread，并使右标志回指
 *   2.2 判断线索二叉树T是否为空，若为空，头节点p左标志置为线索Thread,其左指针回指
 *   2.3 若线索二叉树T不空，头节点p左指针指向T，并使得pre为T的前一个结点，即pre = p;
 *   2.4 线索化二叉树T，调用线索化函数Inthreading(T);
 *   2.5 线索化结束，********************
 * 3.线索化线索二叉树
 *   3.1 若线索二叉树T不空
 *   3.2 递归线索化，直到到达最左边一个叶子结点
 *   3.3 如果该结点左孩子为空，置左标志为线索Thread，并指向前一个结点pre；
 *   3.4 如果前一个结点pre右孩子为空，置右标志线索为Thread，并指向p********************
 * -------------------------------------------------------------------------------------------------------------------------------*/
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
