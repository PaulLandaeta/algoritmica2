#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000];
int parent[10000];
int rango[10000];
int sons[10000];

int n;
void init() {
    for(int i=0;  i<= n; i++) {
        parent[i] = i;
        rango[i] = 0;
        sons[i] = 1;
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
    if(xRaiz == yRaiz ) 
        return;

    if(rango[xRaiz] > rango[yRaiz]) {
        parent[yRaiz] = xRaiz;
        sons[xRaiz] = sons[xRaiz] + sons[yRaiz];
    } else {
        parent[xRaiz] = yRaiz;
        if(rango[xRaiz] == rango[yRaiz]) {
            rango[yRaiz]++;
        }
        sons[yRaiz] = sons[xRaiz] + sons[yRaiz];
    }
}

int main() {
    input;
    int t; 
    cin>>t; 
    while(t--) {
 cin>>n;
    init();
    int nrounionRangoes; 
    cin>>nrounionRangoes;
    while(nrounionRangoes--) {
        int x,y;
        cin>>x>>y; 
        unionRango(x,y);
    }
    int maxFriends = -1;
    for(int i=0;i<=n;i++){ 
       if(parent[i]==i) {
           maxFriends = max(maxFriends, sons[i]);
       }
    }
    cout<<maxFriends<<endl;
    }
    
   
   
    return 0;
}





