/**
 * Version: 0.1
 * Fecha: 21/09/2024
 *
 * Esta libreria permite la creación de una red neuronal multicapa, se debe especificar la arquitectura con el
 * el número de capas que tiene la red y la cantidad de neuronas por capa. La libreria permite:
 * 1. Crear una red indicando su arquitectra y cantidad de capas
 * 2. Entrenar la red
 * 3. Realizar predicciones con la red
 * 4. Guardar la red mediante archivos txt con sus pesos y arquitectura
 * 5. Cargar una red a partir de una red guardada
 *
 * Autor: Jorge Enriquez
 * Correo: jorgeluis1094@gmail.com
 * Tipo de licencia: GPLv3
 *
 **/

#include "redneuronal.h"
#include <iostream>
#include <bits/stdc++.h>

/*
 * Constructor de red neuronal.
 * Parámetros de entrada:
 *      int* arquitecturaRed -> puntero a arreglo, el arreglo debe tener la forma [2,3,3], esto:
 *      capa de entrada con dos (2) puntos
 *      capa intermendia con tres (3) neuronas
 *      capa de salida con tres (3) salidas
 * Salida:
 *      No genera salida, crea una red bajo los parámetros de ingreso
 */
RedNeuronal::RedNeuronal(int* arquitecturaRed, int* numCapas){

    this->arquitecturaRed = arquitecturaRed;
    this->numCapas = *numCapas;
    this->num_Matriz_W = *numCapas-1;

    crearMatrizW();
    PreDiligenciarW(); //Pesos W

    crearArrayB();
    PrediligenciarB(); //bias

    crearMatriz_a();
}


/*
 * Constructor de red neuronal.
 * Parámetros de entrada:
 *      std::string string_arqRed -> string con la ruta y nombre del archivo donde se presenta la arquitectura de la red
 *      std::string pesosRed -> string con la ruta y nombre del archivo donde se presentan los pesos de la red
 * Salida:
 *      No genera salida, crea una red bajo los parámetros de ingreso
 */
RedNeuronal::RedNeuronal(std::string string_arqRed, std::string pesosRed, std::string string_biasRed)
{
    std::ifstream ReadmyFile(string_arqRed);
    //Si no lee correctamente el archivo informa de un error
    if(!ReadmyFile.is_open()) throw std::runtime_error("Could not open file");
    std::string line;
    int numCapas=0;
    if(ReadmyFile.good()){
        // Read data, line by line
        while(getline(ReadmyFile, line,',')){
            numCapas++;
        }
    }
    ReadmyFile.close();
    ReadmyFile.open(string_arqRed);
    int *arqRed = new int[numCapas];
    int i=0;
    while(getline(ReadmyFile, line,',')){
        *(arqRed+i) = stoi(line);
        i++;

        //std::cout<<line<<" ";
    }
    ReadmyFile.close();


    ReadmyFile.open(string_biasRed);
    double *biasRed = new double[numCapas-1];
    i=0;
    while(getline(ReadmyFile, line,',')){
        *(biasRed+i) = stod(line);
        i++;

        //std::cout<<line<<" ";
    }
    ReadmyFile.close();



    this->arquitecturaRed = arqRed;
    this->numCapas = numCapas;
    this->num_Matriz_W = numCapas-1;

    crearMatrizW();
    //PreDiligenciarW(); //Pesos W
    crearArrayB();
    //PrediligenciarB(); //bias
    crearMatriz_a();
    //PreDiligenciar_a(); //asignar memoria pasa matriz a

    cargarRed(pesosRed);
    this->b = biasRed;

}

/*
 * Crea un puntero a matrices para almacenar los pesos de la red entre las diferentes capas
 */
void RedNeuronal::crearMatrizW()
{
    // Reservar memoria de W
    W = new double **[this->num_Matriz_W]; //matrices de pesos. numCapas-1 para el ejemplo 3 matrices W
    for(int i=0; i<this->num_Matriz_W;i++)
    {
        this->W[i] = new double*[arquitecturaRed[i]]; //fila
        for (int j = 0; j < arquitecturaRed[i]; j++)
            this->W[i][j] = new double[arquitecturaRed[i+1]]; //columna
    }
}

/*
 * Diligencia por primera vez las matrices de pesos de la red, se diligencian con valores aleatoreos
 */
void RedNeuronal::PreDiligenciarW()
{
    // Llenar matrices W con valores aleatoreos
    for(int k=0; k<this->num_Matriz_W; k++)
        for(int i=0; i<arquitecturaRed[k]; i++) //fila
            for(int j=0; j<arquitecturaRed[k+1]; j++) //columna
                this->W[k][i][j] = (double)rand()/RAND_MAX;
}

/*
 * crea un puntero a una matriz que almacenará las salidas de las neuronas de la red
 */
void RedNeuronal::crearMatriz_a()
{
    //Reserva de memoria para las salidas, contempla la capa entrada y salida
    a =  new double*[this->numCapas];
    for (int i = 0; i < this->numCapas; i++)
        this->a[i] = new double[this->arquitecturaRed[i]];
}

/*
 * crea un puntero a un arreglo que almacena los sesgos de la red
 */
void RedNeuronal::crearArrayB()
{
    this->b = new double[numCapas-1];
}

/*
 * Diligencia el arreglo de sesgos con valores aleatoreos. El diligenciamiento de la primera vez
 */
void RedNeuronal::PrediligenciarB()
{
    for (int i=0;i<numCapas-1;i++)
        this->b[i]=(double)rand()/RAND_MAX;
}

/*
 * Muestra los valores almacenados en el vector de sesgos b
 */
void RedNeuronal::Mostrar_b()
{
    for(int i =0; i<numCapas-1;i++)
        std::cout<<b[i]<<" ";
    std::cout<<std::endl;
}

/*
 * Muestra los valores almacenados en las matrices de pesos W
 */
void RedNeuronal::Mostrar_Pesos_Red()
{
    // Imprimir matrices W
    for(int k=0; k<num_Matriz_W; k++){
        for(int i=0; i<arquitecturaRed[k]; i++){ //row
            for(int j=0; j<arquitecturaRed[k+1]; j++) //col
                std::cout<<this->W[k][i][j]<<" ";
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}

/*
 * Muestra los valores almacenados en las salida de cada neurona de cada capa
 */
void RedNeuronal::Mostrar_a_Red()
{
    // visualización de a
    for(int i=0; i<this->numCapas; i++)
    {
        for (int j=0; j<this->arquitecturaRed[i]; j++)
            std::cout<<this->a[i][j]<<" ";
        std::cout<<std::endl;
    }
}

/*
 * Realiza una predicción para un vector de entrada mediante propagación hacia adelante,
 * la salida lo almacena en la última capa de la matriz de a
 */
void RedNeuronal::Prediccion(double* X)
{
    //inicia la capa a0 con X
    for(int i=0; i< arquitecturaRed[0]; i++)
        a[0][i]=X[i];

    propagacion_Adelante();
}

/*
 * Realiza la propagación hacia adelante, aplica la función sigmoide entre las sumas de pesos, los sesgos
 * y lo almacena en la matriz de salida a para cada capa
 */
void RedNeuronal::propagacion_Adelante()
{

    // borrar  a
    for(int i=1; i<this->numCapas; i++)
    {
        for (int j=0; j<this->arquitecturaRed[i]; j++)
            a[i][j]=0;;
    }

    for(int k=1; k<numCapas; k++) //capa
    {
        for(int i=0; i<arquitecturaRed[k]; i++) //fila
        {
            for(int j=0; j<arquitecturaRed[k-1]; j++) //columna
            {
                a[k][i] += a[k-1][j]*W[k-1][j][i];
                //std::cout<<a[k+1][i]<<"+="<<a[k][j]<<"*"<<W[k][j][i]<<std::endl;
            }
            a[k][i] = logistic_Func(a[k][i] + b[k-1]);
            //std::cout<<a[k+1][i]<<"= logistic("<<a[k+1][i]<<"+"<<b[k]<<" )"<<std::endl;
        }
    }


}

/*
 * Función sigmoide, resice un valor y retorna la salida de la función sigmoide según la entrada
 */
double RedNeuronal::logistic_Func(double net)
{
    return 1/(1+exp(-net));
}

/*
 * Aplica la derivada de la gunción sigmoide para la retropropagación
 */
double RedNeuronal::derivada(double valor)
{
    //return valor*(1-valor);
    return logistic_Func(valor)*(1-logistic_Func(valor));
}

/*
 * Entrenala red medainte retropropagación y actualiza los pesos y sesgos.
 * Solo se encuentra entrenando con un dato de entrada y uno de salida, estos pueden
 * ser vectores, tanto el de entrada como el de salida
 */
void RedNeuronal::Entrenamiento(double* entradaRed, double* salidaRed, double alpha, int iteraciones)
{
    PrediligenciarEntrenamiento();

    double Error=0;
    for (int i=0;i<iteraciones;i++){

        //delta de la última capa
        for (int i=0; i<arquitecturaRed[numCapas-1]; i++)
        {
            E[i] = a[numCapas-1][i]-salidaRed[i];
            Error += 0.5*E[i]*E[i];
            delta[num_Matriz_W-1][i] = derivada(a[numCapas-1][i])*E[i];
        }

        //Diligenciar delta con la sumatoria
        for( int k=numCapas-2; k>0; k--)
            for(int i=0; i<arquitecturaRed[k]; i++)
                for( int j=0; j<arquitecturaRed[k+1];j++)
                    delta[k-1][i] += derivada(a[k][i])*delta[k][j]*W[k][i][j];

        //Actualización de pesos y sesgos
        double sum_delta = 0;
        for (int k=0; k<num_Matriz_W; k++){
            for(int i=0; i<arquitecturaRed[k]; i++) {//filas
                for( int j=0; j<arquitecturaRed[k+1];j++) // columnas
                    W[k][i][j] = W[k][i][j] - alpha*(a[k][i]*delta[k][j]);
                sum_delta += delta[k][i];
            }
            b[k] = b[k] - alpha*sum_delta;
            sum_delta = 0;
        }

        propagacion_Adelante();

        //Mostrar_Pesos_Red();
        Error = 0;
    }

    delete[] E;
    delete[] delta;

}

/*
 * Prediligencia los valores del vector de error y los deltas para la retropopagación.
 * Con dichos valores realiza el entrenamiento
 */
void RedNeuronal::PrediligenciarEntrenamiento()
{
    E = new double[arquitecturaRed[numCapas-1]];
    for (int i=0;i<arquitecturaRed[numCapas-1];i++)
        E[i]=0;

    delta =  new double*[this->num_Matriz_W];
    for (int i = 0; i < this->num_Matriz_W; i++)
        delta[i] = new double[this->arquitecturaRed[i+1]];
}

/*
 * Calcula el error acumulado de los errores en cada salida respecto al objetivo
 */
double RedNeuronal::Error()
{
    double error=0;
    for(int i=0; i< arquitecturaRed[numCapas-1];i++)
        error += E[i];

    return error;
}


/*
 * Guarda la arquitectura y pesos de una red entrenada
 */
void RedNeuronal::guardarRed(std::string ruta)
{
    std::ofstream arqRed(ruta+"arqRed.txt");
    std::ofstream pesosRed(ruta+"pesosRed.txt");
    std::ofstream biasRed(ruta+"biasRed.txt");

    for(int i=0; i<numCapas;i++){
        arqRed<<this->arquitecturaRed[i];
        if(i != numCapas - 1)
            arqRed << ","; // No comma at end of line
    }

    // Guardar bias
    for(int i=0; i<numCapas-1;i++){
        biasRed<<this->b[i];
        if(i != numCapas - 2)
            biasRed << ","; // No comma at end of line
    }

    // Guardar pesos W
    for(int k=0; k<num_Matriz_W; k++){
        for(int i=0; i<arquitecturaRed[k]; i++){ //row
            for(int j=0; j<arquitecturaRed[k+1]; j++){ //col
                pesosRed<<this->W[k][i][j]<<",";
                //if(j != arquitecturaRed[k+1] - 1)
                //        pesosRed << ","; // No comma at end of line
            }
            pesosRed<<std::endl;
        }
        pesosRed<<std::endl;
    }
    // Close the file
    pesosRed.close();
    arqRed.close();
    biasRed.close();
}

/*
 * Crea una red con base en el archivo de arquitectura y posteriormente carga los pesos del archivo de pesos
 */
void RedNeuronal::cargarRed(std::string rutaPesos)
{

    // Create an input filestream
    std::ifstream myFile(rutaPesos);

    // Make sure the file is open
    if(!myFile.is_open()) throw std::runtime_error("Could not open file");

    std::string line;
    size_t pos = 0;
    int j=0;

    for(int k=0; k<this->num_Matriz_W; k++){
        for(int i=0; i<=arquitecturaRed[k]; i++) {//fila
            std::getline(myFile, line);
            while ((pos = line.find(',')) != std::string::npos) {
                pos = line.find(',');
                this->W[k][i][j] = std::stod(line.substr(0, pos));
                line.erase(0, pos + 1);
                pos=0;
                j++;
            }
            j=0;
        }
    }

    myFile.close();
}
