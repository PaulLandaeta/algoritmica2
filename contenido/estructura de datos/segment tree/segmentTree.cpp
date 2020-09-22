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

    return 0;
}

