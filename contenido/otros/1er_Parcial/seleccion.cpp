/* 
La selección de fútbol se está preparando para las eliminatorias, para tal objetivo Farias 
convocó a jugadores de diferentes equipos, los jugadores son tímidos así que solo hablan 
con los de su mismo equipo. Se desea saber cuántos compañeros tiene el jugador X de su mismo equipo.
Entrada 
N M
nombre1, nombre2, nombre3, nombreN
nombre1, nombre2,
Nombre
Ejemplo 
7 2
Chumacero Wayar Lampe Conejo Bejarano Alvarez Castro
1 2 3 4 5 6 7 
Wayar Castro
2 7 
Conejo Bejarano 
4 5
Lampe
3
Salida
0 compañeros 
*/


/*
La selección de fútbol se está preparando para las eliminatorias, para tal objetivo 
Farias convocó a jugadores de diferentes equipos, los jugadores son tímidos así que solo 
hablan con los de su mismo equipo se desea saber cuantos equipos fueron convocados. 





Entrada 
N M
nombre1, nombre2, nombre3, nombreN
nombre1, nombre2,
nombre2, nombre3,
Ejemplo 
7 2
Chumacero Wayar Lampe Conejo Bejarano Alvarez Castro
Wayar Castro
Conejo Bejarano 
Salida
5 equipos 

*/

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
    int nrounionRangoes;
    while(t--) {
    cin>>n>>nrounionRangoes;
    map<int,string> names;
    map<string,int> numbers;
    for(int i=1;i<=n;i++) {
        string name;
        cin>>name;
        names[i] = name;
        numbers[name] = i;
    }

    init();

    while(nrounionRangoes--) {
        // nombreA, nombre B
        string x,y;
        cin>>x>>y; 

        unionRango(numbers[x],numbers[y]);
    }

    int soccerPlayer;
    cin>>soccerPlayer;
    cout<<sons[parent[find(numbers[soccerPlayer])]]-1<<endl;
    return 0;
}