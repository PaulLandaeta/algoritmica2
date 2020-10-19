#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 10000

using namespace std; 

int v[MAX_N];
int parent[MAX_N];
int rango[MAX_N];

int N, E; 

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

bool sameComponent(int nodeA,int nodeB) {
    return find(nodeA) == find(nodeB);
}

void unionRango(int x,int y) {
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
    double peso; 
    Arista(){}

    bool operator<(const Arista &a) const {
        return peso < a.peso;
    }
}aristas[MAX_N]; 

Arista MST[MAX_N]; 

double kruskal(int nroNodos, int nroAristas) {
    int origen, destino;
    double peso;
    double total = 0;
    int numAristasArbol = 0;
    init();
    sort(aristas,aristas + nroAristas);
    for (int i = 0; i < nroAristas; i++){
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if(!sameComponent(origen,destino)) {
            total+=peso; 
            MST[numAristasArbol++] = aristas[i];
            unionRango(origen,destino);
        }
    }
    return total;
}

double distancia(double pointX1,double pointY1, double pointX2, double pointY2) {
    double x = pointX2 - pointX1;
    double y = pointY2 - pointY1;
    return sqrt(x*x+y*y); 
}

int main(){
    input;
    int testCases; 
    cin>>testCases; 
    while(testCases--) {
        cin>>N;
        double points[2][N];
        for( int i = 0 ; i < N ; ++i ){
            cin>>points[0][i]>>points[1][i];
        }
        int nroVertice=0; 
        for( int i=0;i<N-1;i++) {
            for(int j=i+1;j<N;j++) {
            aristas[nroVertice].origen = i;
            aristas[nroVertice].destino = j;
            aristas[nroVertice].peso = distancia(points[0][i],points[1][i],points[0][j],points[1][j]); 
            nroVertice++;
            }
        }
        double total = kruskal(N,nroVertice);
        printf("%.2f\n",total);
        if(testCases>0){
            cout<<endl;
        }
    }
    return 0;
}