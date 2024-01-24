#include<iostream>
#include<limits>

using namespace std;
int INFINITY = std::numeric_limits<int>::max();
class HashTable{
	private:
		int * keys;
		int * values;
		int size;

		// Hash Function -->  h(key)= key % table-size
		// linear probing --> h(key) = (key + 1) % table-size
	
	public:
		HashTable(int k, int n){
			this->size = n;
			this->keys = new int[n];
			this->values = new int[n];
			for(int i = 0; i < n;i++){
			       this->keys[i] = INFINITY;
			       this->values[i] = INFINITY;
			}		
		}

		void add(int key, int value){
			int hash = key % size;
			if(this->keys[hash] == INFINITY || this->keys[hash] == key){
				this->keys[hash] = key;
				this->values[hash] = value;
				return;
			}
			int i = hash+1;
			while(this->keys[i] != INFINITY){
				i = (i+1) % this->size;
				if(i >= this->size) // wrap around to the beginning of the table
					i = 0;
			}
			this->keys[i] = key;
			this->values[i] = value;
		}

		bool exist(int key){
			int hash = key % size;
			if(this->keys[hash] == key)
				return 1;
			
			for(int i = 0; i < this->size; i++){
				if(this->keys[i] == key)
					return 1;
			}
			return 0;
		}

		void remove(int key){
			int hash = key % size;
			if(this->keys[hash] == key){
				this->keys[hash] = INFINITY;
				this->values[hash] = INFINITY;
				return;
			}
			for(int i = 0; i < this->size; i++){
				if(this->keys[i] == key){
					this->keys[i] = INFINITY;
					this->values[i] = INFINITY;
					break;
				}
			}
		}

		void printHashTable(){
			for(int i = 0; i < this->size; i++){
				cout<< this->keys[i] << "--->" << this->values[i] << endl;
			}
		}
	
};
