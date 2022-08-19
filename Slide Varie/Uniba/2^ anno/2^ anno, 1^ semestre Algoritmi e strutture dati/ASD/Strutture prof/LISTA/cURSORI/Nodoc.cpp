



#include "Nodoc.h"


Nodoc::Nodoc(){Nodoc::succ=-1;};

Nodoc::~Nodoc(){};

tipoelem Nodoc::leggivalore(){return valore;};

void Nodoc::scrivivalore(tipoelem x){valore=x;};

int Nodoc::leggisucc(){return succ;};

void Nodoc::scrivisucc(int x){succ=x;};

