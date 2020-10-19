#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

int rows[9][9];
int number, fila, columna;
bool isValid(int row, int column, int numbER)
{
    for (int prevRow = 0; prevRow < 9; prevRow++)
    {
        for (int prevCol = 0; prevCol < 9; prevCol++)
        {
            if (rows[row][column] != 0 || (rows[prevRow][prevCol] == numbER && (abs(prevRow - row) != abs(prevCol - column))) || (rows[prevRow][prevCol] == numbER && (abs(prevRow - row) == abs(prevCol - column) && abs(prevRow - row) < 3)) || ((rows[prevRow][prevCol] == numbER && (abs(prevRow - row) != abs(prevCol - column))) && ((abs(prevRow - row) < 3 && abs(prevCol - column) < 3))))
            {
                return false;
            }
        }
    }
    return true;
}

void solve(int row, int column, int numb)
{

    if (column == 9 && row == 9)
    {
        return;
    }
    for (int r = 0; r < 9; r++)
    {
        for (int c = 0; c < 9; c++)
        {
            if (isValid(r, c, numb))
            {
                rows[r][c] = numb;
                solve(r + 1, c + 1, numb);
            }
        }
    }
}

void generator()
{

    number = 1 + rand() % (9 + 1 - 1);
    fila = rand() % 9;
    columna = rand() % 9;
}

void generator2()
{
    fila = rand() % 9;
    columna = rand() % 9;
}
int main()
{
    srand(time(NULL));
    int counter = 0;
    for (int k = 0; k < 81; k++)
    {
        generator();
        if (isValid(fila, columna, number))
        {
            rows[fila][columna] = number;
        }
        cout << fila << ":" << columna << ":" << number << endl;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << "[" << rows[i][j] << "]";
                if ((9 - j - 1) % 3 == 0)
                {
                    cout << ' ';
                }
            }
            cout << endl;
            if ((9 - i - 1) % 3 == 0)
            {
                cout << endl;
            }
        }
    }
    cout << endl;

    solve(0, 0, 1);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << "[" << rows[i][j] << "]";
            if ((9 - j - 1) % 3 == 0)
            {
                cout << ' ';
            }
        }
        cout << endl;
        if ((9 - i - 1) % 3 == 0)
        {
            cout << endl;
        }
    }
cout << endl;
}