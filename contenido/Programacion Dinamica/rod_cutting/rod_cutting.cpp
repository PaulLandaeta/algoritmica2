#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int length[] = {1,3,5,7}; // tamanio 4
int precios[] = {2,15,20,50};  // 7 = 50  + 3 =15 = 65 5 = 60 47 20 

int dp[100000];
int solve_dp(int tamanioBarra) { // 10 dp[10] 10 -1 10- 3  10-5 10 -7 
    if(tamanioBarra == 0) {
        return 0;
    }
    // sizeof(length)/sizeof(length[0]) me da el tamanio del array
    if(dp[tamanioBarra] == -1) { // que para ese tamanio de barra no se haya calculado
        int gananciaMaxima = -1; // voy a calcular la ganancia maxima
        for(int i = 0; i < sizeof(length)/sizeof(length[0]); i++) { // voy hacer los cortes de todo tipo
            if(tamanioBarra >= length[i]) { // puedo hacer el corte de ese tamanio
                gananciaMaxima = max(gananciaMaxima,precios[i] + solve_dp(tamanioBarra - length[i]));
            }
        }
        dp[tamanioBarra] = gananciaMaxima;
    }
    return dp[tamanioBarra];
}


int main() {
    memset(dp, -1, sizeof(dp));
    cout<<solve_dp(10)<<endl;
}   