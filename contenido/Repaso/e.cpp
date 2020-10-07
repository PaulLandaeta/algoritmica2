#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std;  

long long dp[12][2][100];
int k; 

string toString(long long currentNumber) {
    string number = "";
    while(currentNumber!=0) {
        char digit = (currentNumber%10) + '0';
        currentNumber /= 10;
        number = digit  + number;
    }
    return number;
}

long long solveDP(string & number, int index, bool tight, int cont) {
    
    if(index == number.length()) {
        return cont; 
    }

    if(dp[index][tight][cont] == -1) {
        int limit = 9; 
        if(tight) {
            limit = number[index] - '0';
        }
        long long numberOfks = 0;
        for( int digit = 0 ; digit<= limit ;digit++) { 
            bool newTight;
            if( digit < (number[index] - '0')) {
                newTight = 0;
            }else {
                newTight = tight;
            }
            numberOfks += solveDP(number,index+1,newTight, cont+(digit==k));
            
        }
        dp[index][tight][cont] = numberOfks;
    }
    return dp[index][tight][cont];
}

int main() {
    input;
    int a,b;
    cin>>a>>b>>k;
    
    string numberA = toString(a-1);
    string numberB = toString(b);

    memset(dp,-1, sizeof(dp));
    long long solB = solveDP(numberB,0,1,0);
    cout<<solB<<endl;
    memset(dp,-1, sizeof(dp));
    long long solA = solveDP(numberA,0,1,0); 

    cout<< solB - solA <<endl;
    
    
}