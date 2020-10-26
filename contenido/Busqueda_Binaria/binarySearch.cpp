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
    long  left  = 0;
    long long  right = 2*v[v.size()-1];  // ojo 
    mid = (left + right) /2; 
    while( left<right ) {
        if(f(mid)) {
            right = mid -1;
        }
        else{
            left = mid+1;
        }
        mid = (left+right)/2;
    }
    return mid;


}




int main() {
    input;
    int t; cin>>t;
    while(t--) {
        cin>>n;
        // v[0] sera 0 que significa el piso;
        for(int i=1;i<=n;i++) {
           cin>>v[i];
        }
    }
    return 0;
}