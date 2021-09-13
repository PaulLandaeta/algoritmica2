#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;   
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef map<int, int> mii;

ll _sieve_size;
bitset<10000010> bs;                             // 10^7 is the rough limit
vll p;    //[2,3,5,7]                                       // compact list of primes
// bs [0,0,1,1,0,1,0,1,....]
void sieve(ll upperbound) {                      // range = [0..upperbound]
  _sieve_size = upperbound+1;                    // to include upperbound
  bs.set();                                      // all 1s
  bs[0] = bs[1] = 0;                             // except index 0+1
  for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
    // cross out multiples of i starting from i*i
    for (ll j = i*i; j < _sieve_size; j += i) bs[j] = 0;
    p.push_back(i);                              // add prime i to the list
  }
}

// int dp[200000000];
// void f(vector<int> &v) {
//     dp[0] = true;
//     for(int i = 0; i < v.size(); i++) {
//         for(int j = 0; j<100000000;j++){
//             if(v[i] <= j) {
//                 dp[j] = dp[j] || dp[j-v[i]];
//             }
//         }
//     }
// }

bool isPrime(ll N) {                             
  if (N < _sieve_size) return bs[N];             
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   
} 

vll primeFactors(ll N) {                         
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i){ 
      while (N%p[i] == 0) {                        
        N /= p[i];                                 
        factors.push_back(p[i]);
      }
  }
    
  if (N != 1) factors.push_back(N);              
  return factors;
}
int dp[100000010]
int f(int k){
  if(k == 0) return 1;
  if( dp[k] == -1) {
    int ans = 0;
    for(int i = 0; i < n; i++) {
      if(k - v[i] >= 0) {
          if(k%v[i] == 0) {
            dp[k] = 1;
            return 1;
          }
          else {
            ans || = f(k-v[i]);
          }
      }
      dp[k] = ans;
    }
  }
  return dp[k];
}

int main() {
  input;
  output;
  cout<<1000<<endl;
  for(int i = 0; i <1000; i++) {
    cout << i+4000<<" ";
  }
  cout<<endl;
  cout<<10000<<endl;
  for(int i = 0;i<10000;i++) {
    // random number from 1 to 100000000
    int r = rand()%100000000+1;
    cout << r<<" ";
  }
    return 0;
}