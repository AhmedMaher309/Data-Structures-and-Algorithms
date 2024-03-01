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

		Node * insertInBST(Node * root, int value){
			if(!root) return new Node(value);
			
			if(value < root->value) 
				root->left = insertInBST(root->left, value);
			else if(value > root->value) 
				root->right = insertInBST(root->right, value);
			return root;
		}



	public:

		Tree(){
			root = nullptr;
		}

		Node * getRoot(){
			return root;
		}


		// creating a binary tree from a given array with size n using level order approach
		Node *createTree(int *arr, int n) {
			if(n == 0) return nullptr;

			root = new Node(arr[0]);
			queue<Node*> q;
			q.push(root);

			for(int i = 1; i < n; i+=2){
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
		
		// create a binary search tree form a given array with size n
		Node * createBST(int *arr, int n){
			if(n == 0) return nullptr;

			root = nullptr;
			for(int i = 0; i < n; i++) root = this->insertInBST(root, arr[i]);
			return root;
		}

		// apply Breadth first search to find a node with specific value
		Node * BFS(int value){
			if(!root) return nullptr;
			Node * result= new Node(-1);
			queue<Node *> q;
			q.push(root);

			while(!q.empty()){
				Node * current = q.front();
				q.pop();
				
				if(current->value) return current;
				
				if(current->left)  q.push(current->left);
				if(current->right) q.push(current->right);
			}
			cout<<result->value<<endl;
			return result;
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
