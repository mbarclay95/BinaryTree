// ADT Binary Tree Node:
// Spec and implementation file
//    data object: a node for a dynamic binary tree
//    operations: two constructors
// Friend classes: BinaryTree, BinarySearchTree

#include <cstddef>

#ifndef NODE_H
#define NODE_H
typedef int ItemType;
class Node
{
private:

   // creates a node
   // post: the item of the node is empty and the kids are NULL
   // usage: newptr = new cnode();
   Node():mleftptr(NULL),mrightptr(NULL) {};

   // creates a node with a given item and kids
   // post: the item of the node is nodeItem, the kids are left and right
   // usage:aptr = new (nothrow) Node (thisone, NULL, NULL);
   // CAUTION: REQUIRES THAT COPY WORKS IN ItemType!!
   Node (const ItemType& nodeItem,
          Node* left, Node* right):
          mitem (nodeItem), mleftptr (left), mrightptr (right){};

   // implementation of data object
   //ItemType mitem;
   ItemType mitem;
   Node* mleftptr;
   Node* mrightptr;


   friend class BinaryTree;
   friend class BinarySearchTree;
};
#endif
