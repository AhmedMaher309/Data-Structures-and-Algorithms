#include <iostream>

#include "dynamic_array.h"

using namespace std;

class Queue{
	private:
		DynamicArray dy;
	public:
		void enqueue(int value){
			dy.push(value);
		}

		int dequeue(){
			if(dy.getSize() == 0){
				cout<<"queue is empty ";
				return -1;
				cout<<endl;
			}
			int value = dy.at(0);
			dy.deleteAt(0);
			return value;
		}

		bool empty(){
			return dy.isEmpty();
		}

		void getSize(){
			dy.getSize();
		}

};
