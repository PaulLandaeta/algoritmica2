#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

bool isValid(int sudoku[9][9], int r,int c,int v) {
    if(!validRow(sudoku,r,c,v)){
        return false;
    }
    if(!validColumn(sudoku,r,c,v)){
        return false;
    }
    if(!validInSubSquare(sudoku,r,c,v)){
        return false;
    }
    return true;
}
bool validRow(int sudoku[9][9], int r,int c,int v) {
    for(int i=0;i<9;i++){
        if(sudoku[r][i] ==v ) {
            return false;
        }
    }
    return true;
}

bool validColumn(int sudoku[9][9], int r,int c,int v) {
    for(int i=0;i<9;i++){
        if(sudoku[i][c] == v ) {
            return false;
        }
    }
    return true;
}

bool validInSubSquare(int sudoku[9][9], int r,int c,int v) {
    for(int i=0;i<9;i++){
        if(sudoku[i][c] == v ) {
            return false;
        }
    }
    return true;
}




bool isFull(int sudoku[9][9]) {
    for(int i = 0;i<9;i++) {
        for(int j = 0;j<9;j++) {
            if(sudoku[i][j] == 0)
                return false;
    }
    return true;
}
int solveSudoku(int sudoku[9][9], int row, int column) {
    if(row == 9 && column == 9) {
        if(isFull(sudoku)) {
            // print sudoku
            return true;
        }
        else 
            return false;
    }

    if(column == 9) {
        row +=1;
        column = 0;  
    }


    if(sudoku[row][column] == 0) {
        for(int number=1;number<=9;number++) {
            if(isValid(sudoku,row,column,number)) {
                sudoku[row][column] =  number;
                solveSudoku(sudoku,row,column+1);
                sudoku[row][column] = 0;
            }
        }
    }
}

int main() {
    solveSudoku(sudoku,0,0);
}
