#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int numeroEtiquetas; // n del vector
int people;          // 
int etiquetas[100000];

bool f(int k) {
    int lastPerson = 0;
    int currentPerson = 1;
    int numberPerson = 1;
    while(currentPerson < numeroEtiquetas) {
        if(etiquetas[currentPerson]- etiquetas[lastPerson] >= k) {
            numberPerson++;
            lastPerson = currentPerson; 
        }
        currentPerson++;
        if(numberPerson == people) {
            return true;
        }
    }
    return false;
}

int binarySearch() {
    long long left  = 0;
    long long right = etiquetas[numeroEtiquetas-1];  // ojo 
    long long answer = 0;
    while( left < right - 1 ) {
        long long mid = left +(right -left)/2;
        if(f(mid)) {
            answer = mid;
            left = mid;
        }
        else{
            right = mid;
        }
    }
    return answer;
}

int main() {
    input;
    int t;
    cin>>t;
    while(t--) {
        cin>>numeroEtiquetas>>people;
        for(int i=0;i<numeroEtiquetas;i++) {
            cin>>etiquetas[i];
        }
        sort(etiquetas,etiquetas+numeroEtiquetas);
        cout<<binarySearch()<<endl;
    }
}