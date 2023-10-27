#include "linkedList.h"
int main(){
	LinkedList list;
	cout<<list.size()<<endl;
	list.push_front(5);
	cout<<list.size()<<endl;
	cout<<list.getHead()->data<<endl;
	list.push_front(20);
	cout<<list.size()<<endl;
	list.pop_front();
	cout<<"after delete "<<list.size()<<endl;
	list.pop_front();
	cout<<"after delete "<<list.size()<<endl;
	list.push_back(100);
	list.push_back(40);
	list.push_back(10);
	list.printList();
	list.insert(1,200);
	list.printList();
	cout<<list.front()<<endl;
	cout<<list.back()<<endl;
	cout<<list.size()<<endl;
	list.insert(1,19);
	list.printList();
	cout<<list.front()<<endl;
	cout<<list.back()<<endl;
	cout<<list.size()<<endl;
	list.printList();
	list.insert(3,90);
	list.printList();
	list.insert(6,60);
	list.printList();
	list.erase(5);
	list.printList();
	list.erase(0);
	list.printList();
	list.insert(0,700);
	list.printList();
	cout<<list.value_n_from_end(5)<<endl;


}





























