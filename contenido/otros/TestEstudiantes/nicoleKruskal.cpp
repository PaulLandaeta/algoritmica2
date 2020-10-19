#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 1000000
using namespace std;
 
int parent[MAX_N];
int rango[MAX_N];
 
int N, E;
void init()
{
    for (int i = 0; i <= MAX_N; i++)
    {
        parent[i] = i;
        rango[i] = 0;
    }
}
 
int find(int x)
{
    if (x == parent[x])
    {
        return x;
    }
    else
    {
        parent[x] = find(parent[x]);
        return parent[x];
    }
}
 
bool sameComponent(int nodeA, int nodeB)
{
    return find(nodeA) == find(nodeB);
}
 
int sameComponent2(int nodeA, int nodeB)
{
    return parent[nodeA] == parent[nodeB];
}
 
void unionRango(int x, int y)
{
    int xRaiz = find(x);
    int yRaiz = find(y);
    if (rango[xRaiz] > rango[yRaiz])
    {
        parent[yRaiz] = xRaiz;
    }
    else
    {
        parent[xRaiz] = yRaiz;
        if (rango[xRaiz] == rango[yRaiz])
        {
            rango[yRaiz]++;
        }
    }
}
 
struct Arista
{
    int origen;
    int destino;
    int peso;
    Arista() {}
    bool operator<(const Arista &a) const
    {
        return peso < a.peso;
    }
} aristas[MAX_N];
 
Arista MST[MAX_N]; //n-1 artistas
 
void kruskal(int nroNodos, int nroAristas)
{
    int origen, destino, peso;
    int total = 0;
    int nAristasArbol = 0;
    init(); //Iniciar union find
 
    sort(aristas, aristas + nroAristas); //arista con menor peso a la de mayor peso
 
    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;
        if (!sameComponent(origen, destino))
        {
            total += peso;
            MST[nAristasArbol++] = aristas[i];
            unionRango(origen,destino);
        }
    }
 
    if (nAristasArbol ==nroNodos -1)
    {
        cout<<total<<endl;
    }   
}
 
int main(){
    int printLine = 0;
	while(cin>>N && N){
        if(printLine) {
            cout<<endl;
        }
        printLine=1;
	memset(aristas,-1,sizeof(aristas));
    memset(MST,-1,sizeof(MST));
    cout<<"nodes:"<<N<<endl;
		 for (int i = 0; i < N-1; i++)
    {
        scanf("%d %d %d", &aristas[i].origen, &aristas[i].destino,&aristas[i].peso);
    }
    kruskal(N,N-1); 
    memset(aristas,-1,sizeof(aristas));
    memset(MST,-1,sizeof(MST));
    int Ex;
    cin>>Ex;
    for (int i = 0; i < Ex; i++)
    {
        scanf("%d %d %d", &aristas[i].origen, &aristas[i].destino,&aristas[i].peso);
    }
    cin>>E;
    for (int i = Ex; i <E+1; i++)
    {
        scanf("%d %d %d", &aristas[i].origen, &aristas[i].destino,&aristas[i].peso);
    }
    kruskal(N,E+Ex);
    cout<<endl;
	}
 
}