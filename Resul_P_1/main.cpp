/*
En el siguiente programa trata sobre la comparacion de ligas de futbol
el cual tiene funciones como busqueda aleatoria de numeros, ciclos while
utilizacion de matrices, entre otros, la entrega se realiza en canvas adjuntando el link del video y el link del
repositorio de Github
*/

//Crsitian David Sipac Ispache
//9959-23-1567
//Progra 1

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

//se define todas las variables que utilizaremos para manejar la matriz
//se define todas las variables que utilizaremos para manejar la matriz
#define NUMERO_Equipos 5
#define NUMERO_Anio 4
#define MAX_CALIFICACION 50
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

//Definimos todas las funciones para establecer los parametros de las matrices
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1], char equipos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    //Definimos cada matriz la cual maneja las diferentes facultades
    float matriz_equipo_1[NUMERO_Equipos][NUMERO_Anio + 1];
    float matriz_equipo_2[NUMERO_Equipos][NUMERO_Anio + 1];
    float matriz_equipo_3[NUMERO_Equipos][NUMERO_Anio + 1];
    char opcion;
    bool repetir = true;

    //Ingresamos la variable que servira
    float promedio_1;
    float promedio_2;
    float promedio_3;
    //Aqui estaremos manejando cada matriz ingresando los equipos en cada una
    char equipos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA] = {"Rojos","Cremas","Xela","Aurora","Guasta"};
    do
    {
        system("cls");
        promedio_1=0;
        promedio_2=0;
        promedio_3=0;
        cout << "*** Comparativo de Ligas ***" << endl << endl;
        //Se escribe el titulo de cada facultad generando las 3 matrices
        llenarMatriz(matriz_equipo_1);
        promedio_1 = imprimirMatriz(matriz_equipo_1, equipos, "Liga Mayor");
        llenarMatriz(matriz_equipo_2);
        promedio_2 = imprimirMatriz(matriz_equipo_2, equipos, "Liga Nacional");
        llenarMatriz(matriz_equipo_3);
        promedio_3 = imprimirMatriz(matriz_equipo_3, equipos, "Liga segunda");
        //Los if funcionan para escribir establecer el promedio de cada facultad
        if (promedio_1 > promedio_2 && promedio_1 > promedio_3)
        {
            cout << " La liga con el mejor promedio es : " << "Liga Mayor" << " Promedio: " << promedio_1 << endl;
        } else
        if (promedio_2 > promedio_1 && promedio_2 > promedio_3)
        {
            cout << " La liga con el mejor promedio es : " << "Liga Nacional" << " Promedio: " << promedio_2 << endl;
        } else
        if (promedio_3 > promedio_2 && promedio_3 > promedio_1)
        {
            cout << " La liga con el mejor promedio es : " << "Liga segunda" << " Promedio: " << promedio_3 << endl;
        } else
        {
            cout << " Algunas ligas tienen el mismo promedio " << endl << endl;
        }
        //Establece la funcion de repetir el ciclo
        cout << "Desea otro calculo (s/n)? ";
        cin >> opcion;
        if (opcion == 'n')
        {
            repetir=false;
        }
    } while (repetir);
}
//la funcion que utilizaremos para generar numeros aleatorios
int busquedaAleatorios(int minimo, int maximo)
{
    return minimo + rand() / (RAND_MAX / (maximo - minimo + 1) + 1);
}

//se usan ciclos for para llenar las matrices
void llenarMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1])
{
    int y, x;
    //Se manejan las filas
    //Se maneja una matriz de 5 por 4 aumentando 1 en la columna que sera nuestro total
    for (y = 0; y < NUMERO_Equipos; y++)
    {
        float suma = 0;
        int puntos = 0;
        //se manejan las columnas
        for (x = 0; x < NUMERO_Anio; x++)
        {
            if (x == 0 || x == 3)  //primer parcial //se genera numero aleatorio en la posicion del primer parcial y en actividades
            {
                puntos = busquedaAleatorios(MIN_CALIFICACION, 50);
            } else if (x == 1)  //segundo parcial //se genera numero aleatorio en la posicion del segundo parcial
            {
                puntos = busquedaAleatorios(MIN_CALIFICACION, 50);
            } else if (x == 2)  //examen final // Se genera numero aleatorio en la posicion del examen final
            {
                puntos = busquedaAleatorios(MIN_CALIFICACION, 50);
            }
            suma += (float)puntos; //aqui establecemos la suma de las calificaciones
            matriz[y][x] = puntos; //se vam sumando en cada posicion
            puntos=0;
        }
        // Agregar promedio

        matriz[y][NUMERO_Anio] = suma;
    }
}

void imprimirMatrizLinea()
{
    int x;

    cout << "+--------";
    for (x = 0; x < NUMERO_Anio + 1; x++)
    {
        cout << "+---------";
    }
    cout << "+\n";
}
float imprimirMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1], char equipos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    //se establecen las variables que nos ayudaran con los promedios
    float PromedioMayor = matriz[0][NUMERO_Anio];
    float promedioMenor = matriz[0][NUMERO_Anio];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char EquipoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char EquipoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    //memcpy sirve para mover un dato de memoria de un lugar a otro
    memcpy(EquipoPromedioMayor, equipos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(EquipoPromedioMenor, equipos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Anio1)=>2010  (Anio2)=>2011 (Anio3)=>2012 (Anio4)=>2014" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Equipo";
    //menejamos un ciclo for para ir escribiendo arriba de la matriz
    for (x = 0; x < NUMERO_Anio; x++)
    {
        cout << setw(9) << "Anio" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_Equipos; y++)
    {
        //se muestra lo que se almacena en la matriz notas en la posicion y
        cout << "!" << setw(8) << equipos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_Anio; x++)
        {
            int puntos = matriz[y][x];
            cout << setw(9) << puntos << "!";
        }
        //Se utiliza ciclos if para establecer el mejor promedio
        float promedio = matriz[y][NUMERO_Anio];
        totalGeneral += matriz[y][NUMERO_Anio];
        if (promedio > PromedioMayor)
        {
            PromedioMayor = promedio;
            memcpy(EquipoPromedioMayor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(EquipoPromedioMenor, equipos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_Equipos;
    cout << "Equipo Mayor Puntaje: " << setw(10) << EquipoPromedioMayor <<  setw(10) << PromedioMayor << endl;
    cout << "Equipo Menor Puntaje: " << setw(10) << EquipoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Promedio de Liga : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
