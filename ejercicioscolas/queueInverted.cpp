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
void showElementsInverted(Node *frente);

int main()
{
    Node *frente = NULL;
    Node *fin = NULL;
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

void addElement(Node *&frente, Node *&fin, int n)
{
    Node *nuevo = new Node();
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

bool cola_vacia(Node *frente)
{
    return (frente == NULL) ? true : false;
}

void deleteElement(Node *&frente, Node *&fin, int &n)
{
    n = frente->dato;
    Node *aux = frente;

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
void showElementsInverted(Node *frente)
{
    if (frente!=NULL)
    {
        showElementsInverted(frente->siguiente);
        cout << frente->dato<<" -> ";
    } 

}