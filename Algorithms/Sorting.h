#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Sort
{
private:
	int partition(int *arr,int low,int high){
		int pivot=arr[high];
		int i=(low-1);
		for(int j=low;j<=high;j++){
			if(arr[j]<pivot){
				i++;
				swap(arr[i],arr[j]);
			}
		}
		swap(arr[i+1],arr[high]);
		return i+1;
	}


public:
	void bubbleSort(int *arr, int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n-i; j++){
				if(arr[j] > arr[j + 1]) swap(arr[j], arr[j+1]);
			}
		}
	}

	void quickSort(int *arr, int low, int high){
		if(low < high){
			int pi = partition(arr, low, high);
			quickSort(arr, low, pi - 1);
			quickSort(arr, pi + 1, high);
		}
	}

	void insertionSort(int * arr, int n){
		int key, j;
		for (int i = 1; i < n; i++){
			key = arr[i];
			j = i - 1;

			while(j >= 0 && arr[j] > key){
				arr[j+1] = arr[j];
				j--;
			}
			arr[j+1] = key;
		}
	}

	//function to merge the two sorted array
	void mergeTwoSortedArrays(int *leftArr, int *rightArr, int *arr, int n, int m){

		int i = 0;
		int j = 0;
		int k = 0;

		while(i<n && j<m){
			if(leftArr <= rightArr){
				arr[k] = leftArr[i];
				i++;
			}
			else{
				arr[k] = rightArr[j];
				j++;
			}
			k++;
		}

		//copy the remaining elements of the leftArr
		while(i<n){
			arr[k] = leftArr[i];
			i++;
			k++;
		}

		//copy the remaining elements of the rightArr
		while(j<n){
			arr[k] = rightArr[j];
			j++;
			k++;
		}

	}

	void mergeSort(int *arr, int size){
		if(size == 1 || size == 0){
			return;
		}

		//create the leftArr and the rightArr
		int n = size/2;
		int m = size - n;

		int leftArr[n];
		int rightArr[m];


		//pointer for arr
		int k = 0;


		for(int i = 0; i < n; i++)
		{
			leftArr[i] = arr[k];
			k++;
		}

		for(int j = 0; j < m; j++)
		{
			rightArr[j] = arr[k];
			k++;
		}

		//call mergeSort on left subarray
		mergeSort(leftArr, n);

		//call mergeSort on right subarray
		mergeSort(rightArr, m);

		//merging the two sorted subarrays back to the original one
		mergeTwoSortedArrays(leftArr, rightArr, arr, n, m);
		return;
	}

};



