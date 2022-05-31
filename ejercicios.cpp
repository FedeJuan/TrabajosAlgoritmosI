#include "ejercicios.h"
#include "auxiliares.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <iomanip>

using namespace std;

/******++++**************************** EJERCICIO tiempoTotal ***********+++***********************/
tiempo tiempoTotal(viaje v) {
    if (v.size() == 0)
        return 0;
    tiempo t;
    t = maxTiempo(v) - minTiempo(v);
    return t;
}

/************++*********************** EJERCICIO distanciaTotal ************++*********************/
distancia distanciaTotal(viaje v) {
    distancia d = 0;
    int i = 0;
    while (i < v.size()){
        d = d + (distEnKM(obtenerPosicion(v[i]), obtenerPosicion(buscoSiguientePunto(v, v[i]))));
        i = i +1;
    }

    return d;
}

/*****************************+***** EJERCICIO excesoDeVelocidad **********************************/
bool excesoDeVelocidad(viaje v) {
    bool resp = false;
    int i = 0;
    while (i < v.size()){
        if (velocidad(v[i], buscoSiguientePunto(v, v[i])) > 80)
            resp = true;
        i = i +1;
    }
    return resp;
}

/************************************ EJERCICIO recorridoCubierto *******************************/
vector<gps> recorridoNoCubierto(viaje v, recorrido r, distancia u) {
    vector<gps> resp;
    int i = 0; int k = 0; bool estaDentro = false;
    while (k < r.size()){
        while (i < v.size()){
            if (distEnKM(obtenerPosicion(v[i]), r[k]) < u) {
                estaDentro = true;
                i = v.size();
            }
            i = i + 1;
        }
        if (!estaDentro) {
            resp.push_back(r[k]);
        }
        i = 0;
        k = k + 1;
        estaDentro = false;
    }
    return resp;
}

/***************************************** EJERCICIO flota ***************************************/
int flota(vector<viaje> f, tiempo t0, tiempo tf) {
    int resp = 0;
    int i = 0;
    while (i < f.size()){
        if ((minTiempo(f[i]) > t0 && maxTiempo(f[i]) < tf) || (minTiempo(f[i]) < t0 && maxTiempo(f[i]) > t0 ) || (minTiempo(f[i]) < tf && maxTiempo(f[i]) > tf) || (minTiempo(f[i]) < t0 &&
                maxTiempo(f[i]) > tf))
           resp = resp + 1;
        i = i + 1 ;
    }
    return resp;
}

/************************************** EJERCICIO construirGrilla *******************************/
grilla construirGrilla(gps esq1, gps esq2, int n, int m) {
    grilla resp = {};
    // codigo

    return resp;
}

/************************************* EJERCICIO cantidadDeSaltos ******************************/
int cantidadDeSaltos(grilla g, viaje v) {
    int resp;
    // codigo

    return resp;
}


/************************************* EJERCICIO corregirViaje ******************************/
void corregirViaje(viaje& v, vector<tiempo> errores){
    // codig

    return;
}
