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
#define MAX_CALIFICACION 100
#define MIN_CALIFICACION 0
#define MAXIMA_LONGITUD_CADENA 100

//Definimos todas las funciones para establecer los parametros de las matrices
void llamaCiclo();
int busquedaAleatorios(int minimo, int maximo);
void llenarMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1]);
void imprimirMatrizLinea();
float imprimirMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1], char alumnos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA], string nombreFacultad);
int main()
{
    srand(getpid());
    llamaCiclo();
    return 0;
}
void llamaCiclo()
{
    //Definimos cada matriz la cual maneja las diferentes facultades
    float matriz_facultad_1[NUMERO_Equipos][NUMERO_Anio + 1];
    float matriz_facultad_2[NUMERO_Equipos][NUMERO_Anio + 1];
    float matriz_facultad_3[NUMERO_Equipos][NUMERO_Anio + 1];
    char opcion;
    bool repetir = true;

    //Ingresamos la variable que servira
    float promedio_facultad_1;
    float promedio_facultad_2;
    float promedio_facultad_3;
    //Aqui estaremos manejando cada matriz ingresando los alumnos en cada una
    char alumnos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA] = {"Carlos","Luis","Maria","Pedro","Juan"};
    do
    {
        system("cls");
        promedio_facultad_1=0;
        promedio_facultad_2=0;
        promedio_facultad_3=0;
        cout << "*** Comparativo de Facultades ***" << endl << endl;
        //Se escribe el titulo de cada facultad generando las 3 matrices
        llenarMatriz(matriz_facultad_1);
        promedio_facultad_1 = imprimirMatriz(matriz_facultad_1, alumnos, "Facultad de Ingenieria");
        llenarMatriz(matriz_facultad_2);
        promedio_facultad_2 = imprimirMatriz(matriz_facultad_2, alumnos, "Facultad de Arquitectura");
        llenarMatriz(matriz_facultad_3);
        promedio_facultad_3 = imprimirMatriz(matriz_facultad_3, alumnos, "Facultad de Administracion");
        //Los if funcionan para escribir establecer el promedio de cada facultad
        if (promedio_facultad_1 > promedio_facultad_2 && promedio_facultad_1 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Ingenieria" << " Promedio: " << promedio_facultad_1 << endl;
        } else
        if (promedio_facultad_2 > promedio_facultad_1 && promedio_facultad_2 > promedio_facultad_3)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Arquitectura" << " Promedio: " << promedio_facultad_2 << endl;
        } else
        if (promedio_facultad_3 > promedio_facultad_2 && promedio_facultad_3 > promedio_facultad_1)
        {
            cout << " La facultad con el mejor promedio es : " << "Facultad de Administracion" << " Promedio: " << promedio_facultad_3 << endl;
        } else
        {
            cout << " Algunas facultades tienen el mismo promedio " << endl << endl;
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
        int calificacion = 0;
        //se manejan las columnas
        for (x = 0; x < NUMERO_Anio; x++)
        {
            if (x == 0 || x == 3)  //primer parcial //se genera numero aleatorio en la posicion del primer parcial y en actividades
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 20);
            } else if (x == 1)  //segundo parcial //se genera numero aleatorio en la posicion del segundo parcial
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 25);
            } else if (x == 2)  //examen final // Se genera numero aleatorio en la posicion del examen final
            {
                calificacion = busquedaAleatorios(MIN_CALIFICACION, 35);
            }
            suma += (float)calificacion; //aqui establecemos la suma de las calificaciones
            matriz[y][x] = calificacion; //se vam sumando en cada posicion
            calificacion=0;
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
float imprimirMatriz(float matriz[NUMERO_Equipos][NUMERO_Anio + 1], char alumnos[NUMERO_Equipos][MAXIMA_LONGITUD_CADENA], string nombreFacultad)
{
    //Funciòn que imprime la matriz en pantalla y realizando los calculos necesarios del promedio
    int y, x;

    //se establecen las variables que nos ayudaran con los promedios
    float promedioMayor = matriz[0][NUMERO_Anio];
    float promedioMenor = matriz[0][NUMERO_Anio];
    float totalGeneral = 0;
    float promedioGeneral = 0;
    char alumnoPromedioMayor[MAXIMA_LONGITUD_CADENA];
    char alumnoPromedioMenor[MAXIMA_LONGITUD_CADENA];
    //memcpy sirve para mover un dato de memoria de un lugar a otro
    memcpy(alumnoPromedioMayor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    memcpy(alumnoPromedioMenor, alumnos[0], MAXIMA_LONGITUD_CADENA);
    cout << nombreFacultad << endl;
    cout << "(Nota1)=>Primer Parcial  (Nota2)=>Segundo Parcial (Nota3)=>Final (Nota4)=>Actividades" << endl;
    imprimirMatrizLinea();
    cout << setw(9) << "Alumno";
    //menejamos un ciclo for para ir escribiendo arriba de la matriz
    for (x = 0; x < NUMERO_Anio; x++)
    {
        cout << setw(9) << "Nota" << x + 1;
    }
    cout << setw(8) << "Tot" << endl;
    imprimirMatrizLinea();
    for (y = 0; y < NUMERO_Equipos; y++)
    {
        //se muestra lo que se almacena en la matriz notas en la posicion y
        cout << "!" << setw(8) << alumnos[y] << "!";
        float suma = 0;
        for (x = 0; x < NUMERO_Anio; x++)
        {
            int calificacion = matriz[y][x];
            cout << setw(9) << calificacion << "!";
        }
        //Se utiliza ciclos if para establecer el mejor promedio
        float promedio = matriz[y][NUMERO_Anio];
        totalGeneral += matriz[y][NUMERO_Anio];
        if (promedio > promedioMayor)
        {
            promedioMayor = promedio;
            memcpy(alumnoPromedioMayor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        if (promedio < promedioMenor)
        {
            promedioMenor = promedio;
            memcpy(alumnoPromedioMenor, alumnos[y], MAXIMA_LONGITUD_CADENA);
        }
        cout << setw(9) << fixed << setprecision(2) << promedio << "!" << endl;
        imprimirMatrizLinea();
    }
    promedioGeneral = totalGeneral / NUMERO_Equipos;
    cout << "Nota mayor: " << setw(10) << alumnoPromedioMayor <<  setw(10) << promedioMayor << endl;
    cout << "Nota menor: " << setw(10) << alumnoPromedioMenor <<  setw(10) << promedioMenor << endl;
    cout << "Nota prom : " << setw(10) <<  promedioGeneral << endl << endl;
    return promedioGeneral;
}
