#include <iostream>
#include <sstream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void addElement(Nodo * &, int);
void showElement(Nodo * &pila, int &n);


int main(void){
    Nodo *pila = NULL;
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

void addElement(Nodo * &pila, int n)
    {
        Nodo *nuevo = new Nodo();
        nuevo->dato = n;
        nuevo->siguiente = pila;
        pila = nuevo;
        cout << "Se ha ingresado correctamente a pila el numero " << n << endl;
    }


void showElement(Nodo * &pila, int &n)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        cout << aux->dato;
    }