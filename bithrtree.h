#ifndef BITHRTREE_H
#define BITHRTREE_H
typedef int ELEMTYPE;
typedef enum{Link,thread} PointerTag;
class biTreNode
{
public:
    //构造函数
    biTreNode(){
        lchild = nullptr;
        rchild = nullptr;
    }
    //析构函数
    ~biTreNode(){

    }
    ELEMTYPE data;
    biTreNode *lchild;
    biTreNode *rchild;
    PointerTag lTag;
    PointerTag rTag;
};
class biThrTree
{
public:
    biThrTree()
    {
        pre = nullptr;
    }
    ~biThrTree()
    {

    }

    //先序遍历创建线索二叉树
    void createThrTree(biTreNode **node);
    //中序遍历线索化二叉树
    void inOrderThreading(biTreNode **p,biTreNode *T);
    //线索化
    void inThreading(biTreNode *T);
private:
    biTreNode *pre;
};

#endif // BITHRTREE_H
