//#include <QCoreApplication>
#include "binarytree.h"
#include <iostream>
#include "bithrtree.h"
using std::cin;
using std::cout;
using std::endl;


void testBinaryTree()
{
    int level = 1;
    binaryTree s;
    binaryTreeNode *node = nullptr;
    s.createBinaryTree(&node);
    s.preOrderBinaryTree(&node,level);
    s.getTreeDepth();
}
void testbiThrTree()
{
    biThrTree s;
    biTreNode *T = nullptr;
    biTreNode *p = nullptr;
    s.createThrTree( &T );
    s.inOrderThreading(&p,T);
}
int main(/*int argc, char *argv[]*/)
{
    //QCoreApplication a(argc, argv);
    //testBinaryTree();
    testbiThrTree();
    //return a.exec();
}
