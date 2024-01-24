#include"HashTable.h"

int main(){
	HashTable H(0 ,10);
	H.add(5,6);
	H.printHashTable();
	H.add(5,4);
	cout<<endl<<endl;
	H.printHashTable();
	H.add(15,9);
	cout<<endl<<endl;
	H.printHashTable();
	H.add(10,8);
	cout<<endl<<endl;
	H.printHashTable();
	cout<<endl;
	cout<<H.exist(2)<<endl;
	cout<<H.exist(5)<<endl;
	H.remove(10);
	cout<<endl<<endl;
	H.printHashTable();





}

