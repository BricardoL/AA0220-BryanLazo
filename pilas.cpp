#include <iostream>

using namespace std;

//Nodo es la combinacion de un dato y puntero(senialando su posicion)
struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void addElement(Nodo *&, int);
void deleteElement(Nodo *&, int &);
void showElement(Nodo *&, int &);

int main()
{
    Nodo *pila = NULL; //Pila vacia, objetos que viene apuntara a la salida(fondo)
    int dato;          //Dato
    int opc;

    cout << "Que quieres hacer con la pila: \n";
    while (opc != 3)
    {
        cout << "1. Agregar numero \n";
        cout << "2. Ver elementos de la pila \n";
        cout << "3. Salir \n";
        cin >> opc;

        switch (opc)
        {
        case 1:
            cout << "Inserte el dato: ";
            cin >> dato;
            addElement(pila, dato);
            break;

        case 2:
            while (pila != NULL)
            {
                if (pila->siguiente != NULL)
                {
                    showElement(pila, dato);
                    cout << " , ";
                }
                else
                {
                    showElement(pila, dato);
                    cout << ".\n";
                }
            }

            default:
                break;
            
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

    void deleteElement(Nodo * &pila, int &n)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        delete aux;
    }

    void showElement(Nodo * &pila, int &n)
    {
        Nodo *aux = pila;
        n = aux->dato;
        pila = aux->siguiente;
        cout << aux->dato;
    }