#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
// Variables
#define MAX_N 100010

using namespace std; 

// Variables static

int n, a[MAX_N];


struct node{
    int sum, mult , min, max;
}segmentTree[MAX_N*2];

void init(int inicio, int final, int nodoActual) { 
    if( inicio == final ) {
        segmentTree[nodoActual].max = a[inicio];
        segmentTree[nodoActual].min = a[inicio];
        segmentTree[nodoActual].sum = a[inicio];
    } else {
        int mid = (inicio + final) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Ir por lado izquierdo
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho 
        init(mid+1, final, nodoDerecho);

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
    } 
}


node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {
    if(inicio >= izquierda && final <= derecha ) {
        return segmentTree[nodoActual];
    }
    
    int mid = (inicio + final ) / 2; 
    int nodoIzquierdo = 2 * nodoActual + 1; 
    int nodoDerecho   = 2 * nodoActual + 2;

    if(derecha <= mid ) {
        return query(inicio, mid, nodoIzquierdo, izquierda, derecha); 
    } else if(izquierda > mid) {
        return query(mid+1, final, nodoDerecho, izquierda, derecha);
    } else {
        node maxIzquierdo = query(inicio, mid, nodoIzquierdo,izquierda,derecha);
        node maxDerecho   = query(mid+1, final, nodoDerecho,izquierda,derecha);

        node result ; 
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min); 
        return result;
    }      
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio && posicion > final ) {
        return ;
    }

    if( inicio == final ) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
        segmentTree[nodoActual].sum = valor;
    } else { 

        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor );

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max); // -inf
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);  // inf

    }
}

int main() {
    input;
    cin>>n;
    for(int i = 0; i < n; i++) {
        cin>>a[i];
    }
    // Inicializar Segment Tree 
    init(0,n -1, 0);    

    for(int i=0;i<2*n;i++) {
        cout<<"[ "<<segmentTree[i].sum<<" ]";
    }
    cout<<endl;
    int queries;
    cin>> queries; 
    for(int i = 0 ;i <queries ; i++) {
        int izquierda, derecha; 
        cin>> izquierda >> derecha; 
        cout<<"El maximo de "<<izquierda<<" y "<< derecha << " es: "<<query(0,n-1,0,izquierda,derecha).max<<endl;
    }

    update(0,n-1,0,5,8);
    cout<<"El maximo de "<<0<<" y "<< 6 << " es: "<<query(0,n-1,0,0,6).max<<endl;




    /* if('max' == consulta) {

    }*/
    return 0;
}

