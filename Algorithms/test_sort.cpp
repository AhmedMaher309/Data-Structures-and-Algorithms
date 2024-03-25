#include "Sorting.h"

int main(){
	int bubbleArr[] = {4, 6, 7, 5, 3, 2, 1, 10, 9, 8, 11, 1, 0};
	int n1 = 13;
	
	Sort S;
	S.bubbleSort(bubbleArr, n1);
	for(int i = 0 ; i < n1; i++){
		cout<< bubbleArr[i]<<" ";
	}
	cout<<endl;


        int quickArr[] = {4, 6, 7, 5, 3, 20, 1, 10, -9, 8, 11, 1, 0};
	int n2 = 13;
	S.quickSort(quickArr, 0, n2-1);
	for(int i = 0 ; i < n2; i++){
		cout<< quickArr[i]<<" ";
	}
	cout<<endl;


	int insertionArr[] = {4, 6, -7, 5, 3, 20, 1, 10, -9, 8, 11, 1, 0};
	int n3 = 13;
	S.insertionSort(insertionArr, n3);
	for(int i = 0; i < n3; i++){
		cout<<insertionArr[i]<<" ";
	}
	cout<<endl;



	return 0;
}
