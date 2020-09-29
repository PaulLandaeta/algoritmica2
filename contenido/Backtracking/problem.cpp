#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int rows[8];
int k=0;
bool isValid(int r, int c)
{
    for (int prev = 0; prev < c; prev++)
    {
        if (rows[prev] == r || abs(rows[prev] - r) == abs(prev - c))
        {
            return false;
        }
    }
    return true;
}

void solve(int column, int reqRow, int reqCol)
{ // column es la columna actual
    if (column == 8)
    {
        if (rows[reqCol] == reqRow)
        {
            k++;
            if (k<10)
            {
                cout<<' ';
            }
            cout<<k<<"      ";
            for (int i = 0; i < 8; i++)
            {
                cout << rows[i] + 1;
                if (i<7)
                {
                    cout<<' ';
                }
                
            }
            cout << endl;
        }
       
        return;
    }
    for (int row = 0; row < 8; row++)
    {
        // como se si debo elimnar

        if (isValid(row, column))
        {                                      // en ese cuadro
            rows[column] = row;                // r es la fila donde estoy guardando la reina;
            solve(column + 1, reqRow, reqCol); // OJO nunca mandar column++ o column--
        }
    }
}


int main()
{
    input;
    output;
    int database;
    cin >> database;
    while (database--)
    {
        k=0;
        int row, column;
        cin >> row >> column;
        cout << "SOLN       "
             << "COLUMN" << endl;
        cout << " #      "
             << "1 2 3 4 5 6 7 8" << endl;
        cout << endl;
        solve(0, row - 1, column - 1);
        if(database) 
            cout<<endl;
    }
}
