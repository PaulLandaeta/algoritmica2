#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 
#define MAX_N 101        // Tarea 
 
int grafo[MAX_N][MAX_N];   // capacidad + flujo  
int path[MAX_N];    
int nodes;       // camino b: b <- a     
// path 0->3->2->4    
// [0,-1,3,0,2,-1, 4]
//  0  1 2 3 4, 5, 6
// Edmonds Karp 
// DINIC 
int maxFlow(int s,int t) { 
    // s nodo inicial 
    // t nodo final 
    int maxFlow = 0;
    while(true) {// empezamos con true porque nosotros nunca sabemos si tenemos flujo
        //BFS complejidad de O(A+E)
        memset(path, -1, sizeof(path));//vector visitado, todos empiezan con -1, que no los estamos visitando aun
        queue<int> Q;
        Q.push(s);//aniadimos el nodo fuente, decimos de donde partimos
        path[s] = s;//s- le aniadimos a camino 
        while(!Q.empty() && path[t]==-1) {
            int currentNode = Q.front();//saco la s
            Q.pop();//elimino de la cola
            for(int i = 0 ; i < nodes ; i++) {//buscamos a sus amigos
                if(path[i]==-1 && grafo[currentNode][i] > 0) {  // puedo visitar? //primero pregunto si tiene caoacidad y luego si ha sido visitado
                    path[i] = currentNode;                       // guardar camino, le aniadimos al camino
                    Q.push(i);                                  // agregar a la cola, metemos a la cola el nodo
                }   
            }
        }
 
        if(path[t]==-1) {//preguntamos si hemos llegado a T, si hemos llegado a T, el pat tiene que ser f=diferente a -1
            break;
        }
        int minFlow = 1e9;//ponemos al minimo como un numero maximo, es como un infinito
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {
            minFlow = min(minFlow,grafo[from][to]);//sacamos las capacidades de las aristas
            //agarramos los minimos de las aristas
 
        }
 
        //peor de los casos, que recorra todos los vertices(V) menos 1
        // Sumamos al grafo residual y restamos ese minimo al grafo capacial  // sumar todos os diferentes a -1 
        for(int from = path[t],to = t; from!=to ; from = path[to = from]) {//si no hicieramos esto, el algoritmo no va a funcionar
            grafo[to][from] += minFlow;//grafo capacidad
            grafo[from][to] -= minFlow;//grafo residual
        }
 
        maxFlow += minFlow;//lo sumamos al maximo flujo
       //2V+E-1 complejidad y se multiplicara por el numero de flujos
       // flujos * 2V + flujos*E - flujos
       //flujos*E(ARISTAS), la clave es saber cuantos deben ser los flujos, debe ser un cruadrado, un e^2
    }
    return maxFlow;
}
 
 
 
int main() {
input;
output;
int  nroCases = 1; 

while(cin>>nodes && nodes) {
 
    int s,t,aristas; //nodo S que sera la fuente o source, T que sera la terminal y el numero de aristas
    cin>>s>>t>>aristas;
    s--;t--;
    memset(grafo,0,sizeof(grafo));
     for(int i=0;i<aristas;i++) {
        int from, to, capacity; 
        cin>>from>>to>>capacity;
        from--;to--;
        grafo[from][to] += capacity;
        grafo[to][from] += capacity;          // camino capacidad
        // cout<<grafo[from][to];
        //if(grafo[to][from] == null){
                // grafo[to][from] = 0;                //  flujo camino residual, dijimos que comenzaban con cero
        //}
 
        //al mismo tiempo que creamos hacemos que las aristas tengan tamanio cero.
    }
   // for(int i=0;i<6;i++){
   //     for(int j=0;j<6;j++){
   //         cout<<grafo[i][j];
    //    }
   //     cout<<endl;
   // }
    cout << "Network " << nroCases++ << '\n';
    cout<<"The bandwidth is "<<maxFlow(s,t)<<"."<<endl;
    }    
}
/*ejercicio de prueba uDebug
4
1 4 5
1 2 20
1 3 10
2 3 5
2 4 10
3 4 20
4
1 4 6
1 2 20
1 3 10
2 3 5
3 2 3
2 4 10
3 4 20
4
1 4 6
1 2 20
1 3 10
2 3 5
2 3 3
2 4 10
3 4 20
0*/
/*resultados esperados:
Network 1
The bandwidth is 25.
 
Network 2
The bandwidth is 28.
 
Network 3
The bandwidth is 28.
*/