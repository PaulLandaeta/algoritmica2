#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n; 
int x,y,p,q;
bool f(int t) {
    int a = p*t-x;
    int b = q*t-y;
    return p*t-x >= 0 && a<=b && q*t-y >= 0; 
}


int binarySearch() {
    long long left  = 2;
    long long right = 1e10;  
    long long answer = -1;
    while( right - left > 1) {
        long long t = left +(right -left)/2;
        if(f(t)) {
            answer = max(p*t-x,q*t-y);
            right = t;
        }
        else{
            left = t;
        }
    }
    return answer;
}




int main() {
    input;
    output;
    int t; cin>>t;
    while(t--) {
        cin>>x>>y>>p>>q;
        cout<<binarySearch()<<endl;
    }
    return 0;
}