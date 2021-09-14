#include <bits/stdc++.h> 
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std; 

void solve(string number, int size, int ones) {

    if(number.size() == size) {
        if(ones == 0){
            cout<<number<<endl;
        }
       return; 
    }
    solve(number + "0", size, ones);
    solve(number + "1", size, ones-1);
}

int main() {
    input;
    output;
    int tcases;
    cin>>tcases;
    while(tcases--) {
        int N,H;
        cin>>N>>H;
        solve("", N, H);
    }

}