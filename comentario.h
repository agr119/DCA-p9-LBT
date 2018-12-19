//Alejandro García Rico 45927720D

#ifndef _comentario_
#define _comentario_

#include <iostream>
#include <vector>
#include <string.h>
#include <ctime>

using namespace std;

class Comentario{
    public:
    string usuario_comenta;
    string texto;
    string fecha;
    Comentario(string usuario_comenta, string texto);
    void mostarComentario();
};


#endif