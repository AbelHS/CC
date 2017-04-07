#include "Afin.h"

Afin::Afin()
{

    this->Alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    this->ClaveA = generaAle(Alfabeto.size());
    this->ClaveB = ran(Alfabeto.size());

}


Afin::Afin(int ClaveA, int ClaveB)
{
    /// funcionloca(int plano,  int cifrado, int alfabeto)

    this->Alfabeto = "abcdefghijklmnopqrstuvwxyz ";
    this->ClaveAI = inversa(ClaveA, Alfabeto.size());
    this->ClaveB = ClaveB;
}

string Afin::cifrar(const string mensaje)
{
    string temp=mensaje;

    for(unsigned int i=0; i<mensaje.size(); i++){
        temp[i] = Alfabeto[mod(Alfabeto.find(mensaje[i]+ClaveB),Alfabeto.size())];
    }
    return temp;
}

string Afin::descifrar(const string mensaje)
{
    string temp=mensaje;

    for(unsigned int i=0; i<mensaje.size(); i++){
        temp[i] = Alfabeto[mod(Alfabeto.find(mensaje[i]-ClaveB),Alfabeto.size())];
    }
    return temp;
}
