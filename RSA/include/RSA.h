#ifndef RSA_H
#define RSA_H

#include "GLOBAL.h"

class RSA
{
	private:
		ZZ p;
		ZZ q;
		ZZ d;
		ZZ phi;

	public:
		ZZ e;
		ZZ n;
		string alfabeto;
        RSA();
        RSA(ZZ e, ZZ n);
        ZZ Ge(ZZ phi);
        ZZ Gd(ZZ e, ZZ n);
        ZZ indice(ZZ M);
        string *cifrar(string[]);
        //string cifrar(string);
        string descifrar(string);

};

#endif // RSA_H
