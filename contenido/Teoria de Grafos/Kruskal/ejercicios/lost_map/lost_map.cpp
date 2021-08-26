#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
#define MAX_N 3125001
using namespace std;

int parent[MAX_N];
int rango[MAX_N];

int n, m;

void init()
{
    for (int i = 0; i < MAX_N; i++)
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
    long long origen;
    long long destino;
    long long peso;
    Arista() {}

    bool operator<(const Arista &a) const
    {
        return peso < a.peso;
    }
} aristas[MAX_N];

Arista MST[MAX_N];

int numAristasArbol = 0;

long long kruskal(int nroNodos, int nroAristas)
{

    long long origen, destino;
    long long peso;

    long long total = 0;

    init();
    sort(aristas, aristas + nroAristas);

    for (int i = 0; i < nroAristas; i++)
    {
        origen = aristas[i].origen;
        destino = aristas[i].destino;
        peso = aristas[i].peso;

        if (!sameComponent(origen, destino))
        {
            MST[numAristasArbol++] = aristas[i];
            unionRango(destino, origen);
        }
    }

    for (int i = 0; i < numAristasArbol; i++)
    {

        cout << MST[i].origen << " " << MST[i].destino<< endl;
    }

    return total;
}

int main()
{
    input;
    cin >> n;
    int k = 0;
    int tmp = 0;
    int grafo[n][n];
    for (int x = 0; x < n; x++)
    {
        for (int j = 0; j < n; j++)
        {
                cin >> grafo[x][j];
        }
    }

    for (int i = 0; i < n; i++){
        for (int j = i+1; j < n; j++){
            aristas[k].origen = i+1;
            aristas[k].destino = j+1;
            aristas[k].peso = grafo[i][j];
            k++;
        }
    }

    kruskal(n, k);

    return 0;
}