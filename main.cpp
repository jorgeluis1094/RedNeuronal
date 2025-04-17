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

    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> y;


    int width = 128;
    int height = 128;
    int chanel = 1;
    int sizeArray=width*height*chanel;


    //int arqRed[numCapas];
    //arqRed[0]= sizeArray;
    //arqRed[1]=25;
    //arqRed[2]=20;
    //arqRed[3]=15;
    //arqRed[4]=10;
    //arqRed[5]=8;
    //arqRed[6]=7;
    //arqRed[7]=6;
    //arqRed[8]=5;
    //arqRed[9]=4;

    std::vector<int> arqRed;
    //arqRed.push_back(sizeArray);
    arqRed.push_back(2);
    arqRed.push_back(2);
    arqRed.push_back(1);
    //arqRed.push_back(2);

    int numCapas = arqRed.size();


//    RedNeuronal *red = new RedNeuronal("/home/lynx/Documentos/Code/RedNeuronal/Models/arqRed.txt",
//                                       "/home/lynx/Documentos/Code/RedNeuronal/Models/pesosRed.txt",
//                                       "/home/lynx/Documentos/Code/RedNeuronal/Models/pesosRed.txt");




    RedNeuronal *red = new RedNeuronal(arqRed,arqRed.size());

    red->LeerDatosEntrenamiento("/home/lynx/Documentos/Code/RedNeuronal/Data/datos.csv",
                                 x,
                                 y);

    red->Entrenamiento2(x,y,0.01,500);


    //red->Mostrar_a_Red();
    //cout<<endl;

    double test[2];
    test[0] = 0;
    test[1] = 0;
    red->Prediccion(test);
    cout<<red->a[numCapas-1][0]<<std::endl;


    test[0] = 1;
    test[1] = 0;
    red->Prediccion(test);
    cout<<red->a[numCapas-1][0]<<std::endl;

    test[0] = 0;
    test[1] = 1;
    red->Prediccion(test);
    cout<<red->a[numCapas-1][0]<<std::endl;

    test[0] = 1;
    test[1] = 1;
    red->Prediccion(test);
    cout<<red->a[numCapas-1][0]<<std::endl;

    //red->Mostrar_a_Red();
    //cout<<endl;





    //red->LeerImagenesEntrenamiento("/home/lynx/Documentos/Code/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/ImagenesMuestra/",
    //                               "/home/lynx/Documentos/Code/RedNeuronal/Data/OD-WeaponDetection/Knife_detection///annotationsMuestra/",
    //                               x,
    //                               y);

    //red->Entrenamiento2(x,y,1,0.01,20);
    //red->guardarRed("/home/lynx/Documentos/Code/RedNeuronal/Models/");


    //string rutaTest = "/home/lynx/Documentos/Code/RedNeuronal/Data/OD-WeaponDetection/Knife_detection/Images/DSC_0006.JPG";
    //std::vector<std::vector<double>> xTest;
    //std::vector<std::vector<double>> yTest;
    //cv::Mat imageOrig = cv::imread(rutaTest,cv::IMREAD_COLOR);   // Read the file
    //cv::Mat imageResize;
    //cv::resize(imageOrig, imageResize, cv::Size(width,height));
    //cv::Mat image = imageResize.clone();
    //image.convertTo(image, CV_64F);
    //image = image/255;
    //cv::Mat plano = image.reshape(1, 1);
    //std::vector<double> vectorImagen(plano.ptr<double>(), plano.ptr<double>() + plano.cols*plano.rows);
    //xTest.push_back(vectorImagen);
//  //  //cout<<red->a[numCapas-1][0]<<" "<<red->a[numCapas-1][1]<<" "<<red->a[numCapas-1][2]<<" "<<red->a[numCapas-1][3];
    //red->Prediccion(xTest[0].data());
    //yTest.push_back({ red->a[numCapas-1][0], red->a[numCapas-1][1], red->a[numCapas-1][2], red->a[numCapas-1][3]});
    //for (size_t i = 0; i < xTest.size(); ++i) {
    //    //const std::vector<double>& vectorImagenTest = imageResize;//xTest[i];
    //    const std::vector<double>& etiqueta = yTest[i];
    //    // Dibujar la caja
    //    cv::Point pt1(etiqueta[0] * width, etiqueta[1] * height);
    //    cv::Point pt2(etiqueta[2] * width, etiqueta[3] * height);
    //    cv::rectangle(imageResize, pt1, pt2, cv::Scalar(0, 255, 0), 1);
    //    // Mostrar
    //    cv::imshow("Imagen con bounding box", imageResize);
    //    cv::waitKey(0);
    //}
    //cv::destroyAllWindows();

    return 0;
}


