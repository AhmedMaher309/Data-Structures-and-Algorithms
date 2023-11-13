#include"queue.h"


int main()
{
	Queue q1;
	q1.enqueue(3);
	q1.enqueue(5);
	for(int i = 0; i < 2; i++){
		cout<<q1.dequeue()<<endl;
	}
}
