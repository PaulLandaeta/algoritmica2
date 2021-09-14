#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int n;
string graph[1010];

void solve(int fila, int columna) { // column es la columna actual 
    if(fila>=0 && fila<n && columna>=0 && columna<n && graph[fila][columna]=='1') {
        graph[fila][columna] = '0';
        solve(fila+1, columna); // abajo
        solve(fila-1, columna); // arriba
        solve(fila, columna+1); // derecha
        solve(fila, columna-1); // izquierda
        solve(fila+1, columna+1); // abajo derecha
        solve(fila-1, columna-1); // arriba izquierda
        solve(fila-1, columna+1); // arriba derecha
        solve(fila+1, columna-1); // abajo izquierda
    }
    return;
}
int main () {
    input;
    while(cin>>n) {
        for(int i = 0; i<n; i++) {
            cin>>graph[i];
        }
        int nroIslas = 0;
        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(graph[i][j] == '1') {
                    solve(i,j);
                    nroIslas++;
                }
            }
        }
        cout<<nroIslas<<endl;
    }
}