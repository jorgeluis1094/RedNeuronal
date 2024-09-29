#include <cstdlib>
#include <iostream>
#include "redneuronal.h"

using namespace std;

int main()
{
    srand((unsigned int)time(NULL)); //semilla aleatorea

    //int* arqRed;
    //int numCapas = 3;
//
    //arqRed[0]=2;
    //arqRed[1]=3;
    //arqRed[2]=3;
//
    //RedNeuronal *red = new RedNeuronal(arqRed,&numCapas);
//
    ////Entrada
    //double x[] ={0.05, 0.1};
    //red->Prediccion(x);
    //cout<<"Antes de entrenamiento"<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    //cout<<"Salida 1 de la red: "<<red->a[numCapas-1][1]<<endl;
    //cout<<"Salida 2 de la red: "<<red->a[numCapas-1][2]<<endl;
    //cout<<endl;
    ////datos de entrenamiento
    //double y[3];
    //y[0]= 0.5;
    //y[1]= 0.5;
    //y[2]= 0.1;
//
    //// Entrenamiento
    //red->Entrenamiento(x,y,0.6,300);
    //red->Prediccion(x);
    //cout<<"Después de entrenamiento 1"<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][1]<<endl;
    //cout<<"Salida 0 de la red: "<<red->a[numCapas-1][2]<<endl;
    //cout<<endl;
//
    //red->guardarRed();

    int numCapas = 3;
    RedNeuronal *red = new RedNeuronal("arqRed.txt","pesosRed.txt");
    ////Entrada
    double x[] ={0.05, 0.1};
    red->Prediccion(x);
    cout<<"Antes de entrenamiento"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<"Salida 1 de la red: "<<red->a[numCapas-1][1]<<endl;
    cout<<"Salida 2 de la red: "<<red->a[numCapas-1][2]<<endl;
    cout<<endl;
    //datos de entrenamiento
    double y[3];
    y[0]= 0.5;
    y[1]= 0.5;
    y[2]= 0.1;

    // Entrenamiento
    red->Entrenamiento(x,y,0.6,300);
    red->Prediccion(x);
    cout<<"Después de entrenamiento 1"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][1]<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][2]<<endl;


    return 0;
}


