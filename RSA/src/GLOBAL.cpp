#include "GLOBAL.h"


string convertirSZZ(ZZ entero)
{   string cadena;
    stringstream convert;
    convert << entero;
    cadena = convert.str(); ///asigna cadena Al contenido del flujo
    return cadena;
}

string convertirSINT(int entero)
{   string cadena;
    stringstream convert;
    convert << entero;
    cadena = convert.str(); ///asigna cadena Al contenido del flujo
    return cadena;
}

int convertirZZ(ZZ entero)
{
    int temp;
    conv(temp, entero);
    return temp;
}

ZZ convertirINT(int entero)
{
    ZZ temp;
	conv(temp, entero);
	return temp;
}

ZZ mod(ZZ a, ZZ b)
{
	ZZ r, q;
	q = a/b;
	r = a-(b*q);
	if(r<ZZ(0)){return r+b;}
	return r;
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
	ZZ p(INIT_VAL, cadena.c_str()); ///Devuelve un puntero a s
	return p;
}
