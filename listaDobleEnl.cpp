#include<iostream>
#include <stdlib.h>

using namespace std;


struct Nodo{
	int valor;
	Nodo *ant;
	Nodo *sig;
};

void insert( int);
void show();
void showInReverse();

Nodo*lista=NULL;

int main (){
	int opcion,num1,num2,num3;

	do{
		cout<<"Eliga Una Opcion...\n";
		cout<<"1- Insertar Lista \n";
		cout<<"2- Mostrar Lista \n";
		cout<<"3- Salir \n";
		cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"ingrese el numero de Nodos ";
				cin>>num1;
				for(int i=1; i<=num1;i++){
					cout<<"Ingresa el valor del nodo "<<i<<"\n";
					cin>>num2;
				insert(num2);
				}
				break;
			case 2:
				cout<<"Las Listas Doblemente Enlazadas son: \n";
				show();
				cout<<endl;
				showInReverse();
				cout<<"\n";
				break;
			case 3:
				cout<<"Gracias";
				break;
		}
	
}while(opcion!=3);
return 0;
}

void insert(int data){
	Nodo *new_nodo=new Nodo;
	new_nodo->sig=NULL;
	new_nodo->ant=NULL; // NULL--nn -- nn -- NULL
	new_nodo->valor=data; //20
	
	if(lista==NULL){
		lista=new_nodo;
	}
	else{
		Nodo *aux=lista;
		while(aux->sig!=NULL){
		aux=aux->sig;	
		}
		aux->sig=new_nodo;
		new_nodo->ant=aux; //     NULL--nn--nn--NULL
	}
	cout<<"\n";
	cout<<"El elemento "<<data<<"  a sido insertado en la lista \n";
	cout<<"\n";
}

void show(){
	Nodo *aux=lista;

	while(aux!=NULL){
		cout<<aux->valor<<", ";
		aux=aux->sig; //NULL -- n1 -- n2 -- n3 -- NULL
	}
	cout<<endl;
}

void showInReverse(){
	Nodo *aux=lista;
	while(aux->sig!=NULL){
		aux=aux->sig;
	}
	while(aux!=NULL){
		cout<<aux->valor<<", ";
		aux=aux->ant;
	}
	cout<<endl;
}