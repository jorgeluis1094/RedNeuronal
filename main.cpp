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
    //Mat image = cv::imread("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/linux.jpg",CV_8UC2);   // Read the file
    //Mat IMAGENchica;
    //resize(image, IMAGENchica, Size(250,250));
    //imshow("cvmat", IMAGENchica);                   // Show our image inside it.
    //waitKey(0);
    //std::vector<double> array;
    //if (IMAGENchica.isContinuous()) {
    //    // array.assign(mat.datastart, mat.dataend); // <- has problems for sub-matrix like mat = big_mat.row(i)
    //    array.assign(IMAGENchica.data, IMAGENchica.data + IMAGENchica.total()*IMAGENchica.channels());
    //} else {
    //    for (int i = 0; i < IMAGENchica.rows; ++i) {
    //        array.insert(array.end(), IMAGENchica.ptr<uchar>(i), IMAGENchica.ptr<uchar>(i)+IMAGENchica.cols*IMAGENchica.channels());
    //    }
    //}


    int sizeArray = 250*250*3;//array.size();
    int numImages = 4;
    //Mat **x;
    //x = new Mat*[numImages];
    //for (int i = 0; i < numImages; i++)
    //    x[i] = new Mat[sizeArray];
    //
    ////x[0] = &array[0];

    vector<Mat> x;

    double **y;
    y =  new double*[numImages];
    for (int i = 0; i < numImages; i++)
        y[i] = new double[4];
    //y[0][0] = 0;
    //y[1][0] = 1;
    //y[2][0] = 1;
    //y[3][0] = 0;
    int numCapas = 5;
    int arqRed[numCapas];
    arqRed[0]= sizeArray;
    arqRed[1]=4;
    arqRed[2]=4;
    arqRed[3]=2;
    arqRed[4]=4;



    //cout<<"puntero paso 1 "<<x<<endl;
    RedNeuronal *red = new RedNeuronal(arqRed,numCapas);
    red->LeerImagenesEntrenamiento("/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/ImagesMuestra/",
                                   "/home/jorge/Documentos/Programacion/Cplusplus/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/annotationsMuestra//",
                                   &x,
                                   y);
    //Mat restored;
    //for(int j=0;j<numImages;j++){
    //    //Mat chn[] = {
    //    //    Mat(250, 250, CV_8UC1, x[j] ),
    //    //    Mat(250, 250, CV_8UC1, x[j] + 250*250),
    //    //    Mat(250, 250, CV_8UC1, x[j] + 250*250*2)
    //    //};
    //    //
    //    //merge(chn,3,restored);
    //    //cv::Mat restored = cv::Mat(250, 250, CV_8UC3 , x.pop_back);
    //
    //    //Rect rect(y[0][j]*250,y[1][j]*250,(y[2][j]-y[0][j])*250,(y[3][j]-y[1][j])*250);
    //    //rectangle(restored,rect,Scalar(0, 255, 0));
    //    namedWindow("reconstructed", WINDOW_AUTOSIZE);
    //    restored = x.pop_back();
    //    imshow("reconstructed", restored);
    //    waitKey(0);
    //}

    int j=0;
    for(auto i:x){
        Rect rect(y[0][j]*250,y[1][j]*250,(y[2][j]-y[0][j])*250,(y[3][j]-y[1][j])*250);
        rectangle(i,rect,Scalar(0, 255, 0));
        namedWindow("reconstructed", cv::WINDOW_AUTOSIZE);//imprimir los valores cargados de las imagenes i recorre las
        imshow("reconstructed", i);//for (int i=0; i< 4; i++){
        j++;
        waitKey(0);//    std::cout<<"*************************************************"<<std::endl<<std::endl;
   }



    ////imprimir los valores cargados de las imagenes i recorre las imagenes y j los datos de las imagenes
    //for (int i=0; i< 1; i++){
    //    std::cout<<"*************************************************"<<std::endl<<std::endl;
    //    for(int j=0; j<250*250*3;j++){
    //        std::cout<<j<<": "<<x[i][j]<<" "; //i=imagen j=datos de la imagen
    //    }
    //}

    //std::cout<<" "<<x[0][0]<<" "; //i=imagen j=datos de la imagen

    // con i recorreo las imagenes, con j recorre las caracteristicas de cada imagen
    //for (int i=0; i< 2078; i++){
    //    std::cout<<i<<" *************************************************"<<std::endl<<std::endl;
    //    for(int j=0; j<4;j++){
    //        std::cout<<j<<": "<<y[j][i]<<" "; //i=imagen j=datos de la imagen
    //    }
    //}

    //red->Entrenamiento2(x,y,1,0.3,100);

    //delete[] x;
    delete[] y;

    return 0;
}


