#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

bool es_valido(int tablero[][],int fila,int columna) {
    // Comprobamos que no exista reinas en la misma fila 
    for(int col = 0; col < 4; col++) {
        if(tablero[fila][col] == 1){
            return false;
        }
    }
    // comprobamos diagonales izq superior
    int row = fila, col = columna;
    while(row> 0 && col > 0) {
        if(tablero[row][col] == 1){
            return false;
        }
        row--;
        col--;
    }
    // comprobamos diagonal izq inferior
    row = fila, col = columna;
    while(row < 4 && col > 0) {
        if(tablero[row][col] == 1){
            return false;
        }
        row++;
        col--;
    }
    return true;
}
void solve_queen(int columna, int tablero[][]){   // f(pos, tablero)
    if( columna >= 4 ) { // ya puso todas las reinas  // CASO BASE
        print_solucion(tablero);
    }
    for (int row = 0; row < 4; row++) {
        if(es_valido(tablero,row,columna)){  // PODA
            tablero[row][columna] = 1;
            solve_queen(columna+1,tablero);
            tablero[row][columna] = 0;
        }
    }
}
void print_solucion(int tablero[][]){
    for(int fila = 0; fila < 4; fila++){
        for(int col = 0; col < 4; col++){
            printf("[%d]",tablero[fila][col]);
        }
        printf("\n");
    }
}
int main(){

}