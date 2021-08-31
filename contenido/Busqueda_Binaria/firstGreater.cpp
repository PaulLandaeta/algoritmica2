#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n;
int x;
int A[100000];
bool f(int number) {
    return number > x;
}

void bs() {
    int ini = 0;
    int fin = n - 1;
    while(ini < fin ) {
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {
            fin = mid;
        } else {
            ini = mid + 1;
        }
    }
    if(f(A[fin])) {
        cout<<A[fin]<<endl;
    }else {
        cout<<"No hay elementos mayores"<<endl;
    }
}
int main() {
    input;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>A[i];
    }
    cin>>x;
    bs();
    return 0;
}