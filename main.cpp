#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "node.h"
#include "binaryTree.h"
#include "searchBinaryTree.h"
using namespace std;

int main()
{
    BinarySearchTree b1;
    int x = 0;
    srand(time(NULL));
    cout << "Inserting... ";
    for(int i = 0 ; i < 20 ; i++)
    {
        x = (rand()%40) + 1;
        cout << x << " ";
        b1.Insert(x);
    }
    cout <<"\n\nPre-Order Traversal:" << endl;
    b1.preorderTraverse();
    cout <<"\nIn-Order Traversal: " << endl;
    b1.inorderTraverse();
    cout <<"\nPost-Order Traversal: " << endl;
    b1.postorderTraverse();
    if(b1.Search(x)) //searches for the last number added
        cout << "\n" << x << " is there." << endl;
    if(!b1.Search(400)) //searches for a number not there
        cout << "\n400 is not there." << endl;
    cout << "\nEnter a number to remove: ";
    cin >> x;
    b1.Remove(x);
    cout <<"\nIn-Order traversal after removing " << x << endl;
    b1.inorderTraverse();
    cout <<"\nThis is a copy of the first Binary Search Tree" << endl;
    BinarySearchTree b2 (b1);
    b2.inorderTraverse();
}
