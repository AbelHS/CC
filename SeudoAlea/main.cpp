#include <fstream>
//#include <sstream>
#include <stdio.h>
#include <NTL/ZZ.h>

#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */
#include <vector>
#include <windows.h>

using namespace std;
using namespace NTL;

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

/*
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
*/
vector<int> binarizador(int n)///recibe entero  retorna vector booleano que representa
{
    vector<int> tempo;
    while(n>0){
        tempo.insert(tempo.end(),n%2);
        n>>=1;
        cout <<tempo[x];
        x++;
    }
    return tempo;
}

ZZ bi_ZZ(vector<int> b)///recibe vector booleano retorna ZZ que representa
{
    ZZ resultado = ZZ(0);
    ZZ parcial = ZZ(1);
    if(b[0]==1)
        resultado = ZZ(1);
    for(int i=1; i<b.size(); i++)
    {
        parcial<<=1;
        if(b[i]==1){
            resultado +=parcial;
        }
    }
    return resultado;
}

int nBit(int entero)
{
    int t=0;
    while(entero>0){
        entero>>=1;
        t++;}
    return t;
}

int Bit_Int(int entero)
{
    int t=1;
    while(entero>1){
        t<<=1;
        entero--;}
    return t;
}

ZZ INT_ZZ(int entero)
{
    ZZ temp;
	conv(temp, entero);
	return temp;
}

/*
//alea debe ser multiplo de semilla
ZZ SeudoAle(int semilla, int alea, int particiones, int vueltas)
{
    ZZ resultado = ZZ(0);
    int saltos = particiones/2;
    int parcial = Bit_Int(alea);
    int repeticiones = particiones;
    int D = nBit(semilla);
    int I = 2*D;
    int temp=0;

    cout << parcial <<endl;

    for(int i=1; i<vueltas+1; i++){
        for(int j=0; j<particiones; j++){
        temp=0;
        D *=i; ///indice acarreo Derecha

    cout << " go " <<endl;
        if(repeticiones%2)
        {
            //temp = (semilla<<D-1);
            temp = D-1;
            parcial = (semilla<<temp)&(semilla<<random(semilla));

    cout << temp <<endl;

        }
        else
        {
            ///pn = n<<nn;
            temp = I;
            parcial = (semilla<<temp)&(semilla<<random(semilla));

    cout << temp <<endl;

        }
        I +=semilla;///indice acarreo Izquierda
        repeticiones--;
        }
    }
    resultado = INT_ZZ(parcial);
    //cout << parcial <<endl;
    return resultado;
}
*/




/***
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



    //for(int h=0; h<alea; h++)
       // cout << X[h]<< endl;

    return X;

}
*/

int bin(int n)
{
    int i = 0;
    int t = n>>i;
    cout << t;
    int temp;
    while(t>0){i++;
        temp = t&1;
        t = n>>i;
        cout << temp;
        }
    return temp;
}

void bin_(int &b, int p)
{
    while(p>1)
    {
        b<<=1;
        p--;
    }
}



//alea debe ser multiplo de semilla
///alea debe ser multiplo de particiones
ZZ SeudoAle(int semilla, int alea, int particiones, int vueltas)
{
    ZZ resultado = ZZ(0);
    int saltoD = alea/particiones;
    int saltoI = alea/particiones;

    int parcial = Bit_Int(alea);
    int repeticiones = particiones;
    int D = nBit(semilla);
    int I = 2*D;
    int temp=0;

    cout << parcial <<endl;

    //for(int i=1; i<vueltas+1; i++){
        for(int j=0; j<particiones; j++){
        //temp=0;
        //D *=i; ///indice acarreo Derecha

        if(repeticiones%2==0)///si impar D
        {
            temp = saltoD-1;
            //saltoD+=saltoD;

            //parcial = (semilla<<temp)&(semilla<<random(semilla));

        cout <<" + "<< temp <<endl;

        }
        else///par I
        {
            temp = saltoI;

            //parcial = (semilla<<temp)&(semilla<<random(semilla));

        cout <<" - "<< temp <<endl;

        }
        //I +=semilla;///indice acarreo Izquierda
        if(repeticiones%2==0)
            saltoI = ;
        else
            saltoD = ;
        repeticiones--;
        }
    //}
    resultado = INT_ZZ(parcial);
    //cout << parcial <<endl;
    return resultado;
}


int main()
{



    /*
    for(int i=0; i<7; i++){
            int t = n>>i;
        int temp = t&1;
        cout << temp ;
        }
    */

    //int n = Bit_Int(16);
    //cout << Bit_Int(32) <<endl;
    //binarizador(Bit_Int(16));
    int nn =2;
    int n =8;
    int pn;
    pn = n>>nn;
    bin_(nn,3);
    //bin(4);
    //cout << nn;
    //cout <<endl<<bin(4)<<endl;

    cout <<endl<<SeudoAle(2,16,4,8);
    return 0;
}
