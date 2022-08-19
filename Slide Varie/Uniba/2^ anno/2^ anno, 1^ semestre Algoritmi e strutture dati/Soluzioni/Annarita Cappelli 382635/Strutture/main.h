/*
Autore: Annarita Cappelli 
Matricola: 382635
Nome file: main.h
Commento: Direttive al pre-processore e definizioni varie.
*/

#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

#include <sys/types.h>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define _gerr(x) { fputs(x, stderr); system("pause"); exit(-1); }

#endif
