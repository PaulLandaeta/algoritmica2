#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int v[10000]; 
int parents[10000];
int rango[10000]; 

void init() {
    for(int i = 0; i<10000; i++) {
        parents[i] = i; 
        rango[i] = 0; 
    }
}

int find(int node) {
    if(node != parents[node]) {
        parents[node] = find(parents[node]);
    }
    return parents[node];
}
void unionAB(int nodeA,int nodeB) {
    int rootA = find(nodeA);
    int rootB = find(nodeB);
    if( rango[rootA] > rango[rootB]) {
        parents[rootB] = rootA; 
    }else {
        parents[rootA] = rootB; 
        if(rango[rootA] == rango[rootB] ) {
            rango[rootB]++;
        }
    }
}

int main() {
    input;
    init();
    int n,q;
    cin>>n>>q;
    while(q--) {
        int a,b;
        cin>>a>>b;
        unionAB(a,b);
    }
    int manzanos = 0;
    for (int i=1;i<=n;i++) {
        if(parents[i] == padre[Paul]){
            if(i != paul)
                cout<<i<<endl;
        }
    }
   // cout<<manzanos<<endl;
}