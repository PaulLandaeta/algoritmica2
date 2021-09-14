#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;
int n;
int x;
int A[100000];
bool f(int number) {
    return number*number > x;
}

void bs() {
    int ini = 0;
    long long fin = 100000000000000 - 1;
    int pos = -1;
    while(ini < fin ) {
        int mid = (ini + fin) / 2;
        if(f(A[mid])) {  /// MOdificar la funcion de condicion
            pos = mid;
            fin = mid -1 ;
        } else {
            ini = mid;
        }
    }
    if(A[pos] == pos*pos) {
        cout<<A[pos]<<endl;
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