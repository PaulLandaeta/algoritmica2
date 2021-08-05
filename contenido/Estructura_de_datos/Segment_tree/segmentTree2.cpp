#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
int[] numbers = {1,2,3,4,5,6,7,8};

struct node {
    // crear una variable por query
    int maximo;
    int minimo;
}segmentTree[1000000];

void init(int ini, int fin, int nodoActual) {
    if(ini == fin) {
        segmentTree[nodoActual].maximo = numbers[ini];
        segmentTree[nodoActual].minimo = numbers[ini];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        // Ir por el hijo Izq 
        init(ini, medio, hijoIzq);
        // Ir por el hijo Der
        init(medio + 1, fin, hijoDer);
        // Actualizar el nodo actual
        segmentTree[nodoActual].maximo = max(segmentTree[hijoIzq].maximo, segmentTree[hijoDer].maximo);
        segmentTree[nodoActual].minimo = max(segmentTree[hijoIzq].minimo, segmentTree[hijoDer].minimo);
    }
}

node query(int ini, int fin, int nodoActual, int i, int j) {
    if(ini >= i && fin <= j){ 
        return segmentTree[nodoActual];
    }
    else {
        int medio = (ini + fin) / 2;
        int hijoIzq = 2 * nodoActual + 1;
        int hijoDer = 2 * nodoActual + 2;
        if ( j <= medio ) {
            return query(ini, medio, hijoIzq, i, j);
        }else if (i > medio){
            return query(medio+1,fin,hijoDer,i,j);
        } else {
            node queryIzq = query(ini,medio,hijoIzq,i,j);
            node queryDer = query(medio+1,fin,hijoDer,i,j);

            node resultado; 
            resultado.maximo = max(queryIzq.maximo, queryDer.maximo);
            resultado.minimo = min(queryIzq.minimo, queryDer.minimo);
            return resultado;
        }
    }
}
int main() {
    
    
    init(0,3,0);
    query(0,7,0,6,7);
    return 0;
}