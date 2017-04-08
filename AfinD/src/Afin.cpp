#include "Afin.h"


Afin::Afin()
{
    cout << "generando clave "<<endl;
    this->Alfabeto = "abcdefghijklmn opqrstuvwxyz";
    this->ClaveA = generaAle(Alfabeto.size());
    this->ClaveB = 1+(rand()%Alfabeto.size());
}


Afin::Afin(int ClaveA, int ClaveB)
{
    this->Alfabeto = "abcdefghijklmn opqrstuvwxyz";
    this->ClaveA = ClaveA;
    this->ClaveB = ClaveB;
}

string Afin::cifrar(const string mensaje)
{
    string temp=mensaje;
    int tempo=0;

    for(unsigned int i=0; i<mensaje.size(); i++){
        tempo = (Alfabeto.find(mensaje[i])*ClaveA)+ClaveB;
        if(tempo>Alfabeto.size())
            temp[i] = Alfabeto[mod((Alfabeto.find(mensaje[i])*ClaveA)+ClaveB,Alfabeto.size())];

        else
            temp[i] = Alfabeto[(Alfabeto.find(mensaje[i])*ClaveA)+ClaveB];

        }
    return temp;
}


string Afin::descifrar(const string mensaje)
{
    string temp=mensaje;
    inversa(ClaveA, Alfabeto.size(), &ClaveAI);

    int tempo=0;
    for(unsigned int i=0; i<mensaje.size(); i++){
        tempo = (Alfabeto.find(mensaje[i])-ClaveB)*ClaveAI;
        if(tempo>Alfabeto.size())
            temp[i] = Alfabeto[mod((Alfabeto.find(mensaje[i])-ClaveB)*ClaveAI,Alfabeto.size())];

        else
            temp[i] = Alfabeto[tempo];
        }
    return temp;
}
