#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;  
// [index][siTope][cont]
// 100000  
// por verificar la tercera 
long long dp[100][2][500];

string toStringBinary(long long currentNumber) {
    string number = "";

    while(currentNumber!=0) {
        char digit = (currentNumber%2) + '0';
        currentNumber /= 2;
        number = digit  + number;
    }
    return number;
}

long long solveDP(string & number, long long index, bool tight, long long cont) {
    
    // CASE BASE
    if(index == number.length()) {
        return cont; 
    }

    if(dp[index][tight][cont] == -1) {
        long long numberOfOnes = 0;
        if(tight) {
            if(number[index] == '1') {
                numberOfOnes += solveDP(number,index+1,0,cont) + solveDP(number,index+1,1,cont+1);
            } else {
                numberOfOnes += solveDP(number,index+1,tight,cont);
            }
        }else {   
            numberOfOnes += solveDP(number,index+1,0,cont) + solveDP(number,index+1,0,cont+1);
        }
        dp[index][tight][cont] = numberOfOnes;
    }
    return dp[index][tight][cont];
}

int main() {
    input;
    long long a,b;
    while(cin>>a>>b){
        string numberA = toStringBinary(a-1);
        string numberB = toStringBinary(b);
        //cout<<numberA<<endl;
        //cout<<numberB<<endl;

        memset(dp,-1, sizeof(dp));
        long long solB = solveDP(numberB,0,1,0);
        memset(dp,-1, sizeof(dp));
        long long solA = solveDP(numberA,0,1,0); 

        cout<<solB-solA<<endl;

    }
    
}


