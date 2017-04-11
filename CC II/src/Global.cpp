#include "Global.h"


int mod(int a, int b) {
	int r, q;
	q = a/b;
	r = a-(b*q);
	if(r<0){return r+b;}
	return r;
}


int ran(int len) {
	srand(time(NULL)); ///evitamos que se repita alguna secuencia
	//int r = 1+(rand()%len);
	int r = mod(rand(),len);
	return r;
}


int generaAle(int len)
{
    int i = ran(len);
    while (mcd(i,len)!=1)
    {
        i = ran(len);
    }
    return i;
}


int inversa(int a, int b) {
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
		return x2;
	}
}
/*
void inversa(int a, int b, int *x)
{
    int q, r, x1, x2;

    if(b == 0)
    x2 = 1;

    x2 = 1, x1 = 0;
    while (b > 0){
        q = a / b, r = a - q * b;
        *x = x2 - q * x1;
        a = b, b = r;
        x2 = x1, x1 = *x;
    }
    *x = (x2<0)? mod(x2,27) : x2;
}

*/
int inv(int a, int b) {

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
		return x2;
	}
		}
int funcionloca(int plano,  int cifrado, int alfabeto)
{
    //int plano = 3;
    //int cifrado = 21;
    //int alfabeto = 26;
    int m=0; ///sera igual a la publica
    int privada=1;
    int temp; ///numero multiplicado cifradoXprivado

    while(m !=plano)
    {
        ++privada;
        temp = cifrado*privada;
        m = mod(temp, alfabeto);
    }
    return privada;
}


int euclidesX(int a, int b)
{
    int r1 = a, r2 =b;
    int s1 = 1, s2 =0;
    int t1 = 0, t2 =1;
    int q, r, s, t;
    while (r2>0)
    {
        q = r1/r2;

        r = mod(r1 ,r2);
        //r = r1-q*r2;
        r1 = r2;
        r2 = r;

        s = s1-q*s2;
        s1 = s2;
        s2 = s;

        t = t1-q*t2;
        t1 = t2;
        t2 = t;
    }
    cout << " valor y "<< t1;
    return s1;
}

int mcd(int a, int b)
{
    int _a = a;
    int _b = b;
    int r = mod(_a,_b);
    while(r>0)
    {   _a = _b;
        _b = r;
        r = mod(_a,_b);
    }
    return _b;
}

void extended_euclid(long a, long b, long *x)
{
    long q, r, x1, x2;

    if(b == 0)
    x2 = 1;

    x2 = 1, x1 = 0;
    while (b > 0){
        q = a / b, r = a - q * b;
        *x = x2 - q * x1;
        a = b, b = r;
        x2 = x1, x1 = *x;
    }
    *x = (x2<0)? mod(x2,27) : x2;
}

