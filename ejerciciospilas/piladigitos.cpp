#include <iostream>
#include <sstream>

using namespace std;

struct Node
{
    int dato;
    Node *siguiente;
};

void addElement(Node * &, int);
void showElement(Node * &pila, int &n);


int main(void){
    Node *pila = NULL;
    string datos;
    string clave;
    int x;

    cout<<"Escriba los numeros: ";
    cin>>datos;

    int cant = datos.length();
    for (int i = 0; i < cant; i++)
    {
        
        clave = datos.substr(i, 1);
        cout<<clave<<endl;
        stringstream geek(clave);

        geek>>x;

        addElement(pila, x);
    }

    cout<<"\n ELEMENTOS EN LA PILA GRAFICAMENTE: \n";
    while (pila != NULL)
            {
                if (pila->siguiente != NULL)
                {
                    showElement(pila, x);
                    cout << " -> ";
                }
                else
                {
                    showElement(pila, x);
                    cout << "-> NULL\n";
                }
            }
    
    
    return 0;
}

void addElement(Node * &pila, int n)
    {
        Node *nuevo = new Node();
        nuevo->dato = n;
        nuevo->siguiente = pila;
        pila = nuevo;
        cout << "Se ha ingresado correctamente a pila el numero " << n << endl;
    }


void showElement(Node * &pila, int &n)
    {
        Node *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        cout << aux->dato;
    }