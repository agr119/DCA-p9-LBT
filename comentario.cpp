//Alejandro García Rico 45927720D

#include "comentario.h"
#include <string.h>


Comentario::Comentario(string usuario_comenta, string texto){
    time_t now=time(0);
    string dt = ctime(&now);
    this->usuario_comenta=usuario_comenta;
    this->texto=texto;
    this->fecha=dt;

}

 void Comentario::mostarComentario(){
     cout<<"USUARIO: "<<usuario_comenta<<" FECHA: "<<fecha;
     cout<<"COMENTARIO: "<<texto<<endl;
 }