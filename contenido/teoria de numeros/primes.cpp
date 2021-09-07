#include <bits/stdc++.h>
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

bool isPrime(ll N) {                             // good enough prime test
  if (N < _sieve_size) return bs[N];             // O(1) for small primes
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    if (N%p[i] == 0)
      return false;
  return true;                                   // slow if N = large prime
} // note: only guaranteed to work for N <= (last prime in vll p)^2

// second part
// N = 48/2 = 24/2 = 12 / 2 = 6 /2 = 3 / 3 = 1
// factors = {2,2,2,2,3}
// p = {2,3,5,7....}
vll primeFactors(ll N) {                         // pre-condition, N >= 1
  vll factors;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i){ 
      while (N%p[i] == 0) {                        // found a prime for N
        N /= p[i];                                 // remove it from N
        factors.push_back(p[i]);
      }
  }
    
  if (N != 1) factors.push_back(N);              // remaining N is a prime
  return factors;
}

// third part

int numPF(ll N) {
  int ans = 0;
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ++ans; }
  return ans + (N != 1);
}

int numDiffPF(ll N) {
  int ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i) {
    if (N%p[i] == 0) ++ans;                      // count this prime factor
    while (N%p[i] == 0) N /= p[i];               // only once
  }
  if (N != 1) ++ans;
  return ans;
}

ll sumPF(ll N) {
  ll ans = 0;
  for (int i = 0; i < p.size() && p[i]*p[i] <= N; ++i)
    while (N%p[i] == 0) { N /= p[i]; ans += p[i]; }
  if (N != 1) ans += N;
  return ans;
}
// N = 48 / 2 = 24 / 2 = 12 / 2 = 6 / 2 = 3 
// p = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47}
// i = 1 
// p[i] = 3
// ans = 1 * (4+1) = 5 * 2 = 10
// power = (2)  // contando los exponentes de los primos
// 2*2 < = 48
// 3*3 < = 3
int numDiv(ll N) {
  int ans = 1;                                   // start from ans = 1
  for (int i = 0; i < (int)p.size() && p[i]*p[i] <= N; ++i) {
    int power = 0;                               // count the power
    while (N%p[i] == 0) { N /= p[i]; ++power; }
    ans *= power+1; // (ep1+1)* (ep2+1)*.....*(epn+1)                             // follow the formula
  }
  return (N != 1) ? 2*ans : ans;                 // last factor = N^1
}

int main() {
  // first part: the Sieve of Eratosthenes
  sieve(10000000);                               // up to 10^7 (<1s)
  printf("%lld\n", p.back());               // primes.back() = 9999991
  for (int i = p.back()+1; ; ++i)
    if (isPrime(i)) {
      printf("The next prime beyond the last prime generated is %d\n", i);
      break;
    }
  printf("%d\n", isPrime((1LL<<31)-1));          // 8th Mersenne prime
  printf("%d\n", isPrime(136117223861LL));       // 104729*1299709
  printf("\n");

  // second part: prime factors
  vll r = primeFactors((1LL<<31)-1);              // slowest, Mersenne prime
  for (auto &pf : r)
    printf("> %d\n", pf);
  r = primeFactors(136117223861LL);              // slow, large prime
  for (auto &pf : r)
    printf("> %d\n", pf);                        // 104729*1299709
  r = primeFactors(142391208960LL);              // faster, large composite
  for (auto &pf : r)
    printf("> %d\n", pf);                        // 2^10*3^4*5*7^4*11*13
  // r = primeFactors(99999820000081LL);            // the limit: 9999991^2
  // for (auto &pf : r)
  //   printf("> %d\n", pf);
  // printf("\n");

  r = primeFactors(9999973LL*9999973LL);         // 9999973^2, the limit
  for (auto &pf : r)
    printf("> %d\n", pf);
  printf("\n");
  // r = primeFactors(9999991LL*9999991LL);         // 9999991^2, first crash
  // for (auto &pf : r)
  //   printf("> %d\n", pf);
  // printf("\n");

  // third part: functions involving prime factors
  printf("numPF(%d) = %d\n", 60, numPF(60));   // 2^2 * 3^1 * 5^1 => 4
  printf("numDiffPF(%d) = %d\n", 60, numDiffPF(60)); // 2^2 * 3^1 * 5^1 => 3
  printf("sumPF(%d) = %lld\n", 60, sumPF(60));   // 2^2 * 3^1 * 5^1 => 2 + 2 + 3 + 5 = 12
  printf("numDiv(%d) = %d\n", 60, numDiv(60)); // 1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 30, 60, 12 divisors
  printf("\n");
  
  return 0;
}