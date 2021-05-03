#include <iostream>
#include <functional>
#include "linkedlist.h"
#include "type.h"

int main() {
  LinkedList<T2> list;
  LinkedList<T2> list2;

    T2 x;
    T2 y=5.5;
  for(x = 0; x < 10 ; x++)
    //list.push_front(x);
    //list.insert(x);
    //list.pop_back();
    list.push_back(x);
  cout << "Fin de la inserción ..." << endl;
  cout << list;
  list.size(cout);
  list.insert(y);
  cout<<"========"<<endl;
  cout<<list;
  list.size(cout);
  //cout<<list[2]<<endl;
  //list.clear();
  //list.display(cout);
  //cout<<list;

  /*
  list.size(cout);
  cout<<"=========================="<<endl;
  T1 x=2;
  T1 x2=30;
  T1 x3=2333;
  T1 x4=55555555;
  T1 x5=10;
  T1 x6=23012102;
  list.push_front(x);
  list.push_back(x2);
  list.push_back(x3);
  list.push_back(x4);
  list.push_front(x5);
  list.push_back(x6);
  list.display(cout);
  list.size(cout);
  list.front();
  list.pop_front();
  list.clear();
  list.back();
  cout<<"=========================="<<endl; 
  list.pop_back();
  
  list.push_back(x);
  list.push_front(x2);
  list.pop_front();
  list.pop_back();
  list.display(cout);
  list.size(cout);
  cout<<"=========================="<<endl; 
  list.front();
  list.back();
  //list.reverse();
  list.display(cout);*/
  

}
