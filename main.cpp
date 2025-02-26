#include <cstdlib>
#include <iostream>
#include <bits/stdc++.h>
#include "redneuronal.h"

#include <opencv2/opencv.hpp>
//#include <opencv2/objdetect.hpp>
//#include <opencv2/highgui.hpp>
//#include <opencv2/video.hpp>
//#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;

int main()
{
    srand((unsigned int)time(NULL)); //semilla aleatorea

    //int numCapas = 4;
    //int arqRed[numCapas];
    //arqRed[0]=2;
    //arqRed[1]=4;
    //arqRed[2]=4;
    //arqRed[3]=2;
    //arqRed[4]=1;

    ////Entrada
    //double** x;
    //x =  new double*[4];
    //for (int i = 0; i < 4; i++)
    //    x[i] = new double[2];
    //x[0][0] = 0;
    //x[0][1] = 0;
    //x[1][0] = 0;
    //x[1][1] = 1;
    //x[2][0] = 1;
    //x[2][1] = 0;
    //x[3][0] = 1;
    //x[3][1] = 1;
//
    //double** y;
    //y =  new double*[4];
    //for (int i = 0; i < 4; i++)
    //    y[i] = new double[1];
    //y[0][0] = 0;
    //y[1][0] = 1;
    //y[2][0] = 1;
    //y[3][0] = 0;
//
//
    //RedNeuronal *red = new RedNeuronal(arqRed,numCapas);
    ////double test[2];
    ////test[0] = 1;
    ////test[1] = 0;
    ////red->Prediccion(test);
    ////////cout<<"Después de entrenamento 1"<<endl;
    ////cout<<"Salida sin entrenar: "<<red->a[numCapas-1][0]<<endl;
    ////cout<<endl;
    ////// Entrenamiento
    ////red->Entrenamiento(x,y,4,0.4,1000);
    ////test[0] = 0;
    ////test[1] = 0;
    ////red->Prediccion(test);
    ////cout<<test[0]<<" "<<test[1]<<" = "<<red->a[numCapas-1][0]<<endl;
    ////cout<<endl;
    ////test[0]=0;
    ////test[1]=1;
    ////red->Prediccion(test);
    ////cout<<test[0]<<" "<<test[1]<<" = "<<red->a[numCapas-1][0]<<endl;
    ////cout<<endl;
    ////test[0]=1;
    ////test[1]=0;
    ////red->Prediccion(test);
    ////cout<<test[0]<<" "<<test[1]<<" = "<<red->a[numCapas-1][0]<<endl;
    ////cout<<endl;
    ////test[0]=1;
    ////test[1]=1;
    ////red->Prediccion(test);
    ////cout<<test[0]<<" "<<test[1]<<" = "<<red->a[numCapas-1][0]<<endl;
    ////cout<<endl;
//
    ////red->guardarRed("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/");
//
//
// *//***************************************************** //
//
    ////RedNeuronal *red = new RedNeuronal("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/arqRed.txt",
    ////                                    "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/pesosRed.txt",
    ////                                    "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Models/biasRed.txt" );
    ////////int numCapas = 3;
    //double test[2];
    //test[0] = 0;
    //test[1] = 0;
    //red->Prediccion(test);
    //cout<<"Despues de cargar la red entrenada"<<endl;
    //cout<<test[0]<<" "<<test[1]<<" >> "<<round(red->a[numCapas-1][0])<<endl;
    //std::cout<<std::endl;
////
    ////test[0] = 0;
    ////test[1] = 1;
    ////red->Prediccion(test);
    ////cout<<"Despues de cargar la red entrenada"<<endl;
    ////cout<<test[0]<<" "<<test[1]<<" >> "<<round(red->a[numCapas-1][0])<<endl;
    ////std::cout<<std::endl;
////
    ////test[0] = 1;
    ////test[1] = 0;
    ////red->Prediccion(test);
    ////cout<<"Despues de cargar la red entrenada"<<endl;
    ////cout<<test[0]<<" "<<test[1]<<" >> "<<round(red->a[numCapas-1][0])<<endl;
    ////std::cout<<std::endl;
////
    ////test[0] = 1;
    ////test[1] = 1;
    ////red->Prediccion(test);
    ////cout<<"Despues de cargar la red entrenada"<<endl;
    ////cout<<test[0]<<" "<<test[1]<<" >> "<<round(red->a[numCapas-1][0])<<endl;
    ////std::cout<<std::endl;
//
    //double** Entrada=NULL;
    //double** Sal=NULL;
//
    //Entrada =  new double*[4];
    //for (int i = 0; i < 4; i++)
    //    Entrada[i] = new double[2];
//
    //Sal =  new double*[4];
    //for (int i = 0; i < 4; i++)
    //    Sal[i] = new double[1];
//
//
    //red->LeerDatosEntrenamiento("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/entrada.csv",
    //                            "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/salida.csv",
    //                            Entrada,
    //                            Sal);
    //test[0] = 0;
    //test[1] = 0;
    //red->Prediccion(test);
    //cout<<"Salida ANTES de entrenamiento test: "<<test[0]<<" "<<test[1]<<" = "<<red->a[numCapas-1][0]<<endl;
    //cout<<endl;
//
    //for(int i=0;i<4;i++){
    //    for(int j=0;j<2;j++){
    //        cout<<x[i][j]<<" ";
    //    }
    //    cout<<endl;
    //}
    //cout<<endl;
    //for(int i=0;i<4;i++){
    //    cout<<Sal[i][0]<<" "<<y[i][0]<<endl;
    //}
//
    //// Entrenamiento
    //red->Entrenamiento(Entrada,Sal,4,0.7,300);
//
    //test[0] = 0;
    //test[1] = 0;
    //red->Prediccion(test);
    //cout<<"1) Salida despues de entrenamiento test: "<<test[0]<<" "<<test[1]<<" = "<<round(red->a[numCapas-1][0])<<endl;
    //cout<<endl;
//
    //test[0] = 0;
    //test[1] = 1;
    //red->Prediccion(test);
    //////cout<<"Después de entrenamento 1"<<endl;
    //cout<<"2) Salida despues de entrenamiento test: "<<test[0]<<" "<<test[1]<<" = "<<round(red->a[numCapas-1][0])<<endl;
    //cout<<endl;
//
    //test[0] = 1;
    //test[1] = 0;
    //red->Prediccion(test);
    //////cout<<"Después de entrenamento 1"<<endl;
    //cout<<"3) Salida despues de entrenamiento test: "<<test[0]<<" "<<test[1]<<" = "<<round(red->a[numCapas-1][0])<<endl;
    //cout<<endl;
//
    //test[0] = 1;
    //test[1] = 1;
    //red->Prediccion(test);
    //////cout<<"Después de entrenamento 1"<<endl;
    //cout<<"4) Salida despues de entrenamiento test: "<<test[0]<<" "<<test[1]<<" = "<<round(red->a[numCapas-1][0])<<endl;
    //cout<<endl;
//
    Mat image = cv::imread("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/linux.jpg",
                           CV_8UC2);   // Read the file



    Mat IMAGENchica;
    resize(image, IMAGENchica, Size(680,430));
    //imshow("cvmat", IMAGENchica);                   // Show our image inside it.
    std::vector<double> array;
    if (IMAGENchica.isContinuous()) {
        // array.assign(mat.datastart, mat.dataend); // <- has problems for sub-matrix like mat = big_mat.row(i)
        array.assign(IMAGENchica.data, IMAGENchica.data + IMAGENchica.total()*IMAGENchica.channels());
    } else {
        for (int i = 0; i < IMAGENchica.rows; ++i) {
            array.insert(array.end(), IMAGENchica.ptr<uchar>(i), IMAGENchica.ptr<uchar>(i)+IMAGENchica.cols*IMAGENchica.channels());
        }
    }

    int sizeArray = array.size();

    double** x;
    x =  new double*[sizeArray];
    for (int i = 0; i < sizeArray; i++)
        x[i] = new double[2];


    x[0] = &array[0];

    double** y;
    y =  new double*[1];
    for (int i = 0; i < 1; i++)
        y[i] = new double[1];
    y[0][0] = 0;
    //y[1][0] = 1;
    //y[2][0] = 1;
    //y[3][0] = 0;

    int numCapas = 5;
    int arqRed[numCapas];
    arqRed[0]= sizeArray;
    arqRed[1]=4;
    arqRed[2]=4;
    arqRed[3]=2;
    arqRed[4]=1;

    //waitKey(0);

    RedNeuronal *red = new RedNeuronal(arqRed,numCapas);

    //red->Entrenamiento(x,y,1,0.3,100);

    red->LeerImagenesEntrenamiento("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/Images/",
                                   "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/annotations/",
                                   x,
                                   y);


    delete[] x;

    return 0;
}


