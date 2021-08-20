#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
string wordA,wordB;

int dp[10000][10000];
int solve(int posA, int posB) {
    if(posA == -1){
        return posB + 1;
    } 
    if(posB == -1){ 
        return posA + 1;
    }
    if(dp[posA][posB] == -1){
        int minimoEditDistance = 100000000;
    
        // editar el caracter
        int sonDiferentes  = wordA[posA] != wordB[posB]; // True o False -> 1 o 0
        minimoEditDistance = min(minimoEditDistance,solve(posA-1, posB-1)+sonDiferentes);
        // eliminar el caracter
        minimoEditDistance = min(minimoEditDistance,solve(posA-1, posB)+1);
        // adicionar el caracter
        minimoEditDistance = min(minimoEditDistance,solve(posA, posB-1)+1);

        dp[posA][posB] = minimoEditDistance;
    }
    return dp[posA][posB];
}
    
    

int main()
{

    wordA = "AEO";
    wordB = "AC";
    memset(dp,-1,sizeof(dp));
    cout << solve(wordA.length()-1, wordB.length()-1) << endl; 

    return 0;
}