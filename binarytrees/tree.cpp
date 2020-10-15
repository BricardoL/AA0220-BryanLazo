#include <iostream>

using namespace std;

struct Node
{

    int info;
    Node *right;
    Node *left;
};

// Funciones

void mainMenu();
void inOrder(Node *);
void preOrder(Node* );
void postOrder(Node* );

Node *CrearNodo(int);

void InsertarNodo(Node *&, int);

Node *tree = NULL;

int main()
{

    mainMenu();
    cin.get();
    return 0;
}

//Menu principal

void mainMenu()
{

    int data, opc;

    do
    {

        cout << "MENU PRINCIPAL";

        cout << "1. Insertar Nodo";

        cout << "2. Mostrar";

        cout << "Seleccione una de las siguientes opciones: ";

        cin >> opc;

        switch (opc)
        {

        case 1:
            cout << "DIGITE EL VALOR DEL NODO: ";
            cin >> data;
            InsertarNodo(tree, data);
            cin.get();
            break;
        
        case 2:
        cout<<"Mostrando  en inOrder ";
            inOrder(tree);
        cout<<"\nPreOrder ";
            preOrder(tree);
        cout<<"\nPostOrder ";
            postOrder(tree);
            cin.get();

            break;
        }

    } while (opc != 3);
}

// Crear un nuevo nodo

Node *CrearNodo(int n)
{

    Node *Nuevo_Nodo = new Node();
    Nuevo_Nodo->info = n;
    Nuevo_Nodo->right = NULL;
    Nuevo_Nodo->left = NULL;

    return 0;
}

//Insertar nodos en el arbol

void InsertarNodo(Node *&tree, int n)
{

    if (tree == NULL)
    {

        Node *Nuevo_Nodo = CrearNodo(n);

        tree = Nuevo_Nodo;
    }

    else
    {

        int ValorRaiz = tree->info;

        if (n < ValorRaiz)
        {

            InsertarNodo(tree->left, n);
        }

        else
        {

            InsertarNodo(tree->right, n);
        }
    }
}

void inOrder(Node *tree) //5, 6, 10, 7, 4 --> 6, 10, 5, 4, 7
{
    if (tree)
    {
        inOrder(tree->left);
        cout << tree->info << endl;
        inOrder(tree->right);
    }
}

void preOrder(Node* tree) {
    if(tree) {
        cout << tree->info << endl;
        preOrder(tree->left);
        preOrder(tree->right);
    }
}

void postOrder(Node* tree) {
    if(tree) {
        postOrder(tree->left);
        postOrder(tree->right);
        cout << tree->info << endl;
    }
}