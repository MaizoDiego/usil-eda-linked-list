#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

// #include
// #include <vector>
// using namespace std;
//Esto lo hizo Diego Alejandro Maizo Rangel ->
template <typename T>
class Node
{
  public: 
  T datos;
  Node* next;
  Node (){
    ident=0;
    datos=0; 
    next = NULL;
  };
  Node(T x, T y){
    ident=x;
    datos=y;
    next= NULL;
  };
}

template <typename T>
class LinkedList
{
  public:
    Node* head, *tail;
    LinkedList()
    {
      head= NULL;
      tail=NULL;
    };
    T front(); // Retorna el elemento al comienzo
    T back(); // Retorna el elemento al final
    void push_front(T datos); // Agrega un elemento al comienzo 
    void push_back(T datos); // Agrega un elemento al final
    void pop_front(); // Remueve el elemento al comienzo
    void pop_back(); // Remueve el elemento al final
    T operator[](int); // Retorna el elemento en la posición indicada
    bool empty(); // Retorna si la lista está vacía o no
    int size(); // Retorna el tamaño de la lista 
    void clear_first(); // Elimina el primer elemento
    void clear_last(); //Elimina el ultimo 
    void sort(); // Ordena la lista
    void reverse(); // Revierte la lista
};


template <typename T>
void LinkedList<T>::empty(){
  if (head==NULL && tail==NULL){
    return true
  } else {
    return fals
  }
}


template <typename T>
void LinkedList



// Comments #2
template <typename T>
void LinkedList<T>::front(T &elem)
{

}

// Comments #3
template <typename T>
T LinkedList<T>::back()
{

}

//eliminar primero
template <typename T>
void  LinkedList<T>::clear_first()
{
  Node* temp=new Node;
  temp=head;
  head=head->next;
  delete temp;
}

//eliminar ultimo
template <typename T>
void  LinkedList<T>::clear_last()
{
  Node *actual= new Node;
  Node *previo= new Node;
  actual=head;
  while (actual->next!=NULL){
    previo=actual;
    actual=actual->next;
  }
  tail=previo;
  previo->next=NULL
  delete actual;
}

#endif

