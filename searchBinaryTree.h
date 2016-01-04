// UNFINISHED -- READ THROUGH AND FIX
// FINAL VERSION SHOULD HAVE NONE OF MY INSTRUCTIONS LEFT


// you do doc and any other stuff that should be here
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include "binarytree.h"
#include "node.h"

class BinarySearchTree: public BinaryTree
{
public:
   //@creates a new binary search tree
   //@post: an empty binary search tree object exists
   //@usage: BinarySearchTree bst;
   BinarySearchTree();

   //@releases memory for a binary search tree
   //@pre: binary search tree object exists
   //@post: binary search tree object does not exist
   //@usage: automatically done at end of scope
   ~BinarySearchTree();

   // *****************************************************************
   // *  pre for all member functions: binary search tree object exists
   // *****************************************************************

   //@searches for a key in a binary search tree object and
   //    retrieves the corresponding item
   //@pre: key has been assigned.
   //@post: theItem contains tkey with rest of the item if
   //    tkey is found in the binary search tree object
   //    else an exception is thrown
   //@usage: bst.Retrieve (abbrev, meaning);
   bool Search (const ItemType& theItem) const;

   //@inserts a new item into the binary search tree
   //@pre: newItem has been assigned
   //@post: if the newItem's key is not already in the tree
   //       and there is memory available
   //         then the newItem is added to the tree
   //       else an exception is thrown
   //@usage: you do
   void Insert (const ItemType& newItem);
//   void remove (const ItemType& theItem);
//   Node * FindMin() const;
//   Node * FindMax() const;
   bool Remove (ItemType& theItem);

protected:  // recursive helper functions
   //@recursively searches (modeling on binary search) for a key
   //@pre: treeptr is assigned. newItem is assigned.
   //@post: searches for tkey in the tree with treeptr's root.
   //    If tkey is found, theItem is the key together with the other
   //    parts of the item. Else an exception is thrown.
   //@usage: retrieveItem (mroot, key, rest);
   bool lookup (Node * treeptr, const ItemType& theItem) const;

   // write the documentation
   void insertItem (Node *& treeptr, const ItemType& newItem);
//   void removeItem (Node *& treeptr, const ItemType& theItem);
   bool removeItem(Node *& treeptr, const ItemType& theItem);

   ItemType removeHelp(Node *& treeptr);

//   Node * lookforMin(Node * treeptr) const;
//   Node * lookforMax(Node * treeptr) const;
   //Prune's helpers shear etc go here else remove this

};
#endif
