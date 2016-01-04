#include "node.h"
#include "binaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree(): mroot(NULL) {}

BinaryTree::BinaryTree(const ItemType& rootItem)
{
    mroot = new Node(rootItem, NULL, NULL);
}

BinaryTree::BinaryTree(const ItemType& rootItem,BinaryTree& leftTree, BinaryTree& rightTree)
{
    mroot = new Node(rootItem, leftTree.mroot, rightTree.mroot);
}

BinaryTree::BinaryTree(const BinaryTree& rhstree)
{
    copyTree(mroot, rhstree.mroot);
}

void BinaryTree::copyTree(Node*& newtreep, Node* oldtreep)
{
    newtreep = new Node(oldtreep -> mitem, NULL, NULL);
    if(oldtreep -> mleftptr != NULL)
        copyTree(newtreep -> mleftptr, oldtreep -> mleftptr);
    if(oldtreep -> mrightptr != NULL)
        copyTree(newtreep -> mrightptr, oldtreep -> mrightptr);
    else
        return;
}

void BinaryTree::destroyTree(Node*& treep)
{
    if(treep -> mleftptr == NULL &&
       treep -> mrightptr == NULL)
    {
        delete treep;
        treep = NULL;
        return;
    }
    if(treep -> mleftptr != NULL)
        destroyTree(treep -> mleftptr);
    if(treep -> mrightptr != NULL)
        destroyTree(treep -> mrightptr);
    delete treep;
    treep = NULL;
}

BinaryTree::~BinaryTree()
{
    destroyTree(mroot);
}

bool BinaryTree::isLeaf(Node* treeptr) const
{
    if(treeptr -> mleftptr == NULL &&
       treeptr -> mrightptr ==NULL)
        return true;
    return false;
}

bool BinaryTree::isEmpty() const
{
    return mroot == NULL;
}

void BinaryTree::preorderTraverse() const
{
    cout << mroot -> mitem << endl;
    preorder(mroot -> mleftptr);
    preorder(mroot -> mrightptr);
}

void BinaryTree::preorder(Node* treep) const
{
    if(treep == NULL)
        return;
    cout << treep -> mitem << endl;
    preorder(treep -> mleftptr);
    preorder(treep -> mrightptr);
}

void BinaryTree::inorderTraverse() const
{
    inorder(mroot -> mleftptr);
    cout << mroot -> mitem << endl;
    inorder(mroot -> mrightptr);
}

void BinaryTree::inorder(Node* treep) const
{
    if(treep == NULL)
        return;
    inorder(treep -> mleftptr);
    cout << treep -> mitem << endl;
    inorder(treep -> mrightptr);
}

void BinaryTree::postorderTraverse() const
{
    postorder(mroot -> mleftptr);
    postorder(mroot -> mrightptr);
    cout << mroot -> mitem << endl;
}

void BinaryTree::postorder(Node* treep) const
{
    if(treep == NULL)
        return;
    postorder(treep -> mleftptr);
    postorder(treep -> mrightptr);
    cout << treep -> mitem << endl;
}

