#include "Afin.h"
#include <fstream>

int main()
{
    Afin a;
    Afin b(a.getA(), a.getB());

    string mensaje = "eso es todo amigos";
    string temp;

    ofstream fichero;
    fichero.open("texto.txt");
    fichero << a.cifrar(mensaje);;
    fichero.close();

    ifstream lectura;
    lectura.open("texto.txt");
    getline(lectura, temp);
    lectura.close();

    cout << b.descifrar(temp) << endl;
    return 0;
}
