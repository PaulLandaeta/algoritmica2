#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

// el numero maximo sera 10^18
// 1000000000000000000
string number;
int dp[20][2][10];

/* 
* Digit DP para contar los numeros 
* donde la suma de los digitos sea un numero primo 
*/ 
int solve_dp(int pos, int mayor,int digito) {
    if(pos > number.size()) { // cuando la posicion exceda al numero dado
        return 0;
    }
    // Modificar de acuerdo al problema
    if(pos == number.size()) {
        if(digito == 5 || digito == 0) { // la suma de los digitos debe ser divisible por 9
            return 1;
        }
        else {
            return 0;
        }
    }
    if(dp[pos][mayor][digito] == -1) { // Pregunto si no lo he calculado 
        int tope = 9;
        if(mayor == true) {  // el numero que voy a crear puede llegar a ser mayor
            tope = number[pos]-'0';  // solo podemos usar los numeros de 0 al tope -- '3'-'0' =  51 - 48 = 3 
        }
        dp[pos][mayor][digito] = 0;
        for(int digito = 0; digito <= tope; digito++) {
            if(digito == tope ) {
                dp[pos][mayor][digito] += solve_dp(pos+1, true, digito);
            }
            else { // 0 1 2 
                dp[pos][mayor][digito] += solve_dp(pos+1, false, digito);
            }
        }
    }
    return dp[pos][mayor][digito];
}



int main(){

    // hallar los numeros que tengan 2 pares en su interior del rango 20 hasta 30

    int  a = 1;
    int b = 15;
    // calculando f(a)
    number = to_string(a-1);
    memset(dp, -1, sizeof(dp));
    int pares_hasta_a = solve_dp(0, true, 0);
    // calculando f(b)
    memset(dp, -1, sizeof(dp));
    number = to_string(b);
    int pares_hasta_b = solve_dp(0, true, 0);
    // total para f(a,b) = f(b) - f(a-1)
    cout<< pares_hasta_b - pares_hasta_a <<endl;
    return 0;
}