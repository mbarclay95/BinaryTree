#include "node.h"
#include "binaryTree.h"
#include "searchBinaryTree.h"
#include <iostream>
using namespace std;

BinarySearchTree::BinarySearchTree(){}

BinarySearchTree::~BinarySearchTree(){}

bool BinarySearchTree::Search(const ItemType& theItem) const
{
    return lookup(mroot, theItem);
}

bool BinarySearchTree::lookup (Node * treeptr, const ItemType& theItem) const
{
    if(treeptr -> mitem == theItem)
        return true;
    else if(isLeaf(treeptr))
        return false;
    if(treeptr -> mleftptr != NULL)
        if(lookup(treeptr -> mleftptr, theItem))
            return true;
    if(treeptr -> mrightptr != NULL)
            if(lookup(treeptr -> mrightptr, theItem))
                return true;
    else
        return false;
}

void BinarySearchTree::Insert(const ItemType& newItem)
{
    insertItem(mroot, newItem);
}

void BinarySearchTree::insertItem(Node *& treeptr, const ItemType& newItem)
{
    if(isEmpty())
        treeptr = new Node(newItem, NULL, NULL);
    else if(newItem >= treeptr -> mitem)
    {
        if(treeptr -> mrightptr == NULL)
        {
            treeptr -> mrightptr = new Node(newItem, NULL, NULL);
            return;
        }
        insertItem(treeptr -> mrightptr, newItem);
    }
    else
    {
        if(treeptr -> mleftptr == NULL)
        {
            treeptr -> mleftptr = new Node(newItem, NULL, NULL);
            return;
        }
        insertItem(treeptr -> mleftptr, newItem);
    }
}

bool BinarySearchTree::Remove(ItemType& theItem)
{
    removeItem(mroot, theItem);
}

bool BinarySearchTree::removeItem(Node *& treeptr, const ItemType& newItem)
{
    if(treeptr == NULL)
    {
        return false;
    }
    if(newItem < treeptr -> mitem)
        removeItem(treeptr -> mleftptr, newItem);
    else if(newItem > treeptr -> mitem)
        removeItem(treeptr -> mrightptr, newItem);
    else
    {
        if(isLeaf(treeptr))
        {
            delete treeptr;
            treeptr = NULL;
        }
        else if((treeptr -> mleftptr == NULL ||
                treeptr -> mrightptr == NULL) &&
                !isLeaf(treeptr))
        {
            if(treeptr -> mleftptr != NULL)
                treeptr = new Node(treeptr -> mleftptr -> mitem,
                                    treeptr -> mleftptr -> mleftptr,
                                    treeptr -> mleftptr -> mrightptr);
            else
                treeptr = new Node(treeptr -> mrightptr -> mitem,
                                    treeptr -> mrightptr -> mleftptr,
                                    treeptr -> mrightptr -> mrightptr);
        }
        else
            treeptr -> mitem = removeHelp(treeptr -> mrightptr);
            //finds the next item in order to replace the treeptr with
    }
    return true;
}

ItemType BinarySearchTree::removeHelp(Node *& treeptr)
{
    if(treeptr -> mleftptr == NULL)
    {
        ItemType x = treeptr -> mitem;
        if(isLeaf(treeptr))
        {
            delete treeptr;
            treeptr = NULL;
        }
        else
        {
            treeptr = new Node(treeptr -> mrightptr -> mitem, NULL,
                                treeptr -> mrightptr -> mrightptr);
        }
        return x;
    }
    return removeHelp(treeptr -> mleftptr);
}
