#include "linkedList.h"
int main(){
	LinkedList list;
	cout<<list.size()<<endl;
	list.push_front(5);
	cout<<list.size()<<endl;
	cout<<list.getHead()->data<<endl;
}


