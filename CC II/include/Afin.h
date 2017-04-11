#ifndef AFIN_H
#define AFIN_H

#include "Global.h"


class Afin
{
        int ClaveA;
        int ClaveAI;
        int ClaveB;

    public:
        Afin();
        ~Afin();
        string Alfabeto;
        string cifrar(const string);
        string descifrar(const string);

        int getA(){return this->ClaveA;};
        int getB(){return this->ClaveB;};
};


#endif // AFIN_H
