#include "Afin.h"


Afin::Afin()
{
    cout << "generando clave ..."<<endl;
    this->Alfabeto = "abcdefghijklmnopqrstuvwxyz .,¿?\t";
    this->ClaveA = generaAle(Alfabeto.size());
}


string Afin::cifrar(const string mensaje)
{
    string temp=mensaje;
    int tempo=0;

    for(unsigned int i=0; i<mensaje.size(); i++){
        tempo = (Alfabeto.find(mensaje[i])*ClaveA);
        if(tempo>Alfabeto.size())
            temp[i] = Alfabeto[mod((Alfabeto.find(mensaje[i])*ClaveA),Alfabeto.size())];
        else
            temp[i] = Alfabeto[tempo];
        }
    return temp;
}


string Afin::descifrar(const string mensaje)
{
    string temp=mensaje;
    ClaveAI = inversa(ClaveA, Alfabeto.size());

    int tempo=0;
    for(unsigned int i=0; i<mensaje.size(); i++){
        tempo = (Alfabeto.find(mensaje[i]))*ClaveAI;
        if(tempo>Alfabeto.size())
            temp[i] = Alfabeto[mod((Alfabeto.find(mensaje[i]))*ClaveAI,Alfabeto.size())];
        else
            temp[i] = Alfabeto[tempo];
        }
    return temp;
}


Afin::~Afin()
{
    //des
    cout << "listo !" << endl;
}
