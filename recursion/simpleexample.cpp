#include <iostream>

using namespace std;

string firstRecursion(string);

int main(void){
    string a;
    cout<<"Ingrese una frase: ";
    cin>>a;
    firstRecursion(a);
    cout<<endl;

    return 0;
}

//Past form to encrypt with recursion
string firstRecursion(string a){
    cout<<a.substr(a.length()-1, 1);
    return (a.length()==1) ? a : firstRecursion(a.substr(0, a.length()-1));
}