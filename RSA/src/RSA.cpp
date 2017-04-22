#include "RSA.h"

RSA::RSA()
{
    alfabeto = "0123456789abcdefghijklmnopqrstuvwxyz, ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    GenPrime(p,512); // GenPrime generates a random prime n of length
    GenPrime(q,512);
    n = p*q;
    phi = (p-1)*(q-1);
    e = Ge(phi);
    d = Gd(e,phi);
}

RSA::RSA(ZZ e, ZZ n)
{
    alfabeto = "0123456789abcdefghijklmnopqrstuvwxyz, ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    this->e = e;
    this->n = n;
}

ZZ RSA::Ge(ZZ phi)
{
    e = RandomLen_ZZ(512);
    while(euclides(e,phi)!=1) {
        e = RandomLen_ZZ(512);
    }
    return e;
}


ZZ RSA::Gd(ZZ e, ZZ n)
{
    d = inv(e,phi);
    return d;
}


ZZ RSA::indice(ZZ M)
{
    ZZ a1=exponenciacion(M, mod(d, p-1), p);
    ZZ a2=exponenciacion(M, mod(d, q-1), q);

    return mod( mod(a1*inv(p, q)*p, n) + mod(a2*inv(q, p)*q, n), n);
}

/*
string RSA::cifrar(string plano)
{
    int indice = alfabeto.find(plano[0]);
    ZZ indice2 = convertirINT(indice);
    ZZ indice3 = exponenciacion(indice2,e,n);
    string mensaje = convertirSZZ(indice3);

    return mensaje;
}*/


string *RSA::cifrar(string plano[])
{
    int len = sizeof(plano)/sizeof(plano[0]);
    string temp[5];
    cout << "hola " << endl;
    for(int i=0; i<5; i++)
    {


    int indice = alfabeto.find(plano[i][0]);
    ZZ indice2 = convertirINT(indice);
    ZZ indice3 = exponenciacion(indice2,e,n);
    string mensaje = convertirSZZ(indice3);

    temp[i] = mensaje;
    //cout << temp[i] << endl<< endl<< endl;
    }
    //string*t= temp;

    return temp;
}


string RSA::descifrar(string cifrado)
{
    ZZ indi = string_ZZ(cifrado);
    ZZ indi2 = indice(indi); ///indice palabra alfabeto
    int indi3 = convertirZZ(indi2);/// mismo valor que anterior pero en int
    string mensaje = "0";
    mensaje[0] = alfabeto[indi3];
		return mensaje;
}
