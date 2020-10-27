#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int parent[10000];
int rango[10000];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
    }
}

int find(int x) {
    if(x == parent[x]) {
        return x;
    }
    else {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}

void unionRango(int x,int y) { 
    int xRaiz = find(x);
    int yRaiz = find(y);
    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
    }
}

int main() {
    input;
    cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        unionRango(x,y);
    }
    for(int i=0;i<=n;i++){ 
        cout<<"["<<i<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<parent[i]<<"] ";
    }
    cout<<endl;
    for(int i=0;i<=n;i++){ 
        cout<<"[" <<rango[i]<<"] ";
    }
    cout<<endl;


    return 0;
}





