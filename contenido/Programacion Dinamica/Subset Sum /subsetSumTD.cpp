#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;  

int dp[100][1000]; 

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

    read(n,k);
    read(v);
    sort(v);
    menset(dp, -1, sizeof(dp));
    cout<< solve(n-1,k)<<endl;
}