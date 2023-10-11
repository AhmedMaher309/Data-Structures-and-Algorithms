#include <iostream>
using namespace std;

class DynamicArray{
    private:
        int size;
        int * array;
        int elementsNumber;

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
            if (index >= 0 && index < size) {
            return array[index];
            }
            // Handle out of bounds index here
            // throw an exception or return a default value
            // For example:
            throw out_of_range("Index out of bounds");
        }
        
        void push(int element){
            // there is no elements yet in the array
            if(size == 1 && elementsNumber == 0){
                array[0] = element;
                elementsNumber++;
            }
            else if(size >1 && elementsNumber < size){
                array[elementsNumber] = element;
                elementsNumber++;
            }
            // there is elements in the array but there is no space for additional elements
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

};

// size = 1, elements = 0
// size = 1, elements = 1
// size = 2, elements = 2
// size = 4, elements = 3

int main(){
    DynamicArray d;
    cout<<d.isEmpty()<<endl;
    //cout<<d.getSize()<<endl;
    d.push(5);
    cout<<d.isEmpty()<<endl;
    //cout<<d.getSize()<<endl;
    d.push(10);
    //cout<<d.getSize()<<endl;
    // for(int i=0;i<d.getSize();i++){
    //     cout<<d.at(i)<<endl;
    // }
    int x = 15;
    for (int i = 0; i < 10; i++)
    {
        d.push(x);
        x++;
    }
    cout<<d.getSize()<<endl<<endl;
    for (int i = 0; i < d.getSize(); i++)
    {
        cout<<d.at(i)<<endl<<endl;
    }
    
}