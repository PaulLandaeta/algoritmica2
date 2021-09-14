#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
using namespace std; 
int n = 1024;
double A[1030];

void init(){
    int cnt = -1;
    for(int i = 0; i < 32; i++) {
        for(int j = 0; j < 32; j++) {
            double p = pow(2, i) * pow(3, j);
            A[cnt++] = p;
        }
    }
    sort(A, A + n);
}

 

int main(){
    input;
    int x;
	init();
    while(scanf("%d", &x) == 1 && x){
        bs(x);
    }
    return 0;
}