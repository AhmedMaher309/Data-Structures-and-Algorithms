#include "BinaryTree.h"

int main() {
    Tree tree;
    int arr[] = {4, 6, 7, 5, 3, 2, 1, 10, 9, 8, 11};
    int n = 11;
    Node* root = tree.createTree(arr, n);
    cout<<"creating a binary tree:\n";
    tree.printBinaryTreeDrawed(root);
    cout<<"/////////////////////////////////////////////////////////////\n";
    root = tree.createBST(arr, n);
    cout<<"creating a binary search tree:\n";
    tree.printBinaryTreeDrawed(root);
    cout<<"////////////////////////////////////////////////////////////\n"; 
    cout<<"pr-order traversal: ";
    tree.printPreOrder(root);
    cout<<endl;
    cout<<"in-order traversal: ";
    tree.printInOrder(root);
    cout<<endl;
    cout<<"post-order traversal: ";
    tree.printPostOrder(root);
    cout<<endl;


    return 0;
}

