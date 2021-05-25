//Dado 2 lados de un tri·ngulo a y b, se desea contar el n˙mero de valores que podrÌa tener
//el lado c para formar un tri·ngulo v·lido
#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;


int main(){
    string cad;
    map<string,int> m;
    while(cin>>cad){
        m[cad]++;
    }
    for (map it = m.begin(); it != m.end(); ++it)
        if(it->second == 1) {
           cout<< it->first<<endl; 
        }
    }
}



