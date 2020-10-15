#include <iostream>

using namespace std;

struct Node
{
    int dato;
    Node *siguiente;
};


void addElement(Node *&, Node *&, int);
bool cola_vacia(Node *);
void deleteElement(Node *&, Node *&, int &); 



int main(){
    Node *frente = NULL;
    Node *fin = NULL;
    int dato;

    cout<<"Ingrese numero a la cola: ";
    cin>>dato;
    addElement(frente, fin, dato);
    cout<<"Ingrese numero a la cola: ";
    cin>>dato;
    addElement(frente, fin, dato);
    cout<<"Ingrese numero a la cola: ";
    cin>>dato;
    addElement(frente, fin, dato);
    cout<<"Ingrese numero a la cola: ";
    cin>>dato;
    addElement(frente, fin, dato);

    cout<<"\t eliminando elementos \n";
    while (frente != NULL)
    {
        deleteElement(frente, fin, dato);
        if (frente != NULL)
        {
            cout<<dato<<" , ";
        } else
        {
            cout<<dato<<".";
        }
        
        
    }
    

    return 0;
}

void addElement(Node *&frente, Node *&fin, int n){
    Node *nuevo = new Node();
    nuevo->dato = n;
    nuevo->siguiente = NULL;

    if(cola_vacia(frente)){
        frente = nuevo;
    } else
    {
        fin->siguiente = nuevo;
    }
    
    fin = nuevo;
}

bool cola_vacia(Node *frente){
    return (frente == NULL)? true : false; 
}

void deleteElement(Node *&frente, Node *&fin, int &n){
    n = frente->dato;
    Node *aux = frente;

    if(frente == fin){
        frente = NULL;
        fin = NULL;
    } else
    {
        frente = frente->siguiente;
    }
    
    delete aux;
}