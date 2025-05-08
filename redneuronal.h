#ifndef REDNEURONAL_H
#define REDNEURONAL_H
#include <string>
#include <filesystem>
#include <opencv2/opencv.hpp>

class RedNeuronal
{
public:

    // matrices de pesos de la red, apunta a las diferentes matrices entre capas
    std::vector<std::vector<std::vector<double>>> W;
    // arreglo que describe la red, cantidad de capas y neuronas por capas
    std::vector<int> arquitecturaRed;
    // matriz que presenta las salidas de cada red
    std::vector<std::vector<double>> a;
    // matriz que presenta las salidas de cada red
    std::vector<std::vector<double>> f;
    // estructura para guardar los datos de una imagen etiquetada
    struct dataImg{
        std::string ruta = "";
        int width = 1;
        int height = 1;
        int depth = 0;
        std::string clase = "";
        int xMin = 0;
        int yMin = 0 ;
        int xMax = 0;
        int yMax = 0;
        double xminAbs = 0;
        double yminAbs = 0;
        double xmaxAbs = 0;
        double ymaxAbs = 0;
    } datos;

    // constructores
    RedNeuronal(std::vector<int> arquitecturaRed, int numCapas);               // constructor a partir de archivos txt de arquitectura y pesoss de una red
    RedNeuronal(std::string arquitecturaRed, std::string pesosRed, std::string string_biasRed); // constructor a partir de punteros a un arreglo de arquitectura y cantidad de capas

    // ver los valores de las matrices y arreglos
    void Mostrar_Pesos_Red();   // muestra los valores de las matrices de pesos de la red
    void Mostrar_a_Red();       //muestra los valores de la matriz de salidas de las neuronas
    void Mostrar_b();           //muestra los valores del arreglo de sesgos

    void Prediccion(double* X); // Método para realizar una predicción

    // metodo para entrenar una red creada
    void Entrenamiento(double **entradaRed, double **salidaRed, int cantidadDatos, double alpha, int iteraciones);   //
    void Entrenamiento2(std::vector<std::vector<double>>& entradaRed,
                        std::vector<std::vector<double>>& salidaRed,
                        double alpha,
                        int iteraciones);

    // Guardar una red entrenada en archivos txt, pesosRed.txt y arqRed.txt
    void guardarRed(std::string ruta);

    // Leer datos de entrada y salida de archivos planos, para entrenamiento de la red
    void LeerDatosEntrenamiento(std::string rutaDatos,
                                std::vector<std::vector<double>>& X,
                                std::vector<std::vector<double>>& Y);

    void LeerImagenesEntrenamiento(std::string rutaX, std::string rutaY, std::vector<std::vector<double>>& X,  std::vector<std::vector<double>>& Y);


private:

    //double *b;              // apunta al arreglo de sesgos
    std::vector<double> b;
    int num_Matriz_W;       //cantidad de matrices de pesos entre capas
    int numCapas;           // cantidad de capas de la red, incluye la capa de entrada y salida

    double **delta;         // Matriz de sumatoria para la retropropagación
    double *E;              // apunta al arreglo de errores, el cual se calcula con la salida y el target al entrenar

    void crearMatrizW();    // crea el puntero y reserva memoria para los pesos de la red
    void PreDiligenciarW(); // prediligencia aleatoriamente las matrices de pesos de la red

    void crearMatriz_a();   // crea el puntero y reserva memoria para las salidas de las neuronas al operar

    void crearArrayB();     // crea el puntero al array de sesgos
    //void PrediligenciarB(); // prediligencia aleatoreamente los sesgos

    void propagacion_Adelante();
    double logistic_Func(double net);
    double derivada(double valor);

    double sigmoide(double net);
    double der_sigmoide(double valor);

    double relu(double net);
    double der_relu(double valor);

    double Error(); // metodo para calcular el erro, usado para el entrenamiento

    // Llama a los usados para realizar un entrenamiento
    void PrediligenciarEntrenamiento();

    void Borrar_a();

    // Carga los pesos de un archivo txt
    void cargarRed(std::string rutPesos);





};

#endif // REDNEURONAL_H
