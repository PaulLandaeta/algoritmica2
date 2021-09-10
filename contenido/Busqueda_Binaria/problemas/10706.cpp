#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
long long n; 
int v[100010];
int mid;
long long numeros[31500];
int s = 1;
int tope = 4;
string sec = "";
// int numeros[]= {0,1,3,6,10...56...,2147483647};
void llenadoNumeros(){
    long long acum = 0;

    for(int i = 1; i < 31500;i++){
        int cantidadDigitos = log10(i) + 1;
        acum +=cantidadDigitos;
        numeros[i] = acum+numeros[i-1];
        
        sec+=to_string(i);
    } 
    cout<<"este"<<numeros[31500-1]<<endl;
}


bool f(long long number) {
    return number < n;
}
int bs() {
    int ini = 0;
    int fin = 31500 - 1;
    int mid = (ini + fin) / 2;
    int pos = -1;
    while(ini <= fin ) {
        if(f(numeros[mid])) {  /// MOdificar la funcion de condicion
            pos = mid;
            ini = mid + 1;
            
        } else {
            fin = mid - 1;
        }
        mid = (ini + fin) / 2;
    }
    if(f(numeros[pos])) {
        return pos;
    }
    return -1;
}
//2181206745
//2147483647

int main() {
    input;
    output;
    llenadoNumeros();
    int tcases;
    cin>>tcases;
    while(tcases--){
        cin>>n;
        int pos = bs();
        // 10 - 6 = 4 -1 = 3
        cout<< sec[n - numeros[pos]-1]<<endl;
    }
    return 0;
}