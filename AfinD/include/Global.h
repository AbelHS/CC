#ifndef GLOBAL_H
#define GLOBAL_H


#include <iostream>
#include <string>
#include <stdlib.h>     /* srand, rand */
#include <time.h>      /* time */


using namespace std;


int mod(int a, int b);

int inv(int, int);

int generaAle(int);

int ran(int);

void inversa(int, int, int*);
int funcionloca(int plano,  int cifrado, int alfabeto);

int euclidesX(int a, int b);

int mcd(int a, int b);


#endif // GLOBAL_H
