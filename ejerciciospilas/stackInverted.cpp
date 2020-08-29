#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

struct nodo{
    char dato;
    struct nodo *sgte;
};

typedef struct nodo *TPila;

/*                      Crear Nodo
------------------------------------------------------------------*/

TPila crearNodo(char x)
{
    TPila newNodo = new(struct nodo);
    newNodo->dato = x;
    return newNodo;
}
/*                      Apilar
------------------------------------------------------------------*/
void push(TPila &top, char x)
{
    TPila aux = crearNodo(x);
    aux->sgte = top;
    top = aux;
}
/*                      Desapilar
------------------------------------------------------------------*/
char pop(TPila &top)
{
    int c ;
    TPila aux;
    
    aux = top ;
    c = aux->dato;   // asignamos el primer vamor de la pila
    top = aux->sgte ;
    delete(aux);
    return c;
}

//Invertir cadena
void invertirCadena( TPila &p, string &cad )
{
     // Copiando caracteres a la pila 
    for(int i=0; i<cad.size(); i++)
    push(p, cad[i]);  
    
     // Desapilando y remplanzando en la cadena 
    for(int i=0; i<cad.size(); i++)
    cad[i] = pop( p );   

}



int main()
{
    TPila pila = NULL;    // creando Pila
    string cad;
    
    cout<<"INVERTIR CADENA USANDO PILA\n";
    
    cout << " Ingrese palabra: ";
    getline(cin, cad);
    
    invertirCadena( pila, cad );
    
    cout << " Cadena invertida: " << cad <<endl;
    
    cout<<"\n ";
    
    return 0;
}