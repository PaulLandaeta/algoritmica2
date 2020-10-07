#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;   

// vector { 2, 5 , 9, 12 }
//          0   1  2   3
// 12
bool subsetSolve(int vec[], int n, int k) {

    bool dp[n+1][k+1];

    for(int i=0; i<=n; i++) {
        dp[i][0] = true; 
    }

    for( int i = 1; i<=n; i++ ) {
        for(int j = 1; j<=k ; j++) {
            if( vec[i-1] < j ) {
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = dp[i-1][j] || dp[i-1][j-vec[i]]; 
            }
        }
    }


}