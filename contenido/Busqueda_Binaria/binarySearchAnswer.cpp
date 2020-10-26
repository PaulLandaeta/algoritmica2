#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n; 
int v[100010];
bool f(int k) {
    for(int i=1;i<=n;i++) {
        if(v[i]-v[i-1]>k) {
            return false;
        }
        if(v[i]-v[i-1]==k) {
            k--;
        }
    }
    return true;
}


int binarySearch() {
    long long left  = 0;
    long long right = 2*v[n];  // ojo 
    long long answer = right;
    while( left < right - 1 ) {
        long long mid = left +(right -left)/2;
        if(f(mid)) {
            answer = mid;
            right = mid;
        }
        else{
            left = mid;
        }
    }
    return answer;
}




int main() {
    input;
    output;
    int t; cin>>t; int cases = 1;
    while(t--) {
        cin>>n;
        // v[0] sera 0 que significa el piso;
        for(int i=1;i<=n;i++) {
           cin>>v[i];
        }
        cout<<"Case "<<cases++<<": "<<binarySearch()<<endl;
    }
    return 0;
}