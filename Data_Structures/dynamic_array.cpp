#include <iostream>
using namespace std;

class DynamicArray{
    private:
        int size;
        int * array;
        int elementsNumber;  // the actual capacity of the array filles by the user 

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

        int getSize(){ 
            return this->elementsNumber; 
        }


        bool isEmpty() {
            if(elementsNumber == 0) return 1;
            return 0;
        }

        int at(int index){
            if (index >= 0 && index < elementsNumber) {
            return array[index];
            }
            throw out_of_range("Index out of range");
        }
        
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
                int * newArray = new int[this->size*2];
                for(int i = 0; i < size; i++){
                    newArray[i] = this->array[i];
                }
                newArray[this->size] = element;
                this->array = newArray;
                this->size = this->size*2;
                elementsNumber++;
            }
        }
        
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
                this->array = newArray;
                this->size = this->size*2;
                elementsNumber++;
            }
        }

        // insert at the beginning of the array
        void prepend(int intem){
            this->insert(0, intem);
        }

        // just move the elementsNumber one step backwards and the size will be decreases by one
        void pop(){
            this->elementsNumber--;
        }

        //utility for debugging
        int getActualSize(){
            return this->size;
        }


};

// size = 1, elements = 0
// size = 1, elements = 1
// size = 2, elements = 2
// size = 4, elements = 3

int main(){
    DynamicArray d;
    d.push(5);
    d.insert(1,20);
    d.insert(1,22);
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    for(int i=0;i<d.getSize();i++){
        cout<<d.at(i)<<endl;
    }
    cout<<endl;
    d.prepend(15);
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    for(int i=0;i<d.getSize();i++){
        cout<<d.at(i)<<endl;
    }

    //cout<<d.getSize()<<endl;
    // d.push(10);
    // cout<<d.getSize()<<endl;
    // cout<<d.at(0)<<endl<<d.at(1)<<endl;
    // for(int i=0;i<d.getSize();i++){
    //     cout<<d.at(i)<<endl;
    // }

    // int x = 15;
    // for (int i = 0; i < 10; i++)
    // {
    //     d.push(x);
    //     x++;
    // }
    // cout<<d.getSize()<<endl<<endl;
    // for (int i = 0; i < d.getSize(); i++)
    // {
    //     cout<<d.at(i)<<endl<<endl;
    // }
    // cout<<d.getSize()<<endl<<endl;
    // d.pop();
    // cout<<d.getSize()<<endl<<endl;
   
    
}