#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *siguiente;
};

void addElement(Nodo *&, Nodo *&, int);
bool cola_vacia(Nodo *);
void deleteElement(Nodo *&, Nodo *&, int &);
void showElementsInverted(Nodo *frente);

int main()
{
    Nodo *frente = NULL;
    Nodo *fin = NULL;
    int dato;

    cout << "Ingrese numero a la cola: ";
    cin >> dato;
    addElement(frente, fin, dato);
    cout << "Ingrese numero a la cola: ";
    cin >> dato;
    addElement(frente, fin, dato);
    cout << "Ingrese numero a la cola: ";
    cin >> dato;
    addElement(frente, fin, dato);
    cout << "Ingrese numero a la cola: ";
    cin >> dato;
    addElement(frente, fin, dato);

    cout << "\t Mostrando elementos INVERTIDOS DE COLA \n";


    showElementsInverted(frente);

    


    return 0;
}

void addElement(Nodo *&frente, Nodo *&fin, int n)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = n;
    nuevo->siguiente = NULL;

    if (cola_vacia(frente))
    {
        frente = nuevo;
    }
    else
    {
        fin->siguiente = nuevo;
    }

    fin = nuevo;
}

bool cola_vacia(Nodo *frente)
{
    return (frente == NULL) ? true : false;
}

void deleteElement(Nodo *&frente, Nodo *&fin, int &n)
{
    n = frente->dato;
    Nodo *aux = frente;

    if (frente == fin)
    {
        frente = NULL;
        fin = NULL;
    }
    else
    {
        frente = frente->siguiente;
    }

    delete aux;
}

//As a recursive method
void showElementsInverted(Nodo *frente)
{
    if (frente!=NULL)
    {
        showElementsInverted(frente->siguiente);
        cout << frente->dato<<" -> ";
    } 

}