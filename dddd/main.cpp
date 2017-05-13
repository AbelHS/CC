#include <fstream>
#include <sstream>
#include <stdio.h>
#include <NTL/ZZ.h>

#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */
#include <windows.h>


using namespace std;
using namespace NTL;

ZZ RestoChino(ZZ a, ZZ p, ZZ b, ZZ q)
{
	ZZ n = p*q;
    return mod( mod( a*q*inv(q,p), n ) + mod( b*p*inv(p,q), n ), n );
}

//   M ≡ Cd mod p
//   M ≡ Cd mod q
int raton()
{
    POINT mouse;
    GetCursorPos(&mouse);
    return mouse.x+mouse.y;
}


int mod(int a, int b) {
	int r, q;
	q = a/b;
	r = a-(b*q);
	if(r<0){return r+b;}
	return r;
}

int random(int n) {
	srand(time(NULL));
	int r = mod(rand(),n-1)+1;
	return r;
}

int temp[100];
int x;
int expoBits(int nbits)
{
	int res=1;
	for(int i=0; i<nbits;i++)
		res <<= 1;
	return res;
}




ZZ mod(ZZ a, ZZ b) {
	ZZ r, q;
	q = a/b;
	r = a-(b*q);
	if(r<ZZ(0)){return r+b;}
	return r;
}

ZZ exp(ZZ a, ZZ e, ZZ m){
	ZZ r = ZZ(1);
	while(e>ZZ(0)){
		if((e&1)==1){
			r = mod(r*a,m);
		}
		a = mod(a*a,m);
		e>>=1;
	}
	return r;
}

int *binarizador(int n)
{
    int *tempo;
    int i=0;
    while(n>0){
            temp[i] = n%2;
            n>>=1;
        i++;
    x = i;
    }
    return temp;
}

ZZ bi_ZZ(int b[], int a)
{
    ZZ temp = ZZ(1);
    for(int i=0; i<a; i++)
    {
        if(b[i]==1)
            temp <<=1;
        else if(b[i]==0){
            temp <<=1;
            temp += ZZ(1);
        }

    }
    return temp/=2;;
}


int *aleatorio(int semilla, int alea, int particiones, int vueltas)
{
    int *Z = binarizador(semilla);
    //int *W = binarizador(alea);

    int  X[alea];
    int indice = 0;
    int indice2 = alea/particiones;
    int indice3 = indice2;
    int particiones2 = particiones;
    int ran;// = random(indice2);

    for(int i=0; i<particiones; i++)
        for(int j=0; j<alea/particiones; j++){
            X[indice] = *(Z+j);
            indice++;}


    for(int i=0; i<vueltas; i++)
        for(int j=0; j<particiones2; j++){
            if(particiones2%2){
                ran = random(indice2);
                X[indice3-1] = mod((X[indice3-1] + X[ran]),2);
                particiones2--;
            }
            else{
                ran = random(indice2);
                X[indice3*2-1] = mod((X[indice3*2-1] + X[ran]),2);
                particiones2--;
            }
        }

    return X;
}


int ZZ_INT(ZZ entero)
{
    int temp;
    conv(temp, entero);
    return temp;
}

ZZ INT_ZZ(int entero)
{
    ZZ temp;
	conv(temp, entero);
	return temp;
}




ZZ euclides(ZZ a, ZZ b)
{
	ZZ r;
	while(b>ZZ(0))
    {
		r = mod(a,b);
		a = b;
		b = r;
	}

	return a;
}

ZZ inv(ZZ a, ZZ b)
{
    ZZ t=b;

	ZZ r, q, x, x1, x2;
	if(b==ZZ(0)) {
		x2=ZZ(1);
		return x2;
	}
	else {
		x1=ZZ(0);
		x2=ZZ(1);
		while(b>ZZ(0)) {
			q = a/b;
			r = a - (q * b);
			x = x2 - (q * x1);
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
		}
		if (x2<ZZ(0)){
            return x2+t;
            }
        else
            return x2;
	}
}

ZZ exponenciacion(ZZ a, ZZ m, ZZ n)
{
	ZZ r = ZZ(1);
	while(m>ZZ(0)){
		if((m&1)==1){
			r = mod(r*a,n);
		}
		a = mod(a*a,n);
		m>>=1;
	}
	return r;
}


ZZ string_ZZ(string cadena)
{
	ZZ p(INIT_VAL, cadena.c_str()); ///Devuelve un puntero de tipo ZZ a cadena
	return p;
}

string ZZ_string(ZZ numero) {
    stringstream temp;
    temp<<numero;
	string cadena = temp.str();
    return cadena;
}

class RSA
{
	private:
		//ZZ p;
		//ZZ q;
		//ZZ d;
		//ZZ d1;
		ZZ phi;

	public:
	    ZZ p;
		ZZ q;

		ZZ d;

		ZZ e;
		ZZ n;
		string alfabeto;
        RSA();
        RSA(ZZ e, ZZ n);
        ZZ Ge(ZZ phi);
        ZZ Gd(ZZ e, ZZ n);
        ZZ indice(ZZ M);
        ZZ cifrar(string);
        int descifrar(ZZ);

};


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


ZZ RSA::Gd(ZZ e, ZZ phi)
{
    d = inv(e,phi);
    return d;
}

ZZ RSA::cifrar(string plano)
{
    int indice = alfabeto.find(plano[0]);
    ZZ indice2 = INT_ZZ(indice);
    ZZ indice3 = exponenciacion(indice2,e,n);
    return indice3;
}

int RSA::descifrar(ZZ cifrado)
{
    ZZ temp = exponenciacion( mod(cifrado,n) ,d,n);
    int temp2 = ZZ_INT(temp);
    return temp2;
    //return alfabeto[temp2];
}

int main()
{

    //string a[5] = {"L","u","y","R", "a"};
    RSA Emisor;

    ofstream escritura;
    escritura.open("Claves.txt");
    escritura << ZZ_string(Emisor.e)<<"\n";
    escritura << ZZ_string(Emisor.n)<<"\n";
    escritura << ZZ_string(Emisor.d)<<"\n";
    escritura.close();

    RSA receptor(Emisor.e,Emisor.n);

    ZZ cifrado = receptor.cifrar("4");

    cout << Emisor.descifrar(cifrado);



    return 0;
}



/*
#include "global.h"


/// 1. congruencia linear.
void LCG(int a, int b, int n)
{
    int seed = 0;
    int x = seed;

    do
    {
        x = mod( ((a*x) +b), n);
        cout << x << endl;
    }
    while (x!=seed);

}


/// 2.	algoritmo de Euclides  recursiva para a=412 y b=260
int euclidesmcd(int a, int b)
{
    if(b == 0)
        return a;
    return euclidesmcd(b, mod(a,b));

}



int main()
{
    //LCG(3,7,11);

/***
    ZZ a(412);
    ZZ b(260);

    double t0, t1;
    t0=clock();
    ZZ t = mcd(a,b);
    t1 = clock();
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("%.30f\n\n", time);

    t0=clock();
    ZZ tt = euclidesmcd(a,b);
    t1 = clock();
    time = (double(t1-t0)/CLOCKS_PER_SEC);
    printf("%.30f\n", time);
    //cout << t << tt;




    return 0;
}
*/
















/*

#include <iostream>
#include <fstream>
#include <sstream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;


ZZ inv(ZZ a, ZZ b) {

	ZZ r, q, x, x1, x2;
	if(b==ZZ(0)) {
		x2=ZZ(1);
		return x2;
	}
	else {
		x1=ZZ(0);
		x2=ZZ(1);
		while(b>ZZ(0)) {
			q = a/b;
			r = a - (q * b);
			x = x2 - (q * x1);
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
		}
		return x2;
	}
}
ZZ mod(ZZ a, ZZ b) {
	ZZ r, q;
	q = a/b;
	r = a-(b*q);
	if(r<ZZ(0)){return r+b;}
	return r;
}

ZZ inv2(ZZ a, ZZ b) {
    ZZ c;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
	ZZ r, q, x, x1, x2;
	if(b==ZZ(0)) {
		x2=ZZ(1);
		cout << "hola ";
		return x2;
	}
	else {
		x1=ZZ(0);
		x2=ZZ(1);
		while(b>ZZ(0)) {
			q = a/b;
			r = a - (q * b);
			x = x2 - (q * x1);
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
		}
		if (x2<ZZ(0)){
                cout <<" exito ";

			x2 += b;
            return x2;
            }
        else
            return x2;
	}
}

int mod(int a, int b) {
	int r, q;
	q = a/b;
	r = a-(b*q);
	if(r<0){return r+b;}
	return r;
}

int Euclides(int a, int b) {
	int r;

	while(b>0) {
		r = mod(a,b);
		a = b;
		b = r;
	}

	return a;
}


ZZ Euclides(ZZ a, ZZ b) {
	ZZ r;

	while(b>ZZ(0)) {
		r = mod(a,b);
		a = b;
		b = r;
	}

	return a;
}

int inv(int a, int b) {
    int c;
    if(a>b){
        c=a;
        a=b;
        b=c;
    }
	int r, q, x, x1, x2;
	if(b==0) {
		x2=1;
		return x2;
	}
	else {
		x1=0;
		x2=1;
		while(b>0) {
			q = a/b;
			r = a - (q * b);
			x = x2 - (q * x1);
			a = b;
			b = r;
			x2 = x1;
			x1 = x;
		}
		if (x2<0)
            return x2+b;
        else
            return x2;
	}
}


int main()
{
    int i=20;
    while(Euclides(72,i) != 1)
    {
        i++;
    }
    	ZZ p;
		ZZ q;
        GenPrime(p,512);
		GenPrime(q,512);
		cout << q << endl << endl;
		cout << p << endl << endl;
		cout << Euclides(p,q) << endl << endl;
		cout << inv(p,q) << endl << endl;
		cout << inv(q,p) << endl << endl;
		cout << inv2(p,q) << endl << endl;
		cout << inv2(q,p) << endl << endl;
    return 0;

////

    ZZ RestoChino(ZZ x1, ZZ p, ZZ x2, ZZ q)
{
    ZZ x1= exp(M,mod(d,p-1),p);///indice palabra correcta
    ZZ x2= exp(M,mod(d,q-1),q); /// igual anterior
	ZZ n = p*q;
		cout << "a1 "<<a1 << endl << endl;
		cout << "a2 "<<a2 << endl << endl;
		cout << "mod "<<mod(a1*inv(p,q)*p,n)+mod(a2*inv(q,p)*q,n)<< endl << endl;
    return mod( mod( x1*inv(p,q)*p, n ) + mod( x2*inv(q,p)*q, n ), n );

}

}
*/
