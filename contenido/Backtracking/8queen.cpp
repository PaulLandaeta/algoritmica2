#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

int rows[8]; 
// row = [1,0,0,0,0,0,0,0]
//        0 1 2 3 4 5 6 7     8  


bool isValid(int row, int column) {
    for(int prev = 0; prev < column; prev++) {
        if(rows[prev] == row || abs(rows[prev]-row) == abs(prev-column)) {
            return false;
        }
    }
    return true;
}

void solve(int column) { // column es la columna actual 
    if (column == 8) {
        for(int i = 0 ; i<8; i++) {
            cout<<"[" << rows[i]+1<< "]";
        }
        cout<<endl;
        return;
    }   // N 
    for(int row=0;row<8;row++) {   // N 
        // como se si debo elimnar 

        if(isValid(row,column)){  // en ese cuadro   N 
            
            rows[column] = row;    // r es la fila donde estoy guardando la reina;//  2 
            //cout<<"fila "<<rows[column]<<endl;
            //cout<<row<<' '<< column<<endl;
            solve(column + 1);  // OJO nunca mandar column++ o column--    T(n-1)   0 1 2 3 4 5 6 7 
        }
    }
}
int main () {
    solve(0);
}