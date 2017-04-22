#include "RSA.h"
#include <iostream>
#include <string>



int main()
{

    RSA Receptor;

    string a[5] = {"2","G","a","R", "a"};

    string *mn= Receptor.cifrar(a);
    string *pn= a;

    for(int i=0; i<6; i++)
        cout << mn+i<< endl;

    /*
    string cifrado[5];
    for(int i=0; i<5; i++)
    cifrado[i]  = Receptor.cifrar(a[i]);


    cout << endl<< endl;
    for(int i=0; i<5; i++)
    cout << Receptor.descifrar(cifrado[i]);


*/
    cout << endl<< endl;

    cout << endl<< endl;

    //cout << sizeof(cifrado)/sizeof(cifrado[0]);

    string tu[3] = {"hola","ados","tres"};
    string *puntero = tu;

    for(int i=0; i<3; i++)
    cout << *puntero++<< endl;
    return 0;
}
