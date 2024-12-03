#include <cstdlib>
#include <iostream>
#include "redneuronal.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL)); //semilla aleatorea


    int numCapas = 3;
    int arqRed[numCapas];
    arqRed[0]=2;
    arqRed[1]=1;
    arqRed[2]=3;
    ////Entrada
    double x[] ={0.05, 0.1};

    //RedNeuronal *red = new RedNeuronal(arqRed,&numCapas);
    //red->Prediccion(x);
    //cout<<"Antes de entrenamiento"<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    //cout<<"Salida 1 de la red: "<<red->a[numCapas-1][1]<<endl;
    //cout<<"Salida 2 de la red: "<<red->a[numCapas-1][2]<<endl;
    //cout<<endl;
    //// Datos de entrenamiento
    //double y[3];
    //y[0]= 0.5;
    //y[1]= 0.1;
    //y[2]= 0.2;
    ////// Entrenamiento
    //red->Entrenamiento(x,y,0.6,500);
    //red->Prediccion(x);
    //cout<<"Después de entrenamiento 1"<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    //cout<<"Salida 1 de la red: "<<red->a[numCapas-1][1]<<endl;
    //cout<<"Salida 2 de la red: "<<red->a[numCapas-1][2]<<endl;
    //cout<<"-----------Se guarda Red------------------"<<endl;
    //cout<<endl;
    //red->guardarRed("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/");
    //red->Mostrar_Pesos_Red();
    //cout<<endl;

    //delete red;


    RedNeuronal *red2 = new RedNeuronal("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/arqRed.txt",
                                        "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/pesosRed.txt",
                                        "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/biasRed.txt" );
    //cout<<"-----------------------------"<<endl;
    //cout<<endl;

    red2->Prediccion(x);
    cout<<"Despues de cargar la red entrenada"<<endl;
    cout<<"Salida 0 de la red2: "<<red2->a[numCapas-1][0]<<endl;
    cout<<"Salida 1 de la red2: "<<red2->a[numCapas-1][1]<<endl;
    cout<<"Salida 2 de la red2: "<<red2->a[numCapas-1][2]<<endl;
    cout<<endl;

    return 0;
}


