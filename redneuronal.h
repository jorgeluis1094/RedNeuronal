#ifndef REDNEURONAL_H
#define REDNEURONAL_H
#include <string>

class RedNeuronal
{
public:

    // variables
    double ***W;            //Putero a matrices de pesos de la red, apunta a las diferentes matrices entre capas
    int *arquitecturaRed;   // arreglo que describe la red, cantidad de capas y neuronas por capas
    double **a;             // matriz que presenta las salidas de cada red


    // constructores
    RedNeuronal(int* arquitecturaRed, int* numCapas);               // constructor a partir de archivos txt de arquitectura y pesoss de una red
    RedNeuronal(std::string arquitecturaRed, std::string pesosRed); // constructor a partir de punteros a un arreglo de arquitectura y cantidad de capas

    // ver los valores de las matrices y arreglos
    void Mostrar_Pesos_Red();   // muestra los valores de las matrices de pesos de la red
    void Mostrar_a_Red();       //muestra los valores de la matriz de salidas de las neuronas
    void Mostrar_b();           //muestra los valores del arreglo de sesgos

    void Prediccion(double* X); // Método para realizar una predicción

    // metodo para entrenar una red creada
    void Entrenamiento(double* entradaRed, double* salidaRed, double alpha, int iteraciones);   //

    // Guardar una red entrenada en archivos txt, pesosRed.txt y arqRed.txt
    void guardarRed();

private:


    double *b;              // apunta al arreglo de sesgos
    int num_Matriz_W;       //cantidad de matrices de pesos entre capas
    int numCapas;           // cantidad de capas de la red, incluye la capa de entrada y salida

    double **delta;         // Matriz de sumatoria para la retropropagación
    double *E;              // apunta al arreglo de errores, el cual se calcula con la salida y el target al entrenar

    void crearMatrizW();    // crea el puntero y reserva memoria para los pesos de la red
    void PreDiligenciarW(); // prediligencia aleatoriamente las matrices de pesos de la red

    void crearMatriz_a();   // crea el puntero y reserva memoria para las salidas de las neuronas al operar

    void crearArrayB();     // crea el puntero al array de sesgos
    void PrediligenciarB(); // prediligencia aleatoreamente los sesgos

    void propagacion_Adelante();
    double logistic_Func(double net);
    double derivada(double valor);

    double Error(); // metodo para calcular el erro, usado para el entrenamiento

    // Llama a los usados para realizar un entrenamiento
    void PrediligenciarEntrenamiento();

    // Carga los pesos de un archivo txt
    void cargarRed(std::string rutPesos);



};

#endif // REDNEURONAL_H
