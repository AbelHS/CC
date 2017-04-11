#include "Afin.h"
#include <fstream>

int main()
{
    Afin a;

    ifstream escritura;
    escritura.open("plano.txt");
    while(!escritura.eof())
    {
        string mensajeC;
        ofstream lectura("cifrado.txt", ios_base::app );

        getline(escritura, mensajeC); ///copiamos del mensaje original
        lectura << a.cifrar(mensajeC) << endl; ///pegamos a nuestro nuevo txt

    }
    escritura.close();



    ifstream escrituraD;
    escrituraD.open("cifrado.txt");
    while(!escrituraD.eof())
    {
        string mensajeC;
        ofstream lectura("descifrado.txt", ios_base::app );

        getline(escrituraD, mensajeC); ///copiamos del mensaje original
        lectura << a.descifrar(mensajeC) << endl; ///pegamos a nuestro nuevo txt

    }
    escrituraD.close();

    return 0;
}
