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
    arqRed[1]=2;
    arqRed[2]=1;
    //arqRed[3]=1;

    ////Entrada

    double** x;

    x =  new double*[4];
    for (int i = 0; i < 4; i++)
        x[i] = new double[2];

    x[0][0] = 0;
    x[0][1] = 0;

    x[1][0] = 1;
    x[1][1] = 0;

    x[2][0] = 0;
    x[2][1] = 1;

    x[3][0] = 1;
    x[3][1] = 1;

    double** y;
    y =  new double*[4];
    for (int i = 0; i < 4; i++)
        y[i] = new double[1];

    y[0][0] = 0;
    y[1][0] = 1;
    y[2][0] = 1;
    y[3][0] = 1;


    RedNeuronal *red = new RedNeuronal(arqRed,numCapas);
    double test[2];

    test[0] = 1;
    test[1] = 0;
    red->Prediccion(test);
    ////cout<<"Después de entrenamento 1"<<endl;
    cout<<"Salida 0 sin entrenar: "<<red->a[numCapas-1][0]<<endl;
    ////cout<<"Salida 1 sin entrenar: "<<red->a[numCapas-1][1]<<endl;

    // Entrenamiento
    red->Entrenamiento(x,y,4,0.6,2500);


    test[0] = 0;
    test[1] = 0;
    red->Prediccion(test);
    cout<<"Después de entrenamento uno"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<endl;


    test[0]=1;
    test[1]=0;
    red->Prediccion(test);
    cout<<"Segunda predicción de entrenamento uno"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<endl;

    test[0]=0;
    test[1]=1;
    red->Prediccion(test);
    cout<<"tercera predicción de entrenamento uno"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<endl;

    test[0]=1;
    test[1]=1;
    red->Prediccion(test);
    cout<<"cuarta predicción de entrenamento uno"<<endl;
    cout<<"Salida 0 de la red: "<<red->a[numCapas-1][0]<<endl;
    cout<<endl;
//
//
//
    ////cout<<"Salida 2 de la red: "<<red->a[numCapas-1][2]<<endl;
    ////cout<<"-----------Se guarda Red------------------"<<endl;
    ////cout<<endl;
    ////red->guardarRed("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/");
    ////red->Mostrar_Pesos_Red();
    //cout<<endl;

    //double x[] ={0, 0};
    ////red->Prediccion(x);
//
    //red->Entrenamiento( "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/entrada.csv",
    //                    "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/salida.csv",
    //                    4,
    //                    0.01,
    //                    4);
//
    //red->Mostrar_Pesos_Red();
    //red->Mostrar_b();
//

    //x[4][2] ={{0, 0},{0, 1},{1, 0},{1, 1}};
    //x[0][0] = 0;
    //x[0][1] = 0;
//
    //x[1][0] = 0;
    //x[1][1] = 1;
//
    //x[2][0] = 1;
    //x[2][1] = 0;
//
    //x[3][0] = 0;
    //x[3][1] = 0;
//
    //double test[2];
    //test[0]=0;
    //test[1]=0;
//
//
    //red->Prediccion(test);
    //cout<<"Salida caso 0 de la red: "<<red->a[numCapas-1][0]<<endl;
//
    //test[0]=0;
    //test[1]=1;
    //red->Prediccion(test);
    //cout<<"Salida caso 1 de la red: "<<red->a[numCapas-1][0]<<endl;
//
    //test[0]=1;
    //test[1]=0;
    //red->Prediccion(test);
    //cout<<"Salida caso 2 de la red: "<<red->a[numCapas-1][0]<<endl;
//
    //test[0]=1;
    //test[1]=1;
    //red->Prediccion(test);
    //cout<<"Salida caso 3 de la red: "<<red->a[numCapas-1][0]<<endl;
    //////red->Mostrar_a_Red();
    //cout<<endl;
////
    //double x_2[2];
    //x_2[0] = 10;
    //x_2[1] = -0.11;
    //red->Prediccion(x_2);
    //cout<<"Salida caso 0 de la red_2: "<<red->a[numCapas-1][0]<<endl;
    ////cout<<"Salida caso 1 de la red_2: "<<red->a[numCapas-1][1]<<endl;
//
    //cout<<endl;
    ////red->Mostrar_Pesos_Red();
    ////red->Mostrar_b();
    //cout<<endl;
    //red->Prediccion(x);
    //cout<<"Salida caso 2 de la red: "<<red->a[numCapas-1][0]<<endl;

    //x[0] = 0.1;
    //x[1] = 0.0;
    //red->Prediccion(x);
    //cout<<"Salida caso 3 de la red: "<<red->a[numCapas-1][0]<<endl;
    ////red->Mostrar_a_Red();
    //cout<<endl;
//
    //x[0] = 0.1;
    //x[1] = 0.1;
    //red->Prediccion(x);
    //cout<<"Salida caso 4 de la red: "<<red->a[numCapas-1][0]<<endl;
    ////red->Mostrar_a_Red();
    ////delete red;


    //RedNeuronal *red2 = new RedNeuronal("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/arqRed.txt",
    //                                    "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/pesosRed.txt",
    //                                    "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/biasRed.txt" );
//
//
    //red2->Prediccion(x);
    //cout<<"Despues de cargar la red entrenada"<<endl;
    //cout<<"Salida 0 de la red2: "<<red2->a[numCapas-1][0]<<endl;
    //cout<<"Salida 1 de la red2: "<<red2->a[numCapas-1][1]<<endl;
    //cout<<"Salida 2 de la red2: "<<red2->a[numCapas-1][2]<<endl;
    //cout<<endl;

    //double** Entrada=NULL;
    //double Sal[4];
    //Entrada =  new double*[4];
    //for (int i = 0; i < 4; i++)
    //    Entrada[i] = new double[2];
    //red2->LeerDatosEntrenamiento("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/entrada.csv",
    //                             "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/salida.csv",
    //                             Entrada,
    //                             Sal);
//

//

    return 0;
}


