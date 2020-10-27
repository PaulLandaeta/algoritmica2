#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101        // Tarea 

int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];           // camino b: b <- a     
// path 0->3->2->4    
// [0,-1,3,0,2,-1, 4]
//  0  1 2 3 4, 5, 6
// Edmonds Karp 
// DINIC 
int maxFlow(int s,int t) { 
    // s nodo inicial 
    // t nodo final 
    int maxFlow = 0;
    while(true) {
        //BFS 
        memset(path, -1, sizeof(path));
        queue<int> Q;
        Q.push(s);
        path[s] = s; 
        while(!Q.empty() && path[t]==-1) {
            int currentNode = Q.front();
            Q.pop();
            for(int i = 0 ; i < MAX_N ; i++) {
                if(path[i]==-1 && grafo[currentNode][i] > 0) {  // puedo visitar? 
                    path[i] = currentNode;                       // guardar camino 
                    Q.push(i);                                  // agregar a la cola
                }   
            }
        }
        int minFlow = 1e9;
        if(path[t]==-1) {
            break;
        }
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]);
        }
        
        // Sumar y restar ese minimo                                            // sumar todos os diferentes a -1 
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            grafo[to][from] += minFlow;
            grafo[from][to] -= minFlow;
        }
        
        maxFlow += minFlow;
        
    }
    return maxFlow;
}



int main() {
input;
int nodes, vertices, nroCases = 1; 
while(cin>>nodes && nodes) {
    int s,t,vertices; 
    cin>>s>>t>>vertices;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<vertices;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        grafo[from][to] = capacity;          // camino capacidad
        grafo[to][from] = 0;                //  flujo camino residual 
    }
    cout<<maxFlow(s,t)<<endl;
    }    
}