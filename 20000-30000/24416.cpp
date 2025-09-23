#include <bits/stdc++.h>
using namespace std;

int f[41] = {0,};

int cnt_1 = 0;
int cnt_2 = 0;

void fib(int n){
    if (n == 1 || n == 2) cnt_1++;
    else {fib(n-1);fib(n-2);}
}

void fibonnaci(int n){
    f[1] = f[2] = 1;
    for (int i=3;i<=n;i++){
        f[i] = f[i-1]+f[i];
        cnt_2++;
    }
}

int main(){
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    fib(N); fibonnaci(N);
    cout << cnt_1 << " " << cnt_2;
}