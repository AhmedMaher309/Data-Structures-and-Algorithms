#include <iostream>
#include <queue>
using namespace std;

class Node {
	public:
		int value;
		Node *right;
		Node *left;
		Node(int value) : value(value), left(nullptr), right(nullptr) {}

};

class Tree {
	private:
		Node* root;
	public:

		Tree(){
			root = nullptr;
		}

		Node * getRoot(){
			return root;
		}


		// creating a binary tree using level order approach
		Node *createTree(int *arr, int n) {
			if(n == 0) return nullptr;

			root = new Node(arr[0]);
			queue<Node*> q;
			q.push(root);

			for(int i = 0; i < n; i+=2){
				Node* current = q.front();
				q.pop();

				// create left child
				current->left = new Node(arr[i]);
				q.push(current->left);

				//create right child
				if(i + 1 < n){
					current->right = new Node(arr[i+1]);
					q.push(current->right);
				}
			}
			return root;

		}

		void printPreOrder(Node *root){
			if(root){
				cout<<root->value<<" ";
				printPreOrder(root->left);
				printPreOrder(root->right);
			}
		}

		void printInOrder(Node *root){
			if(root){
				printInOrder(root->left);
				cout<<root->value<<" ";
				printInOrder(root->right);
			}
		}

		void printPostOrder(Node *root){
			if(root){
				printPostOrder(root->left);
				printPostOrder(root->right);
				cout<<root->value<<" ";
			}
		}

		void printBinaryTree() {
			if (!root) return;

			queue<Node*> q;
			q.push(root);

			while (!q.empty()) {
				Node* current = q.front();
				q.pop();
				cout << current->value << " ";

				if (current->left) q.push(current->left);
				if (current->right) q.push(current->right);
			}
		}

		void printBinaryTreeDrawed(Node* root, int space = 0, int count = 7) {
			if (!root) return;
			space += count;
			printBinaryTreeDrawed(root->right, space);
			cout << endl;
			for (int i = count; i < space; i++)
				cout << " ";
			cout << root->value << "\n";
			printBinaryTreeDrawed(root->left, space);
		}


};
