#ifndef BITHRTREE_H
#define BITHRTREE_H
typedef int ELEMTYPE;
typedef enum{Link,thread} PointerTag;
class biTreNode
{
public:
    //���캯��
    biTreNode(){
        lchild = nullptr;
        rchild = nullptr;
    }
    //��������
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

    //���������������������
    void createThrTree(biTreNode **node);
    //�������������������
    void inOrderThreading(biTreNode **p,biTreNode *T);
    //������
    void inThreading(biTreNode *T);
private:
    biTreNode *pre;
};

#endif // BITHRTREE_H
