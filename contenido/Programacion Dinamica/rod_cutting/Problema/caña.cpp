#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int length[3]; // tamanio 4
int N;
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
                gananciaMaxima = max(gananciaMaxima,1 + solve_dp(tamanioBarra - length[i]));
            }
        }
        dp[tamanioBarra] = gananciaMaxima;
    }
    return dp[tamanioBarra];
}


int main() {
    input;
    while(cin>>N){
        for(int i = 0 ;i<3;i++){
            cin>>length[i];
        }
        memset(dp, -1, sizeof(dp));
        cout<<solve_dp(N)<<endl;
    }
    
}   