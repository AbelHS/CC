#ifndef GLOBAL_H
#define GLOBAL_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;

ZZ mod(ZZ a, ZZ b);

ZZ euclides(ZZ a, ZZ b);

ZZ inv(ZZ a, ZZ b);

ZZ exponenciacion(ZZ a, ZZ e, ZZ m);

ZZ string_ZZ(string);

string convertirSZZ(ZZ entero);

string convertirSINT(int entero);

ZZ convertirINT(int entero);

int convertirZZ(ZZ entero);

#endif // GLOBAL_H
