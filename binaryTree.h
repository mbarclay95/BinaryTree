// Specification of ADT Binary Tree
//    Data object: A binary tree T that is either empty or in the form
// you finish




//    Operations: (a scaled-down version)
//       create, destroy, copy, operator=,
//       traversals (preorder, inorder, postorder)
// Contract: Assumes the this class can access private data members of class cnode.
//    Those data members are: citem mitem, cnode* mleftptr, cnode* mrightptr.
//    There is a constructor that allows caller to give item, left and right ptrs.

#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"
#include <iostream>
using namespace std;


class BinaryTree
{
public:
   // creates an empty binary tree
   // post: object is an empty binary tree
   // usage: BinaryTree zags;
   BinaryTree();
   BinaryTree(const ItemType& rootItem);
   BinaryTree(const ItemType& rootItem,BinaryTree& leftTree, BinaryTree& rightTree);

   // creates a new binary tree that is a copy of an existing tree
   // post: object is a copy of rhstree
   // usage: BinaryTree zags (bulldog);
   BinaryTree(const BinaryTree& rhstree);


   // releases the memory of a binary tree
   // pre: object exists
   // post: memory for the object has been released. object theoretically does not exist
   //       but in practice, it is empty.
   ~BinaryTree();

   // ******************** member functions ********************************************
   // pre: binary tree object exists
   // **********************************************************************************
   // post: returns true if the object is empty; else returns false
   // usage: if (tree.isEmpty())
   bool isEmpty() const;

   // pre: rhstree is an assigned tree.
   // post: object is a copy of rhstree
   // usage: atree = btree = ctree;
//   BinaryTree& operator=(const BinaryTree& rhstree);

   // *************** on the following traversals
   // uses: operator<< from citem
   // post: prints the objects in the tree in order specified
   // usage: tree.PreorderTraverse();
   // similarly for the other traversals
   // *****************************************************

   void preorderTraverse () const;
   void inorderTraverse () const;
   void postorderTraverse() const;


protected:   // recursive helper functions for coding member functions


    bool isLeaf(Node* treeptr) const;
    // Copies one binary tree to another
    // pre: oldtreep points to the root of a binary tree
    // post: newtreep points to the root of a binary tree
    //  that has copies of the nodes of oldtreep's tree
    // usage: copyTree (newptr, oldptr);
    void copyTree (Node*& newtreep, Node* oldtreep);

    // Releases memory for a binary tree
    // pre: treep points to the root of a binary tree
    // post: releases all of the nodes in the tree pointed to by treep
    //    and leaves treep empty.
    // usage: destroyTree (mroot);
    void destroyTree (Node*& treep);

    // recursive helper for prettyDisplay. You do the doc
//    void writePretty (Node* treep, int level);

    // ********** recursive helpers for the traversals ****************
    // pre: treep points to the root of a binary tree to be traversed
    // post: prints the objects of the nodes on the screen in the
    //     specified order
    // usage: preorder (mroot);
    //    similarly for the others



    void preorder (Node* treep) const;
    void inorder (Node* treep) const;
    void postorder (Node* treep) const;

    // data member

    Node* mroot;
};
#define BINARYTREE_H
#endif
