#ifndef __LINKEDLIST_H__
#define __LINKEDLIST_H__

#include <iostream>
#include <functional>
#include <stdexcept>
#include "type.h"
using namespace std;

//REALIZADO POR DIEGO ALEJANDRO MAIZO RANGEL
template <typename T>
struct Node //Se crea un nado con un tipo de data y su puntero 
{
T data; 
Node<T> *next=nullptr; 
};

template <typename T>
class LinkedList
{
  private:
  Node<T> *head, *tail; //Se crean 2 punteros de tipo node
  typedef Node<T> *PNODE;
  typedef PNODE &RPNODE;
  T1 tam; //variable para retornar el tamaño
  public:
    LinkedList(){
      head=nullptr; //se inicializan los 2 puntero en null
      tail=nullptr; 
      tam=0; //la variable se inicia en 0
    }
    T front(); // Retorna el elemento al comienzo
    T back(); // Retorna el elemento al final
    void push_front(T &elem); // Agrega un elemento al comienzo
    void push_back(T &elem); // Agrega un elemento al final_LISTO
    void pop_front(); // Remueve el elemento al comienzo pero no lo retorna
    void pop_back(); // Remueve el elemento al final pero no lo retorna
    void insert(T &elem);
    void insert2 (T &elem);
    void internal_insert(RPNODE pPrev, T &elem);
    T &operator[](size_t pos); // Retorna el elemento en la posición indicada
    bool empty(); // Retorna si la lista está vacía o no
    size_t size(ostream &os); // Retorna el tamaño de la lista 
    void clear(); // Elimina todos los elementos de la lista
    void sort(); // Ordena la lista
    void reverse(); // Revierte la lista
    void display(ostream &os); //listo
    ostream &recorrer_imprimiendo(ostream &os);
    template <typename F>
    T recorrer(F &func);
};

template <typename T>
T &LinkedList<T>::operator[](size_t pos)
{
    Node<T> *ptr=head;
    T1 x=0;
    while (x<pos){
      ptr=ptr->next;
      x++;
    }
    return ptr->data;
}

template <typename T>
void LinkedList<T>::sort()
{


}
template <typename T>
T LinkedList<T>::front()
{
  Node <T>* prm=head; //se crea nuevo puntero que apunta a lo que apunta head
  if (empty()){
    throw out_of_range ("El primer valor es NULL");
    return 0;
  }
  else
  {
    prm->data=head->data; //el tipo de dato del nuevo puntero es igual al tipo de dato del puntero head
    cout<<"El primer elemento de la Lista es: "<<prm->data<<endl;
    return prm->data; //regresa el primer dato
  }
}

template <typename T>
T LinkedList<T>::back()
{
  Node<T> *ult=tail; //se crea nuevo puntero
    if (empty()){
    throw out_of_range ("El utlimo valor es NULL");
    return 0;
  } else if(tail==head){
    ult->data=head->data;
    cout<<"El ultimo elemento de la Lista es: "<<ult->data<<endl;
    return ult->data; //regresa el ultimo dato
  } else {
    ult->data=tail->data;
    cout<<"El ultimo elemento de la Lista es: "<<ult->data<<endl;
    return ult->data; //regresa el ultimo dato
  }
}

//se encarga de mostrar la lista 
template <typename T>
void LinkedList<T>::display(ostream &os)
{
  Node<T> *temp;
  if (empty()){
    os<<"La Lista Enlazada es vacia {No hay elementos en ella}"<<endl;
  } else {
  temp=head;
  os<<"La ListaEnlazada es: "<<endl;
  while (temp!=nullptr){ 
   os<<temp->data<<" ";
   temp=temp->next;
  }
  }
}

template <typename T>
void LinkedList<T>::pop_back()
{
  if (empty()){
    cout << "La lista está vacia \n";
  } else if(tail==head){
    delete tail; 
    head=nullptr;
    tail=nullptr;
    tam--;
  } else {
    Node <T> *prev, *curr; //se crean 2 punteros prev(previo) y curr(actual)
    curr=tail; //curr apunta a tail
    prev=head;//prev a head
    while(prev->next!=tail){ //se viaje en la lista al nodo anterior de tail
      prev=prev->next;
    }
    prev->next=nullptr; //la direccion del puntero next ahora es null
    prev=curr; //prev es igual a cola ahora
    delete curr; //se libera espacio de memoria
    tam--; //se reduce tamaño
  }
}

template <typename T>
void LinkedList<T>::pop_front()
{
  if (empty()){
    cout << "La lista está vacia \n";
  } else if(head==tail){ 
    delete head; 
    head=nullptr;
    tail=nullptr;
    tam--;
    cout<<"La lista ahora no tiene elementos"<<endl;
  } else {
    Node<T> *temp=head; //se crean 1 puntero temp
    head=head->next;  //el puntero head ahora va apuntar a la direccion de next
    tam--;//se reduce el tamaño
    delete temp; //se libera espacio de memoria y se elimina el nodo temp
  }
}

template <typename T>
void LinkedList<T>::clear(){
  //los punteros head y tail apuntan a null 
  Node <T>*limp=head->next;
  while (limp!=tail){ 
    limp->data=0; // se encarga de que todos los nodos apunten a null
    limp=limp->next;
  }
  head=nullptr; //los punteros head y tail apuntan a null 
  tail=nullptr;
  tam=0;
}

template <typename T>
void LinkedList<T>::push_front(T &elem){
  Node<T> *ptr=new Node<T>(); 
  ptr->data=elem; 
  ptr->next=nullptr;
  if (head==nullptr && tail==nullptr){
    head=ptr; 
    tail=ptr; 
    tam++;
  } else{
    ptr->next=head;
    head=ptr;
    tam++;
  }
}

template <typename T>
void LinkedList<T>::push_back(T &elem){
  Node<T> *ptr= new Node<T>();
  ptr->data=elem; 
  ptr->next=nullptr; 
  if (head==nullptr && tail==nullptr){
    head=ptr; 
    tail=ptr; 
    tam++;
  }else{
    Node <T> *temp=head;
    while (temp->next!=nullptr){
      temp=temp->next;
    }
    temp->next=ptr;
    tail=ptr;
    tam++;
  }
}

template <typename T>
size_t LinkedList<T>::size(ostream &os)
{
  os<<" \nEl tamaño de la ListaEnlazada es: "<<tam<<endl;
  return tam; 
}

template <typename T>
bool LinkedList<T>::empty()
{
  if (head==nullptr && tail==nullptr){
    return true;
  } else {
    return false; 
  }
}

template <typename T>
void LinkedList<T>::reverse()
{
  Node <T>*prnd=nullptr;
  Node <T>*crnd, *nxtnd;
  crnd=nxtnd=head;
  tail=head;
  while(nxtnd!=nullptr){
    nxtnd=nxtnd->next;
    crnd->next=prnd;
    prnd=crnd;
    crnd=nxtnd;
  } 
  head=prnd;
}

template <typename T>
void LinkedList<T>::insert(T &elem)
{
  Node <T> **numw=&head;
  Node <T> *act=head;
  while (*numw && elem > (*numw)->data)
  { act=act->next;
    numw =&(*numw)->next; }
  Node <T>*nuew=new Node<T>();
  nuew->data=elem;
  nuew->next=*numw;
  *numw=nuew;
}

template <typename T>
ostream &LinkedList<T>::recorrer_imprimiendo(ostream &os)
{
  if(empty())
  {  os<<"La lista está vacia"<<endl; }
  else{
  auto pNode = head;
  while( pNode != nullptr )
  {os << pNode->data << endl;
      pNode = pNode->next; }
  }
  return os; 
}

template <typename T>
ostream &operator<<(ostream &os, LinkedList<T> &list)
{
  return list.recorrer_imprimiendo(os);
}

#endif
