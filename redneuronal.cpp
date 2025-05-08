/**
 *  *
 * Version: 0.2
 * Fecha: 7/05/2025
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

#include <sstream>

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
RedNeuronal::RedNeuronal(std::vector<int> arquitecturaRed, int numCapas){

    this->arquitecturaRed = arquitecturaRed;
    this->numCapas = numCapas;
    this->num_Matriz_W = numCapas-1;

    crearMatrizW();
    //PreDiligenciarW(); //Pesos W

    crearArrayB();
    //PrediligenciarB(); //bias

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
    std::ifstream ReadmyFile;
    ////Si no lee correctamente el archivo informa de un error
    if(!ReadmyFile.is_open()) throw std::runtime_error("Could not open file");

    std::string line;
        ReadmyFile.open(string_arqRed);
    while (getline(ReadmyFile, line, ',')) {
        arquitecturaRed.push_back(std::stoi(line));
    }
    ReadmyFile.close();

    ReadmyFile.open(string_biasRed);
    while (getline(ReadmyFile, line, ',')) {
        b.push_back(std::stod(line));
    }
    ReadmyFile.close();

    this->numCapas = this->b.size();
    this->num_Matriz_W = this->numCapas - 1;

    crearMatrizW();
    crearArrayB();
    crearMatriz_a();
    cargarRed(pesosRed);

}

void RedNeuronal::crearMatrizW()
{
    int filas = 0;
    int columnas = 0;
    W.clear(); // Por si se llama más de una vez
    W.resize(this->num_Matriz_W); // W.size() == numCapas - 1
    for (int i = 0; i < this->num_Matriz_W; ++i) {
        filas = arquitecturaRed[i];
        columnas = arquitecturaRed[i + 1];
        W[i].resize(filas); // cada fila representa una neurona en la capa i
        for (int j = 0; j < filas; ++j) {
            W[i][j].resize(columnas); // pesos hacia cada neurona en la siguiente capa

            for (int k = 0; k < columnas; ++k)
                W[i][j][k] = ((double)rand() / RAND_MAX) * 0.1 - 0.05; // entre -0.05 y 0.05
        }
    }
}


/*
 * Diligencia por primera vez las matrices de pesos de la red, se diligencian con valores aleatoreos
 */
void RedNeuronal::PreDiligenciarW()
{
    // Llenar matrices W con valores aleatoreos
    for(int k=0; k<this->num_Matriz_W; k++) // matriz
        for(int i=0; i<arquitecturaRed[k]; i++) //fila
            for(int j=0; j<arquitecturaRed[k+1]; j++) //columna
                //this->W[k][i][j] = (double)rand()/RAND_MAX;
                //this->W[k][i][j] = 0.0;//(double)(rand() % 10);//RAND_MAX;
                this->W[k][i][j] = ((double)rand() / RAND_MAX) * 0.1 - 0.05; // entre -0.05 y 0.05
}

/*
 * crea una matriz "a" que almacena las salidas de las neuronas de la red y una matriz "f" que almacena las salidas pero de la retropopagación
 */
void RedNeuronal::crearMatriz_a()
{
    a.resize(this->numCapas);
    f.resize(this->numCapas);

    for (int i = 0; i < this->numCapas; ++i) {
        a[i].resize(this->arquitecturaRed[i], 0.0); // inicializa con 0.0
        f[i].resize(this->arquitecturaRed[i], 0.0);
    }
}


/*
 * crea un vector "b" que almacena los sesgos de la red, también inicializa
 */
void RedNeuronal::crearArrayB()
{

    b.resize(numCapas - 1);

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dist(0.0, 1.0);

    for (int i = 0; i < numCapas - 1; i++)
        b[i] = dist(gen);
}

/*
 * Muestra los valores almacenados en el vector de sesgos b
 */
void RedNeuronal::Mostrar_b()
{
    for(int i =0; i<this->b.size();i++)
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
    for(int i=0; i<this->numCapas; i++)
    {
        for (int j=0; j<this->arquitecturaRed[i]; j++)
            std::cout<<this->a[i][j]<<" ";
        std::cout<<std::endl;
    }
}

/*
 * Realiza una predicción para un vector de entrada mediante propagación hacia adelante,
 * la salida lo almacena en la última capa de la matriz de "a"
 */
void RedNeuronal::Prediccion(double* X)
{

    // borrar  a
    for(int i=0; i<this->numCapas; i++)
        for (int j=0; j<this->arquitecturaRed[i]; j++)
            a[i][j]=0;

    ////inicia la capa a0 con la entrada X
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
    Borrar_a();

    for(int k=1; k<numCapas; k++){ //capa
        for(int i=0; i<arquitecturaRed[k]; i++){ //fila
            for(int j=0; j<arquitecturaRed[k-1]; j++){ //columna
                a[k][i] += a[k-1][j]*W[k-1][j][i];
                //std::cout<<a[k][i]<<"+="<<a[k-1][j]<<"*"<<W[k-1][j][i]<<std::endl;
            }
            //a[k][i] = sigmoide(a[k][i] + b[k-1]);
            //std::cout<<"logistic("<<a[k][i]<<"+"<<b[k-1]<<" )"<<" = ";
            if(k<numCapas-1){
                a[k][i] = relu(a[k][i] + b[k-1]);
                //std::cout<<k<<std::endl;
            }
            else{
                a[k][i] = sigmoide(a[k][i] + b[k-1]);
                //std::cout<<k<<std::endl;
            }
            //std::cout<<a[k][i]<<std::endl;
        }
    }
}

/*
 * Función sigmoide, recibe un valor y retorna la salida de la función sigmoide según la entrada
 */
double RedNeuronal::logistic_Func(double net)
{
    return 1/(1+std::exp(-net));
}

/*
 * Aplica la derivada de la gunción sigmoide para la retropropagación
 */
double RedNeuronal::derivada(double valor)
{
    return logistic_Func(valor)*(1-logistic_Func(valor));
}

/*
 * Función sigmoide, recibe un valor y retorna la salida de la función sigmoide según la entrada
 */
double RedNeuronal::sigmoide(double net)
{
    return 1/(1+std::exp(-net));
}

/*
 * Aplica la derivada de la gunción sigmoide para la retropropagación
 */
double RedNeuronal::der_sigmoide(double valor){
    return sigmoide(valor)*(1-sigmoide(valor));
}

/*
 * Función relu, recibe un valor y retorna la salida de la función relu según la entrada
 */
double RedNeuronal::relu(double net){

    if (net>0)
        return net;
    else
        return 0;
}

/*
 * Función der_relu, recibe un valor y retorna la salida de la derivada de la función relu según la entrada
 */
double RedNeuronal::der_relu(double net){

    if (net>0)
        return 1;
    else
        return 0;
}

/*
 *
 * Entrenala red medainte retropropagación y actualiza los pesos y sesgos.
 * Solo se encuentra entrenando con un dato de entrada y uno de salida, estos pueden
 * ser vectores, tanto el de entrada como el de salida
 */
void RedNeuronal::Entrenamiento(double** entradaRed, double **salidaRed, int cantidadDatos, double alpha, int iteraciones){

    double Error_total = 0;
    int p=0;
    int datos_i=0;
    double sum_delta = 0;

    PrediligenciarEntrenamiento();

    // Inicializar la capa de entrada con los valores de entrada
    for (int i=0; i< arquitecturaRed[0];i++)
        a[0][i] = entradaRed[datos_i][i];
    // Propaga hacia adelante para calcular la salida en la última capa
    propagacion_Adelante();
    // Calcular el error de la última capa
    for (int i=0; i<arquitecturaRed[numCapas-1]; i++){
        E[i] = (a[numCapas-1][i]-salidaRed[datos_i][i]);
        Error_total += 0.5*E[i]*E[i];
        delta[num_Matriz_W-1][i] = der_sigmoide(a[numCapas-1][i])*E[i]; //delta L
    }
    while( p < iteraciones*cantidadDatos ){
        //Diligenciar delta con la sumatoria
        for( int k=numCapas-2; k>0; k--)
            for(int i=0; i<arquitecturaRed[k]; i++){
                for( int j=0; j<arquitecturaRed[k+1];j++){
                    delta[k-1][i] += der_relu(a[k][i])*delta[k][j]*W[k][i][j];
                }
            }
        //Actualizar Pesos y bias
        for (int k=0; k<num_Matriz_W; k++){
           for(int i=0; i<arquitecturaRed[k+1]; i++){//filas
               for( int j=0; j<arquitecturaRed[k];j++){ // columnas
                    W[k][j][i] = W[k][j][i] - alpha*(a[k][j])*(delta[k][i]);
               }
               sum_delta += delta[k][i];
           }
           b[k] = b[k] - alpha*sum_delta;
           sum_delta = 0;
        }
        //reiniciar delta
        for(int k=0; k<num_Matriz_W; k++)
            for(int i=0; i<arquitecturaRed[k+1]; i++){
                delta[k][i]=0;
            }
        // Inicializar la capa de entrada con los valores de entrada
        for (int i=0; i<arquitecturaRed[0]; i++){
            a[0][i] = entradaRed[datos_i][i];
        }
        // Propaga hacia adelante para calcular la salida en la última capa
        propagacion_Adelante();
        // Calcular el error de la última capa
        Error_total=0;
        for (int i=0; i<arquitecturaRed[numCapas-1]; i++){
            E[i] = (a[numCapas-1][i]-salidaRed[datos_i][i]);
            Error_total += 0.5*E[i]*E[i];
            delta[num_Matriz_W-1][i] = der_sigmoide(a[numCapas-1][i])*E[i]; //delta L
        }
        // Mueve
        if (p%cantidadDatos == 0){
            datos_i++;
            if (datos_i>cantidadDatos-1)
                datos_i=0;
        }
        p++;
    }
    std::cout<<"Entremaniento finalizado. Se realizaron "<<p<<" iteraciones. Error total: "<<Error_total<<std::endl;
    std::cout<<std::endl;
}

/*
 * Entrenala red mediante retropropagación y actualiza los pesos y sesgos.
 * Se encuentra entrenando con datos en un archivo de entrada y uno de salida
 */
void RedNeuronal::Entrenamiento2(std::vector<std::vector<double>>&  entradaRed,
                                 std::vector<std::vector<double>>& salidaRed,
                                 double alpha,
                                 int iteraciones)
{
    double Error_total = 0;
    double sum_delta = 0;

    PrediligenciarEntrenamiento();

    for (int epoca = 0; epoca < iteraciones; ++epoca) {
        Error_total = 0;
        for (size_t i = 0; i < entradaRed.size(); ++i) {
            //const std::vector<double>& vectorImagenTest = entradaRed[i];
            const std::vector<double>& etiqueta = salidaRed[i];
            // Inicializar la capa de entrada con los valores de entrada
            //std::memcpy(a[0], entradaRed[i].data(), arquitecturaRed[0] * sizeof(double));
            if (a[0].size() != entradaRed[i].size())
                a[0].resize(entradaRed[i].size());
            a[0] = entradaRed[i];            // Propaga hacia adelante para calcular la salida en la última capa

            propagacion_Adelante();

                // Calcular el error de la última capa
            for (int i=0; i<arquitecturaRed[numCapas-1]; i++){
                //std::cout<<salidaRed[i][datos_i]<<std::endl;
                E[i] = a[numCapas-1][i]-etiqueta[i];
                Error_total += 0.5*E[i]*E[i];
                delta[num_Matriz_W-1][i] = der_relu(a[numCapas-1][i])*E[i]; //delta L
            }

            //Diligenciar delta con la sumatoria
            for( int k=numCapas-2; k>0; k--)
                for(int i=0; i<arquitecturaRed[k]; i++){
                    for( int j=0; j<arquitecturaRed[k+1];j++){
                        delta[k-1][i] += der_relu(a[k][i])*delta[k][j]*W[k][i][j];
                    }
                }
            //Actualizar Pesos y bias
            for (int k=0; k<num_Matriz_W; k++){
                for(int i=0; i<arquitecturaRed[k+1]; i++){//filas
                    for( int j=0; j<arquitecturaRed[k];j++){ // columnas
                        W[k][j][i] = W[k][j][i] - alpha*(a[k][j])*(delta[k][i]);
                    }
                    sum_delta += delta[k][i];
                }
                b[k] = b[k] - alpha*sum_delta;
                sum_delta = 0;
            }
            //reiniciar delta
            for(int k=0; k<num_Matriz_W; k++)
                for(int i=0; i<arquitecturaRed[k+1]; i++){
                    delta[k][i]=0;
                }
        }
        std::cout << "Época: " << epoca << " Error total: " << Error_total << std::endl;
    }
    std::cout<<"Entremaniento finalizado. Se realizaron "<<iteraciones*entradaRed.size()<<" iteraciones. Error total: "<<Error_total<<std::endl;
    std::cout<<std::endl;
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

    //reiniciar delta
    for(int k=0; k<num_Matriz_W; k++)
        for(int i=0; i<arquitecturaRed[k+1]; i++){
            delta[k][i]=0;
        }
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

    std::cout<<"Red guardada en "<<ruta<<std::endl;
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
            while ( line.find(',') != std::string::npos) {
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

/*
 * Lee archivos de datos de variable independiente y dependiente y los guarda en matris X y puntero Y
 */

void RedNeuronal::LeerDatosEntrenamiento(   std::string rutaDatos,
                                            std::vector<std::vector<double>>& X,
                                            std::vector<std::vector<double>>& Y)
{

    std::ifstream archivo(rutaDatos);
    std::string linea;

    while (std::getline(archivo, linea)) {
        std::stringstream ss(linea);
        std::string valor;
        std::vector<double> fila;

        while (std::getline(ss, valor, ',')) {
            if (!valor.empty())
                fila.push_back(std::stod(valor));
        }

        // Suponiendo que la salida es el último valor
        std::vector<double> entrada(fila.begin(), fila.end() - 1);
        std::vector<double> salida(1, fila.back());

        X.push_back(entrada);
        Y.push_back(salida);
    }

    archivo.close();
}


void RedNeuronal::LeerImagenesEntrenamiento(std::string rutaX, std::string rutaY, std::vector<std::vector<double>>& X,  std::vector<std::vector<double>>& Y)
{
    cv::Mat IMAGENchica;
    std::string line;
    std::string ruta;
    std::string tamaho[]={"<filename>","</filename>",
                          "<width>","</width>",
                          "<height>","</height>",
                          "<depth>","</depth>"};

    std::string posicion[]={"<name>","</name>",
                            "<xmin>","</xmin>",
                            "<ymin>","</ymin>",
                            "<xmax>","</xmax>",
                            "<ymax>","</ymax>"};
    int pos1=0;
    int pos2=0;

    //Recorre todos los archivos de una carpeta
    for (auto & p : std::filesystem::directory_iterator(rutaY)){
        ruta = std::string(p.path());
        std::ifstream File_Y(ruta);
        //std::cout<<std::string(p.path())<<" "<<std::endl;
        //std::cout<<j<<" "<<std::endl;
        //recorre todas las lineas de un archivo
        while (std::getline(File_Y, line)){
            for(int i=0; i<4; i++){
                //std::cout<<claves[i*2]<<" "<<claves[i*2+1]<<std::endl;
                pos1 = line.find(tamaho[i*2]);
                pos2 = line.find(tamaho[i*2+1]);
                if(pos1>0 && pos2>0){
                    switch(i){
                    case 0:
                        //std::cout<<"Ruta img: "<<rutaY<<line.substr(pos1+10,pos2-11)<<std::endl;
                        datos.ruta = rutaX+line.substr(pos1+10,pos2-11);
                        break;
                    case 1:
                        //std::cout<<"width: "<<line.substr(pos1+7,pos2-9)<<std::endl;
                        datos.width = stoi(line.substr(pos1+7,pos2-9));
                        break;
                    case 2:
                        //std::cout<<"height: "<<line.substr(pos1+8,pos2-10)<<std::endl;
                        datos.height = stoi(line.substr(pos1+8,pos2-10));
                        break;
                    case 3:
                        //std::cout<<"depth: "<<line.substr(pos1+7,pos2-9)<<std::endl;
                        datos.depth = stoi(line.substr(pos1+7,pos2-9));
                        break;
                    default:
                        std::cout<<"error no encontró"<<std::endl;
                    }
                }
            }
            for(int i=0; i<5; i++){
                //std::cout<<claves[i*2]<<" "<<claves[i*2+1]<<std::endl;
                pos1 = line.find(posicion[i*2]);
                pos2 = line.find(posicion[i*2+1]);
                if(pos1>0 && pos2>0){
                    switch(i){
                    case 0:
                        //std::cout<<"name: "<<line.substr(pos1+6,pos2-8)<<std::endl;
                        datos.clase = line.substr(pos1+6,pos2-8);
                        break;
                    case 1:
                        //std::cout<<"xmin: "<<line.substr(pos1+6,pos2-9)<<std::endl;
                        datos.xMin = stoi(line.substr(pos1+6,pos2-9));
                        datos.xminAbs = (double)datos.xMin/(double)datos.width;
                        break;
                    case 2:
                        //std::cout<<"ymin: "<<line.substr(pos1+6,pos2-9)<<std::endl;
                        datos.yMin = stoi(line.substr(pos1+6,pos2-9));
                        datos.yminAbs = (double)datos.yMin/(double)datos.height;
                        break;
                    case 3:
                        //std::cout<<"xmax: "<<line.substr(pos1+6,pos2-9)<<std::endl;
                        datos.xMax = stoi(line.substr(pos1+6,pos2-9));
                        datos.xmaxAbs = (double)datos.xMax/(double)datos.width;
                        break;
                    case 4:
                        //std::cout<<"ymax: "<<line.substr(pos1+6,pos2-9)<<std::endl;
                        datos.yMax = stoi(line.substr(pos1+6,pos2-9));
                        datos.ymaxAbs = (double)datos.yMax/(double)datos.height;
                        break;
                    default:
                        std::cout<<"error no encontró"<<std::endl;
                    }
                }
            }
        }
        cv::Mat image = cv::imread(datos.ruta,cv::IMREAD_GRAYSCALE);   // Read the file
        if (image.empty()) continue;
        cv::resize(image, image, cv::Size(128,128));
        image.convertTo(image, CV_64F);
        cv::Mat plano = image.reshape(1, 1);
        std::vector<double> vectorImagen(plano.ptr<double>(), plano.ptr<double>() + plano.cols*plano.rows);
        X.push_back(vectorImagen);
        Y.push_back({ datos.xminAbs, datos.yminAbs, datos.xmaxAbs, datos.ymaxAbs });
    }
}

/*
 * Función Borrar_a, dedicada a borrar los datos de la matriz que almacena la salida de cada neurona
 *
*/
void RedNeuronal::Borrar_a()
{
    // borrar  a
    for(int i=1; i<this->numCapas; i++)
        for (int j=0; j<this->arquitecturaRed[i]; j++)
            a[i][j]=0.0;
}
