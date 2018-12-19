//Alejandro García Rico 45927720D
#include <iostream>
#include <vector>
#include <string.h>
#include <limits>
#include "avisoFallo.h"
#include "comentario.h"


using namespace std;

//reportador, producto, version, mensaje

void limpiaPantalla(){
    cout<<"\033[2J\033[1;1H";
}

string inicioSesion(){
    limpiaPantalla();
    string nombreUsuario="";
    cout<<"Introduce el nombre de usuario para acceder al servicio"<<endl;
    cout<<"Nombre : ";
    cin>>nombreUsuario;
    return nombreUsuario;
}

//La opcion devuelta siempre va a ser correcta
int texto_menu(string usuario){
    int opcion_seleccionada=5;
    do{
        limpiaPantalla();
        cout<<"--------------------------------------"<<endl;
        cout<<"           Local Bug Tracker "<<endl;
        cout<<"--------------------------------------"<<endl;
        cout<<endl;
        cout<<"Usuario con sesión iniciada: "<<usuario<<endl;
        cout<<endl;
        cout<<"Selecciona la acción a realizar"<<endl;
        cout<<"1.- Crear nuevo aviso de fallo"<<endl;
        cout<<"2.- Seguimiento de aviso de fallo"<<endl;
        cout<<"3.- Cerrar aviso de fallo"<<endl;
        cout<<"4.- Cambiar de usuario"<<endl;
        cout<<"5.- Salir"<<endl;
        cout<<endl;
        cout<<"Introduce tu opción: ";
        cin>>opcion_seleccionada;

    } while(opcion_seleccionada<1 || opcion_seleccionada>5 );

    return opcion_seleccionada;
    
}


void CreaAviso(string usuario, int idAvisoActual, vector<AvisoFallo> &avisos){
    string continua;
    string nombre_producto="", version_producto="", reporte_producto="";
    cout<<"---------------------------------------"<<endl;
    cout<<"           Crear nuevo aviso"<<endl;
    cout<<"---------------------------------------"<<endl;
    cout<<endl;
    cout<<"El reporte será creado creado por: "<<usuario<<endl;
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');       
    cout<<"Introduce nombre del producto: ";
    getline(cin,nombre_producto);
    cout<<"Introduce la versión del programa: ";
    getline(cin,version_producto);
    cout<<"Especifica en detalle el reporte: ";
    getline(cin,reporte_producto);
    AvisoFallo nuevoAviso =  AvisoFallo(idAvisoActual,usuario,nombre_producto,version_producto,reporte_producto);
    avisos.push_back(nuevoAviso);
    cout<<endl;
    cout<<"AVISO CREADO, pulsa INTRO para regresar al menú";
    cin.get();
}


void anyadeComentarioAviso(string usuario, vector<AvisoFallo> &avisos, int id_equipo){
    string comentario="";
    limpiaPantalla();
        
        for(unsigned int i=0; i<avisos.size(); i++){
            if(avisos[i].id==id_equipo){
                avisos[i].MostrarAviso();

                if(avisos[i].estado==false){
                    cout<<"Este reporte está finalizado y por lo tanto no se pueden añadir más comentarios, pulsa INTRO para regresar al menú"<<endl;
                    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                    cin.get();
                }

                else{
                    cout<<"Añade un comentario a este reporte: ";
                    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
                    getline(cin,comentario);
                    Comentario comentario_post= Comentario(usuario,comentario);
                    avisos[i].comentarios.push_back(comentario_post);
                    cout<<endl;
                    cout<<"Comentario añadido al reporte, pulsa INTRO para regresar al menú";
                    cin.get();
                }
            }
            
        }
}


void finalizaAviso( vector<AvisoFallo> &avisos, int id_equipo){
    limpiaPantalla();
    for(unsigned int i=0; i<avisos.size(); i++){
            if(avisos[i].id==id_equipo){
                avisos[i].MostrarAviso();
                if(avisos[i].estado==false){
                    cout<<endl;
                    cout<<"Este reporte ya está finalizado, pulsa INTRO para regresar al menú";
                }
                else{
                    avisos[i].FinalizarAviso();
                    cout<<endl;
                    cout<<"Pulsa INTRO para finalizar este reporte y regresar al menú";
                }

            }
    }
    cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
    cin.get();
}

void SeguimientoAviso(string usuario, vector<AvisoFallo> &avisos, bool comentar){
    limpiaPantalla();
    unsigned int id_equipo;
    if(avisos.size()==0){
        cout<<"ERROR: No existe ningún aviso actualmente, pulsa INTRO para regresar al menú";
        cin.ignore(std::numeric_limits<streamsize>::max(),'\n');
        cin.get();
    }
    else{
        string estado="ABIERTO";
        string nombre_producto="", version_producto="", reporte_producto="";
        cout<<"---------------------------------------"<<endl;
        cout<<"             Lista de avisos"<<endl;
        cout<<"---------------------------------------"<<endl;
        cout<<endl;
        for(unsigned int i=0; i<avisos.size(); i++){
            if(avisos[i].estado==false){
                estado= "FINALIZADO";
            }
            cout<<"-> ID["<<avisos[i].id<<"] ESTADO["<< estado<<"] PRODUCTO["<<avisos[i].producto<< "] VERSIÓN["<<avisos[i].version<<"]"<<endl;
            cout<<endl; 
        }

        if(comentar==false){
            cout<<"Introduce el ID del aviso en el que desees finalizar ";
        }
        else{
            cout<<"Introduce el ID del aviso en el que desees añadir un comentario: ";
        }
        
        do{
            cin >>id_equipo;
            if(id_equipo<=0 || id_equipo>avisos.size()){
                cout<<"ERROR, No existe ningún aviso con ese ID de quipo, Prueba de nuevo: ";
            }   
        }while(id_equipo<=0 || id_equipo>avisos.size());

        if(comentar==false){
            finalizaAviso(avisos,id_equipo);
        }
        else{
            anyadeComentarioAviso(usuario,avisos,id_equipo);
        }
        
    }
}



int main(){
    string usuario;
    int opcion;
    int idAvisoActual=0;
    vector<AvisoFallo> avisos;
    usuario=inicioSesion();


        do{
            //La opcion recibida siempre será válida
            opcion=texto_menu(usuario);
            
            switch (opcion){
                case 1:
                    limpiaPantalla();
                    idAvisoActual++;
                    CreaAviso(usuario,idAvisoActual,avisos);
                    break;
                case 2:
                    limpiaPantalla();
                    SeguimientoAviso(usuario,avisos,true);
                    break;
                case 3:
                    limpiaPantalla();
                     SeguimientoAviso(usuario,avisos,false);
                    break;
                case 4: //Cambio de usuario
                    usuario=inicioSesion();
                    break;
                default:
                    break;
            }


        }while(opcion!=5);

  

}