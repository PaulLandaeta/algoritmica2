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
}segmentTree[MAX_N*4];

void init(int inicio, int final, int nodoActual) { 
    if( inicio == final ) {
        segmentTree[nodoActual].max = a[inicio];
        segmentTree[nodoActual].min = a[inicio];
        segmentTree[nodoActual].sum = a[inicio];
        segmentTree[nodoActual].mult = a[inicio];
    } else {
        int mid = (inicio + final) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Ir por lado izquierdo
        init(inicio, mid, nodoIzquierdo );
        // Ir por lado derecho 
        init(mid+1, final, nodoDerecho);

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].mult = segmentTree[nodoIzquierdo].mult * segmentTree[nodoDerecho].mult;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);
    } 
}


node query(int inicio, int final, int nodoActual, int izquierda, int derecha ) {
    if(izquierda<=inicio && final <= derecha ) {
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
        result.mult = maxIzquierdo.mult *  maxDerecho.mult;
        result.max = max(maxIzquierdo.max, maxDerecho.max);
        result.min = min(maxIzquierdo.min, maxDerecho.min); 
        return result;
    }      
}

void update(int inicio, int final, int nodoActual, int posicion, int valor ) {
    if(posicion < inicio || posicion > final ) {
        return ;
    }

    if( inicio == final ) {
        segmentTree[nodoActual].max = valor;
        segmentTree[nodoActual].min = valor;
        segmentTree[nodoActual].sum = valor;
        segmentTree[nodoActual].mult = valor;
    } else { 

        int mid = (inicio + final ) / 2; 
        int nodoIzquierdo = 2 * nodoActual + 1; 
        int nodoDerecho   = 2 * nodoActual + 2;
        // Actualizar por lado izquierdo
        update(inicio, mid, nodoIzquierdo, posicion, valor );
        // Actualizar por lado derecho 
        update(mid+1, final, nodoDerecho, posicion, valor );

        segmentTree[nodoActual].sum = segmentTree[nodoIzquierdo].sum + segmentTree[nodoDerecho].sum;
        segmentTree[nodoActual].mult = segmentTree[nodoIzquierdo].mult * segmentTree[nodoDerecho].mult;
        segmentTree[nodoActual].max = max(segmentTree[nodoIzquierdo].max,  segmentTree[nodoDerecho].max);
        segmentTree[nodoActual].min = min(segmentTree[nodoIzquierdo].min, segmentTree[nodoDerecho].min);

    }
}

int main() {
    input;
    output;
    int queries; 
    //a[-2,6,2,-1]

    // 4 1
    // P 1 4
    
    while(cin>>n>>queries) {
        for(int i=0;i<n;i++){
            cin>>a[i];
            if(a[i]>0) {
                a[i]=1;
            }else if(a[i]<0){
                a[i]=-1;
            }
        }
        init(0,n-1,0);
        for(int i=0;i<queries;i++) {
            char querie; 
            cin>>querie; 
            if('C' == querie) {
                int posicion, valor; 
                cin>>posicion>>valor; 
                if(valor>0) {
                    valor = 1;
                }else if(valor<0){
                    valor = -1;
                }
                update(0,n-1,0,posicion-1, valor);
            } else {
                int izquierda,derecha; 
                cin>>izquierda>>derecha;
                int result = query(0,n-1,0,izquierda-1,derecha-1).mult;
                if(result == 0)
                    cout<<'0';
                else if( result >0) {
                    cout<<'+';
                }else {
                    cout<<'-';
                }
            }
        }
        cout<<endl;
    }
    return 0;
}
