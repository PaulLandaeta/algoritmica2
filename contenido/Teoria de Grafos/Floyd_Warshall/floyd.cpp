#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int V; /// Vertices 
// Grafo va estar en una matriz de V*V
int GRAFO[100][100];
void floyd() { // n^3 100 vertices mas de 100 sera lento 
    for(int k = 0; k<V; k++) 
        for(int i = 0; i<V; i++) 
            for(int j = 0; j<V; j++) 
                GRAFO[i][j] = min(GRAFO[i][j], GRAFO[i][k] + GRAFO[k][j]);
    
}