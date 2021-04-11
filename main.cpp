//#include <QCoreApplication>
#include "binarytree.h"
#include <iostream>

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
int main(/**/)
{
    //QCoreApplication a(argc, argv);
    testBinaryTree();
    //return a.exec();
}
