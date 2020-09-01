#include <iostream>

using namespace std;

//struct for elements in list, stack and queues.
struct Elem
{
    int dato;
    Elem *siguiente;
};

//Rename Elem to Nodo
typedef Elem Nodo;

void insertInList(Nodo *&, int);
void showList(Nodo *);
void searchElement(Nodo *, int);
void deleteElement(Nodo *&, int);
void deleteList(Nodo *&, int &);


int main(void)
{
    Nodo *lista = NULL;

    int dato, opc;
    opc=1;

    cout << "Lista Simplemente Enlazada\n\n";
    while (opc > 0 && opc < 6)
    {
        cout << "1. Aniadir elemento.\n";
        cout << "2. Mostrar elementos.\n";
        cout << "3. Buscar elemento en lista.\n";
        cout << "4. Borrar un elemento de lista.\n";
        cout << "5. Eliminar toda la lista.\n";
        cout<< "Pulse otro numero para salir...\n";
        cin >> opc;
        switch (opc)
        {
        case 1:
            cout << "\nIngresa numero: ";
            cin >> dato;
            insertInList(lista, dato);
            break;

        case 2:
            cout << "Mostrando elementos de lista...\n";
            showList(lista);
            break;

        case 3:
            cout << "Inserta elemento a buscar: ";
            cin>> dato;
            searchElement(lista, dato);
            break;
        
        case 4:
            cout << "Inserta elemento a eliminar: ";
            cin>> dato;
            deleteElement(lista, dato);
            break;

        case 5:
            cout<<"Eliminando lista...";
            deleteList(lista, dato);
            break;
        }
    }

    return 0;
}

//Insert in list with ascendent order
void insertInList(Nodo *&lista, int n)
{
    Nodo *nuevo = new Nodo();
    nuevo->dato = n;

    Nodo *aux1 = lista;
    Nodo *aux2;

    //Ascendent
    while ((aux1 != NULL) && (aux1->dato < n))
    {
        aux2 = aux1;
        aux1 = aux1->siguiente;
    }

    if (lista == aux1)
        lista = nuevo;
    else
        aux2->siguiente = nuevo;

    nuevo->siguiente = aux1;

    cout << "Elemento " << n << " esta en lista hoy!!!\n";
}

//See elements
void showList(Nodo *lista)
{
    Nodo *inicio = lista;

    while (inicio != NULL)
    {
        cout << inicio->dato << " -> ";
        inicio = inicio->siguiente;
    }
}

//Search in List
void searchElement(Nodo *lista, int n)
{
    bool band = false;
    int i = 0; //see the position in list
    Nodo *inicio = new Nodo();
    inicio = lista;

    //with list asc ordered
    while ((inicio != NULL) && (inicio->dato <= n))
    {

        if (inicio->dato == n)
            band = true;

        inicio = inicio->siguiente;
        i++;
    }

    if (band == true)
        cout << "Elemento " << n << " ha sido encontrado en LISTA en la posicion " << i << endl;
    else
        cout << "Elemento " << n << " no ha sido encontrado en LISTA, revisa elemento por favor\n ";
}

//Delete one element
void deleteElement(Nodo *&lista, int n)
{
    if (lista != NULL)
    {
        Nodo *aux_delete;
        Nodo *anterior = NULL;
        aux_delete = lista;

        while ((aux_delete != NULL && aux_delete->dato != n))
        {
            anterior = aux_delete;
            aux_delete = aux_delete->siguiente;
        }

        if (aux_delete == NULL)
        {
            cout << "Elemento NO ESTA EN LISTA\n";
        }
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_delete;
            cout << "Elemento " << n << " borrado exitosamente\n";
        }
        else
        {
            anterior->siguiente = aux_delete->siguiente;
            delete aux_delete;
            cout << "Elemento " << n << " borrado exitosamente\n";
        }
    }
}

//delete all list
void deleteList(Nodo *&lista, int &n){
    while(lista != NULL){
    Nodo *aux = lista;
    n = aux->dato;
    lista = aux->siguiente;
    delete aux;
    }
    cout<<"Ya se elimino todos los elementos...\n";

}