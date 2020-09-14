#include <iostream>

using namespace std;

void mainMenu(string);
int damageCalculus(int, int);
int factorial(int);

int main(void) {
    int n;
    //cout<<"Ingrese un numero: ";
    //cin>>n;
    //factorial(n);
    string player;
    cout<<"Ingrese su nombre: ";
    cin>> player;
    mainMenu(player);

    return 0;
}

void mainMenu(string player){
    cout<<"Bienvenido "<<player<<" a su juego favorito de guerra!\n";
    int opc;
    while (opc != 2)
    {
        cout<<"\nMENU...\n";
        cout<<"1- Ver puntaje de danio\n 2- Salir\n";
        cin>>opc;
        switch (opc)
        {
        case 1:
            int dead, hs;
            cout<<"Disparos realizados: ";
            cin>>dead;
            cout<<"Headshots: ";
            cin>>hs;
            cout<<"Dano total: \n";
            cout<< damageCalculus(dead, hs);
            break;
        
        default: cout<<"Ingrese opcion valida\n";
            break;
        }
    }
    
}

//To calculate damage in fact of shots and headshots
int damageCalculus(int dead, int head){
    if (dead == 0 && head == 0) return 0; //base case
    else if(dead != 0 && head == 0)  return 30 + damageCalculus(dead - 1, head);
    else if(dead == 0 && head != 0)  return 100 + damageCalculus(dead, head - 1);
    else return 130 + damageCalculus(dead - 1, head - 1);
}

//Base case of recursion
int factorial(int n){
    if(n == 0) return 1; //base case
    else return n * factorial(n-1);
}