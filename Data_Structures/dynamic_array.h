#include <iostream>
using namespace std;


class DynamicArray{
    private:
        int size;
        int * array;
        int elementsNumber;  // the actual capacity of the array filles by the user 

        void resize(){
            // when you reach capacity, resize to double the size
            // when popping an item, if size is 1/4 of capacity, resize to half
            if(this->size == this->elementsNumber){
                int newSize = this->size*2;
                int * newArray = new int[newSize];
                fill_n(newArray, newSize, 0);
                for(int i = 0; i < this->size; i++){
                    newArray[i] = this->array[i];
                }
                delete[] this->array;
                this->array = newArray;
                this->size = newSize;
            }
            else if(this->elementsNumber == this->size/4){
                int newSize = this->size/2;
                int * newArray = new int[newSize];
                fill_n(newArray, newSize, 0);
                for(int i = 0; i < newSize; i++){
                    newArray[i] = this->array[i];
                }
                delete[] this->array;
                this->array = newArray;
                this->size = newSize;
            }
        }

    public:

        // initialize vector without any parameters
        // the initial size is 1, and the number of elements is 0
        // as there is not elements inserted yet
        DynamicArray(){
            array = new int[1];
            size = 1;
            elementsNumber = 0;
        }
    
         // initialize vector with with specified size and elements number is also zero
        DynamicArray(int size){
            array = new int[size];
            this->size = size;
            elementsNumber = 0;
        }

        // initialize vector with specified size and initial value 
        // so the elements number is equal to the size of the vector
        DynamicArray(int size, int initialValue){
            array = new int[size];
            for(int i = 0; i < size; i++){
                array[i] = initialValue;
            }
            elementsNumber = size;
            this->size = size;
        }

        // get the size of the array
        int getSize(){ 
            return this->elementsNumber; 
        }

        // check if the array is empty
        bool isEmpty() {
            if(elementsNumber == 0) return 1;
            return 0;
        }

        // get the element at the specified index
        int at(int index){
            if (index >= 0 && index < elementsNumber) {
            return array[index];
            }
            throw out_of_range("Index out of range");
        }
        
        // push element at the end of the array
        void push(int element){
            // there are no elements yet in the array
            if(size == 1 && elementsNumber == 0){
                array[0] = element;
                elementsNumber++;
            }
            // there are elements in the array and the array can be expanded without reallocation
            else if(size >1 && elementsNumber < size){
                array[elementsNumber] = element;
                elementsNumber++;
            }
            // there are elements in the array but there is no space for additional elements
            else if(size >= 1 && elementsNumber == size){
                this->resize();
                this->array[elementsNumber] = element;
                elementsNumber++;
            }
        }
        
        // insert element at specific index
        void insert(int index, int item){
            // the index is out of range
            if(index > this->elementsNumber){
                throw out_of_range("Index out of range");
            }
            // the array can be extended without new allocation for the new size
            else if(this->elementsNumber < this->size){
                for(int i = this->elementsNumber; i>= index; i--){
                    this->array[i+1] = this->array[i];
                }
                array[index] = item;
                elementsNumber++;
            }
            // the array cannot be extended without reallocation for the new size
            else if(this->elementsNumber == this->size){
                int * newArray = new int[this->size*2];
                for(int i = 0; i < index; i++){
                    newArray[i] = this->array[i];
                }
                newArray[index] = item;
                for(int i = index+1; i < this->size+1; i++){
                    newArray[i] = this->array[i-1];
                }
                delete [] this->array;
                this->array = newArray;
                this->size = this->size*2;
                elementsNumber++;
            }
            this->resize();
        }

        // insert at the beginning of the array
        void prepend(int intem){
            this->insert(0, intem);
        }

        // delete element from specific index
        void deleteAt(int index){
            // the index is out of range
            if(index > this->elementsNumber){
                throw out_of_range("Index out of range");
            }
            else if(elementsNumber == 0){
                throw runtime_error("no elements in the array");
            }
            else{
                for(int i = index; i <= this->elementsNumber; i++){
                    this->array[i] = this->array[i+1];
                }
                elementsNumber--;
            }
            this->resize();
        }

        // remove one element from the end of the array
        void pop(){
            if(elementsNumber == 0){
                throw runtime_error("no elements in the array");
            }
            this->elementsNumber--;
            this->resize();
        }

        // remove all elements from the array that are equal to the item 
        void remove(int item){
            int * newArray = new int[this->size];
            fill_n(newArray, this->size, 0);
            int i = 0;
            int j = 0;
            while(i < this->elementsNumber){
                if(array[i] != item){
                    newArray[i] = item;
                    j++;
                }
                i++;
            }
            this->array = newArray;
            this->resize();
        }

        // search for a specific element and return the first index containing it, if not found return -1
        int find(int item){
            for(int i = 0; i < this->elementsNumber; i++){
                if(array[i] == item){
                    return i;
                }
            }
            return -1;
        }

        //utility for debugging
        int getActualSize(){
            return this->size;
        }
};
