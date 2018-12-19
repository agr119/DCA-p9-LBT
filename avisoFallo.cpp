//Alejandro García Rico 45927720D

#include "avisoFallo.h"
#include "comentario.h"
#include <string.h>
#include <vector>
#include <string.h>

AvisoFallo::AvisoFallo(int id, string usuario_reportador, string producto,string version,string reporte){
    time_t now=time(0);
    string dt = ctime(&now);
    this->id = id;
    this->usuario_reportador = usuario_reportador;
    this->producto = producto;
    this->version = version;
    this->reporte = reporte;
    //Siempre se creará como abierto
    this->estado = true;
    this->fecha = dt;
}

 void AvisoFallo::AnyadeComentario(Comentario comentario){
    comentarios.push_back(comentario);
 }
    
void AvisoFallo::FinalizarAviso(){
   this->estado = false;
};
void AvisoFallo::MostrarAviso(){
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<"                 Producto:"<<producto<<"      Versión:"<<version<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"- Fallo reportado por: "<<usuario_reportador<<endl;
    cout<<"- Reporte abierto desde : "<<fecha;
    cout<<"- Estado del reporte: ";
    if(estado==true){
        cout<<"Abierto"<<endl;
    }
    else{
        cout<<"Finalizado"<<endl;
    }
    cout<<"- Reporte: "<<reporte<<endl;
    cout<<endl;cout<<endl;
    cout<<"----------------------------------------------------------------------------"<<endl;
  
    else{
        cout<<"                       Comentarios sobre este reporte"<<endl;
        cout<<"----------------------------------------------------------------------------"<<endl;
	cout<<endl;
        for(unsigned int i=0;i<comentarios.size();i++){
            comentarios[i].mostarComentario();
            cout<<endl;
        }
     cout<<"----------------------------------------------------------------------------"<<endl;
    }    
};
