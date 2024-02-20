#include "Tree.h"

int main() {
    Tree tree;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int n = 7;
    Node* root = tree.createTree(arr, n);
    cout << "Constructed Binary Tree: ";
    tree.printBinaryTree();
    cout << endl;
    tree.printBinaryTreeDrawed(tree.getRoot());
    cout<<endl;
    return 0;
}

