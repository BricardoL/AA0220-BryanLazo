#include <iostream>

using namespace std;

int main(void)
{
    float numero[5]; // Un array de 5 numeros enteros
    float media;
    float total;
    int numeritos[3] = {1, 3, 5}; //otra forma de poner datos

    cout << "Ingrese cinco elementos" << endl;
    cin >> numero[0] >> numero[1] >> numero[2] >> numero[3] >> numero[4];
    for (int i = 0; i <= 4; i++)
    {
        media += numero[i];
    };
    // Y hallamos la suma

    total = media / 5;
    cout << "Su media aritmetica es " << total << endl;
    cout << "La suma de numeritos es " << numeritos[0] + numeritos[1] + numeritos[2] << endl;
    //voltearlos for
    for (int k = 4; k >= 0; k--)
    {
        cout << "Numero ingresado n" << k << "es " << numero[k] << " " << endl;
    };

    float vector1[3];
    float vector2[3];
    float vectorSuma[3];
    int i;

    // Pedimos los datos del primer vector
    for (i = 0; i < 3; i++)
    {
        cout << "Introduce la componente " << i
                << " del primer vector: ";
        cin >> vector1[i];
    }

    // Pedimos los datos del segundo vector
    for (i = 0; i < 3; i++)
    {
        cout << "Introduce la componente " << i
                << " del segundo vector: ";
        cin >> vector2[i];
    }

    // Calculamos la suma
    for (i = 0; i < 3; i++)
        vectorSuma[i] = vector1[i] + vector2[i];

    // Y mostramos el resultado
    cout << "El vector suma es ";
    for (i = 0; i < 3; i++)
        cout << vectorSuma[i] << " ";

    float matriz[2][3][3];
    float matrizSuma[3][3];
    int m, fila, columna;
    
    // Pedimos los datos de las dos matrices
    for (m=0; m<2; m++)
        for (fila=0; fila<3; fila++)
            for (columna=0; columna<3; columna++)
            {
                cout << "En la matriz " << m+1
                    << ", dime el dato de la fila " << fila+1 
                    << " y la columna " << columna+1 << ": ";
                cin >> matriz[m][fila][columna];
            }
    
    // Calculamos la suma
    for (m=0; m<2; m++)
        for (fila=0; fila<3; fila++)
            for (columna=0; columna<3; columna++)
                matrizSuma[fila][columna] += matriz[m][fila][columna];
    // La línea anterior es errónea: estamos dando por sentado
    // que la matriz suma contiene ceros, y quizá no sea así
    
    
    // Y mostramos el resultado (puede salir un poco descolocado)
    cout << "La suma es ";
    for (fila=0; fila<3; fila++)
    {
        for (columna=0; columna<3; columna++)
            cout << matrizSuma[fila][columna] << " "; 
        cout << endl;
    };

    int mat[2][2];
    
    for (int fila = 0; fila < 2; fila++)
    {
        for (int columna = 0; columna < 2; columna++)
        {
            cout<< "Ingrese dato de la fila "<< fila+1 << " , columna "
                <<columna+1<<endl;
            cin>>mat[fila][columna];

        }
        
    };

    cout << "La matriz es "<<endl;
    for (int fila=0; fila<2; fila++)
    {
        for (int columna=0; columna<2; columna++)
            cout << mat[fila][columna] << " "; 
            cout << endl;
    };
    
    int trans;
    cout<<"Y su transpuesta: "<<endl;
    for (int fila=1; fila>=0; fila--)
    {
        for (int columna=1; columna>=0; columna--)
            cout << mat[fila][columna] << " "; 
            cout << endl;
    };
    
    return 0;
    
}