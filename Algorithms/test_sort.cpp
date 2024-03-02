#include "Sorting.h"

int main(){
	int arr[] = {4, 6, 7, 5, 3, 2, 1, 10, 9, 8, 11, 1, 0};

	int n = 13;
	Sort S;
	S.bubbleSort(arr, n);

	for(int i = 0 ; i < n; i++){
		cout<< arr[i]<<" ";
	}
	cout<<endl;

	return 0;
}
