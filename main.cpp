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


    std::vector<std::vector<double>> x;
    std::vector<std::vector<double>> y;


    //int width = 128;
    //int height = 128;
    //int chanel = 1;
    //int sizeArray = width*height*chanel;


      // construye una red a partir de una red que anteriormente fue creada y guardada en los archivos en cuestion
//    RedNeuronal *red = new RedNeuronal("/home/lynx/Documentos/Code/RedNeuronal/Models/arqRed.txt",
//                                       "/home/lynx/Documentos/Code/RedNeuronal/Models/pesosRed.txt",
//                                       "/home/lynx/Documentos/Code/RedNeuronal/Models/pesosRed.txt");

    // se crea una red con dos entradas, una capa oculta con dos neuronas y capa de salida con una salida [2,2,1]
    std::vector<int> arqRed;
    arqRed.push_back(2);
    arqRed.push_back(2);
    arqRed.push_back(1);

    int numCapas = arqRed.size();

    // Crea una red a partir de la arquitectura definida en arqRed
    RedNeuronal *red = new RedNeuronal(arqRed,arqRed.size());

    // Lee datos para realizar un entrenamiento, tanto los X como el Y está en el archivo datos.csv, la función entrega los vectores con los datos diligenciados
    red->LeerDatosEntrenamiento("/home/lynx/Documentos/Code/RedNeuronal/Data/datos.csv",
                                 x,
                                 y);

    //Parametriza el entrenamiento dando los datos de entrada y salida. Se parametriza el paso de entrenamiento y la cantidad de epocas
    red->Entrenamiento2(x,y,0.1,100);

    // La red entrenada del ejemplo se realizó para simular una compuesta OR entonces se validan los casos
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

    return 0;
}


