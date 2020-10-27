// Contar el número de palíndromos que existen entre 0 hasta 10^5

int v[10002];

bool isPalindrome(int number) {

}

int solve() {
    for(int i=0;i<100001;i++) {
        v[i] = isPalindrome(i);
    }
}
// 1 2 3 4 5 6 7 8 9 10 11 12 
// 1 1 1 1 1 1 1 1 1 0 1 0
// BIT sum(0,X)
