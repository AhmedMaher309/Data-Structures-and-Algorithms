#include"dynamic_array.h"

// main for testing
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
    cout<<endl<<endl;
    d.deleteAt(0);
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    for(int i=0;i<d.getSize();i++){
        cout<<d.at(i)<<endl;
    }
    cout<<endl<<endl;
    d.deleteAt(3);
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    for(int i=0;i<d.getSize();i++){
        cout<<d.at(i)<<endl;
    }

    d.push(4);
    d.push(5);
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    d.pop();
    cout<<"size "<<d.getSize()<<endl;
    cout<<"actual size "<<d.getActualSize()<<endl;
    d.pop();
    cout<<d.getSize()<<endl;
    d.push(10);
    cout<<d.getSize()<<endl;
    cout<<d.at(0)<<endl<<d.at(1)<<endl;
    for(int i=0;i<d.getSize();i++){
        cout<<d.at(i)<<endl;
    }

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
    cout<<d.getSize()<<endl<<endl;
    d.pop();
    cout<<d.getSize()<<endl<<endl;
   
    
}