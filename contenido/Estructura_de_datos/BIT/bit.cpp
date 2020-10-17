#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int BIT[10001];
int tamanhoVector;

void update(int posicion, int valor ) {
    for(;posicion <= tamanhoVector ;posicion += posicion&-posicion) {
        BIT[posicion] += valor;
    }
}

int query(int posicion){ // F(x) = 0+....+x 
    int result = 0 ;
    for(;posicion > 0 ;posicion -= posicion&-posicion) {
        result += BIT[posicion];
    }
    return result; 
}

int query2(int inicio, int final) {
    return query(final)-query(inicio-1);
}

int main() {
    input;
    int queries; 
    cin>>tamanhoVector>>queries; 
    for(int i=0;i<tamanhoVector;i++) {
        int x;cin>>x;
        update(i+1, x);
    }
    for(int i =0 ;i<= tamanhoVector; i++){
        cout<<"["<< BIT[i]<<"]";
    }
    cout<<endl;
   while(queries--) {
        int x,y; cin>>x>>y;
        cout<<query2(x,y)<<endl;
    }
    return 0;
}