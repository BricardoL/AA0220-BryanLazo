#include <iostream>

using namespace std;

void parAsValue(int, string);
void parAsPunteroAndRef(int *, string &);


//punteros y referencias
int main(void){
    string b = "Hola soy b";
    //declaramos un puntero, este puede guardar dir de memoria, y asi sucesivamente
    string *pb = &b;
    string **ppb = &pb;
    string ***pppb = &ppb;
    string ****ppppb = &pppb;
    string *****pppppb = &ppppb;

    cout<<*pb<<" "<<**ppb<<" "<<***pppb<<" "<<****ppppb<< " "<<*****pppppb<<endl;

    //referencia apunta la dir de memoria sin anotarla, solo el valor
    int a = 100;
    int &pa = a;
    int &ppa = pa;
    cout<<ppa<<endl;

    //pasar parametro a funcion como valor
    int prueba = 10;
    string proof = "Proof";
    parAsValue(prueba, proof);
    cout<<prueba<< " "<< proof<<endl;
    cin.get();

    /*pasar parametro como puntero y ref para no crear copias y
    tratar con el valor original*/
    parAsPunteroAndRef(&prueba, proof);
    cout<<prueba<<" "<<proof<<endl;


    return 0;
}

void parAsValue(int p, string g){
    p = p + 6;
    g = g.substr(0, 2);
    cout<<p<<" "<<g<<endl;
}

void parAsPunteroAndRef(int *a, string &b){
    *a = *a + 6;
    b = b.substr(0, 2);
    cout<< *a<< " "<< b<<endl;
}