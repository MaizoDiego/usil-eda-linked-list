#include <iostream>
#include "linkedlist.h"
#include "type.h"

using namespace std;

int main()
{
  LinkedList<T1> lista;
  T1 x;
  for(x = 0; x < 10 ; x++)
    lista.insert2(x);
  cout << "Fin de la inserción ..." << endl;
  lista[5] = 78;
  cout << lista;
}