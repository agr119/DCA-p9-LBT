//Alejandro García Rico 45927720D

#ifndef _avisofallo_
#define _avisofallo_

#include <iostream>
#include "comentario.h"
#include <vector>
#include <string.h>
#include <ctime>

using namespace std;

class AvisoFallo{
    public:
    int id;
    //Cuando el estado es true el aviso sigue abierto, cuando es false ya no se puede comentar
    bool estado;
    string usuario_reportador;
    string producto;
    string version;
    string reporte;
    string fecha;
    vector<Comentario> comentarios;
    AvisoFallo(int id,string usuario_reportador, string producto,string version,string reporte);
    void AnyadeComentario(Comentario comentario);
    void FinalizarAviso();
    void MostrarAviso();
};


#endif