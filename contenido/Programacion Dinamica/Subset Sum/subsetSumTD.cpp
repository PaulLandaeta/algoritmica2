#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;  

int dp[101][100000000]; 
int v[101];
bool solve(int index, int k) {
    if(index == 0) {
        if(k == 0){
            return true;
        }
        return false;
    }
    if(dp[index][k] == -1) {
        if(k-v[index]>=0) {
            dp[index][k] = solve(index-1, k-v[index]) || solve(index-1,k);
        }else {
            dp[index][k] = solve(index-1,k);
        }
    }
    return dp[index][k];
}

int main() {

 input;
    int n;
    cin >> n;
    memset(dp, -1, sizeof(dp));
    for(int i=0; i<n; i++) {
        cin>>v[i];
    }
    int queries;
    cin >> queries;
    while(queries--) {
        int k;
        cin >> k;
        if(solve(n-1, k))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}