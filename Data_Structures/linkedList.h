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
		LinkedList(){
			Head = nullptr;
		}

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

		void pop_front(){
			if(!Head)
				return;
			Node * temp = Head;
			Head = Head->next;
			delete temp;
		}

		void push_back(int item){
			Node* newNode = new Node;
			newNode->data = item;
			newNode->next = nullptr;
			if(!Head){
				Head = newNode;
			}
			else{
				Node * ptr = Head;
				while(ptr->next){
					ptr = ptr->next;
				}
				ptr->next = newNode;
			}
		}

		void pop_back(){
			if(!Head);

			else if(!Head->next){
				delete Head;
				Head = nullptr;
			}
			else{
				Node * ptr = Head;
				while(ptr->next->next){
					ptr = ptr->next;
				}
				Node* ptr2 = ptr->next;
				delete ptr2;
				ptr->next = nullptr;
			}

		}
		
		int front(){
			if(!Head){
				return -1;
			}
			return Head->data;
		}

		int back(){
			if(!Head){
				return -1;
			}
			else{
				Node* ptr = Head;
				while(ptr->next){
					ptr = ptr->next;
				}
				return ptr->data;
			}
		}

		void insert(int index, int value){
			if(index > this->size() || index < 0){
				cout<<"Index out of range!"<<endl;
			}
			else if(index == 0){
 				this->push_front(value);
			}
			else{
				int count = 0;
				Node*ptr = Head;
				while(count < index-1){
					count++;
					ptr = ptr->next;
				}
				Node * newNode = new Node;
				newNode->data = value;
				newNode->next = ptr->next;
				ptr->next = newNode;
			}
		}

		void erase(int index){
			if(index > this->size() || index < 0){
				cout<<"Index out of range"<<endl;
			}
			else if(index == 0){
				this->pop_front();
			}
			else{
				int count = 0;
				Node*prev = Head;
				while(count < index-1){
					count++;
					prev = prev->next;
				}
				Node* current = prev->next;
				prev->next = current->next;
				delete current;
			}
		}


		// if the index is out of range
		// it prints "Index out of range" and returns -1
		int value_n_from_end(int indexFromEnd){
			if(indexFromEnd >= this->size()|| indexFromEnd < 0){
				cout<<"Index out range"<<endl;
				return -1;
			}

			int index = this->size() - indexFromEnd;
			Node *ptr = Head;
			int count = 0;
			while(count < index-1){
				count++;
				ptr = ptr->next;
			}
			return ptr->data;
		}
		
		void reverse(){
			if (Head == nullptr || Head->next == nullptr)
            			return;

        		Node *prev = nullptr;
       		 	Node *curr = Head;

        		while (curr != nullptr)
        		{
            			Node *temp = curr->next;
            			curr->next = prev;
            			prev = curr;
            			curr = temp;
       		 	}
			Head->next = nullptr;
			Head = prev;

		}

		void remove_value(int value){
			if(Head == nullptr)
				return;
			if(Head->data == value && !Head->next){
				delete Head;
				Head = nullptr;
				return;
			}
			if(Head->data == value && Head->next){
				Node* temp = Head;
				Head = Head->next;
				delete temp;
				temp = nullptr;
			}

			Node* curr = Head;
			while(curr->next){
				if(curr->next->data == value){
					Node * temp = curr->next;
					curr->next = temp->next;
					delete temp;
					temp = nullptr;
					
				}
				else
					curr = curr->next;
			}
		}

		void printList(){
			if(!Head){
				cout<<"Linkedlist is empty"<<endl;
				return;
			}
			Node* ptr = Head;
			while(ptr){
				cout<<ptr->data<<"->";
				ptr = ptr->next;
			}
			cout<<"NULL"<<endl;
		}

};















