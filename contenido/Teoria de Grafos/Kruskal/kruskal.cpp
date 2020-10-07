#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 100010

using namespace std; 


int v[10000];
int parent[10000];
int rango[10000];

int nroNodos, nroAristas; 

void init() {
    for(int i=0;  i<= MAX_N; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

int sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

int sameComponent3(int nodeA,int nodeB) {
    return parent[nodeA] == parent[nodeB];
}
//  No seguro
int sameComponent2(int nodeA,int nodeB) {
    return nodeA == nodeB;
}

void unionRango(int x,int y) { cd 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

struct Arista{ 
    int origen;
    int destino; 
    int peso; 
    Arista(){}

    bool operator<(const Arista &a) const {
        return peso < a.peso
    }
}aristas[MAX_N]; 

Arista MST[MAX_N]; // n-1 aristas 


void kruskal() {
    int origen, destino, peso;
    int total = 0;
    int numAristasArbol = 0;
    init(); // union Find 

    sort(aristas,arista + nroAristas);  // la arista con menor peso hasta la de mayor peso 


    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) {
            total+=peso; 
            MST[numAristasArbol++] = aristas[i];
            unionRango(origen,destino);
        }
    }

    if(numAristasArbol != nroNodos -1 ) {
        cout<<"no existe un arbol de expansion minima";
    } else {
        for(int i=0;i<nroNodos-1;i++) {
            cout<<MST[i].origen<<endl;
            cout<<MST[i].destino<<endl;
            cout<<MST[i].peso<<endl;
        }
        cout<<total<<endl;
    }

}