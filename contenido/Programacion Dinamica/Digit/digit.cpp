#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;  

long long dp[12][2][83];
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

long long solveDP(string & number, int index, bool tight, int remainder) {
    
    // CASE BASE
    if(index == number.length()) {
        if(remainder == 0 ){
            return 1;
        }
        return 0; 
    }

    if(dp[index][tight][remainder] == -1) {
        int limit = 9;
        if(tight) {
            limit = number[index] - '0';
        }
        long long numberDivisibleK = 0;
        for( int digit = 0 ; digit<= limit ;digit++) { 
            bool newTight;
            if( digit < (number[index] - '0')) {
                newTight = 0;
            }else {
                newTight = tight;
            }
            numberDivisibleK += solveDP(number,index+1,newTight, (digit+remainder)%k);
        }
        dp[index][tight][remainder] = numberDivisibleK;
    }
    return dp[index][tight][remainder];
}
int main() {
    input;
    int a,b;
    cin>>a>>b>>k;
    
    string numberA = toString(a-1);
    string numberB = toString(b);

    memset(dp,-1, sizeof(dp));
    long long solB = solveDP(numberB,0,1,0);
    memset(dp,-1, sizeof(dp));
    long long solA = solveDP(numberA,0,1,0); 

    cout<< solB - solA <<endl;
    
    
}