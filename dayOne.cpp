#include <iostream>

using namespace std;

void muestraUsuario(int, string, string, bool, int, int);
void usuario(string, string, bool, int, int);
string estadoBooleano(bool);

enum opcion {no, yes};

int main(void){
    int id, edad, siono;
    string nombre, apellido;
    bool active = false;
    opcion opcion;

    cout<<"Bienvenido a un sistema de recoleccion de datos"<<endl;
    cin.get();
    cout<<"Nombre: ";
    cin>>nombre;
    cout<<"Apellido: ";
    cin>>apellido;
    cout<<"Edad: ";
    cin>>edad;
    cin.get();
    cout<<"Desea activar su usuario y asi ver sus datos, escriba  1 si o 0 no"<<endl;
    cin>>siono;

    muestraUsuario(siono, nombre, apellido, active, edad, id);
    
    return 0;
};

void muestraUsuario(int a, string n, string p, bool act, int e, int id){
    switch (a)
    {
    case 0 :
        cout<<"Vuelva pronto, ha elegido no ver su usuario"<<endl;
        break;

    case 1 :
        cout<<"Cargando datos... Espere un momento"<<endl;
        cin.get();
        usuario(n, p, act, e, id);
        break;

    
    default:
        cout<<"ELiga un numero correcto, por favor"<<endl;
        break;
    };
};

void usuario(string n, string a, bool act, int e, int id){
        act = true;
        int variable;
        string *punt = &n;
        id = e/10 + (2*e);
        cout<<"EL usuario que acaba de registrar: \n";
        cout<<"Nombre: "<< n<<endl;
        cout<<"Apellido: "<< a<<endl;
        cout<<"Edad: "<< e<<endl;
        cout<<"id generado: "<< id<<endl;
        cout<<"Estado: "<< estadoBooleano(act)<<endl;
        cout<<"Espacio de tu nombre en memoria: "<< sizeof n<<endl;
        cout<<"Direccion en memoria de nombre: "<<punt;
};

string estadoBooleano(bool a){
        if (a)
        {
            return "Activo";
        } else
        {
            return "Inactivo";
        }
        
        
}
