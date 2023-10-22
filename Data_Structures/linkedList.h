#include <iostream>

using namespace std;

class Node{
	public:
	int data;
	Node * next;
};


class LinkedList{
	private:
		Node * Head;
		
	public:
		Node * getHead(){
			return this->Head;
		}

		int size(){
			Node* ptr = Head;
			int size = 0;
			while(ptr){
				size++;
				ptr = ptr->next;
			}
			return size;
		}

		bool empty(){
			if(!Head){
				return 1;
			}
			return 0;
		}

		int value_at(int place){
		        Node* ptr = Head;
			int count = 0;
			while(ptr && count < place){
				ptr = ptr->next;
				count++;
			}
			return ptr->data;
		}

	        void push_front(int data) {
    			Node* newNode = new Node;
    			newNode->data = data;      
    			newNode->next = Head;      
    			Head = newNode;            
		}	

};

