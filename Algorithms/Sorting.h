#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Sort
{
	public:
	    void bubbleSort(int *arr, int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-i; j++){
				if(arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
			}
		    }
		}

	    void quickSort(int *arr, int n);
	
};



