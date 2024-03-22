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
};



