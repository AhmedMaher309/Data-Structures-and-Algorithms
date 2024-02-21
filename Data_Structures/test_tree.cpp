#include "BinaryTree.h"

int main() {
    Tree tree;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    Node* root = tree.createTree(arr, n);
    tree.printBinaryTree();
    cout << endl;
    tree.printBinaryTreeDrawed(tree.getRoot());
    cout<<endl;
    tree.printPreOrder(tree.getRoot());
    cout<<endl;
    tree.printInOrder(tree.getRoot());
    cout<<endl;
    tree.printPostOrder(tree.getRoot());
    cout<<endl;


    return 0;
}

