#include <bits/stdc++.h>
typedef long long ll;
typedef unsigned long long ull;
using namespace std;

ll power_modular(__int128_t x,ll y,__int128_t M){
    ll res = 1;
    while (y > 0){
        if (y & 1){
            res = (__int128_t)res * x % M;
        }
        x =  x * x % M;
        y >>= 1;
    }
    return res;
}

int main(){
    ll A,X,M;
    cin >> A >> X;
    M = 1000000007;
    cout << power_modular(A,X,M);
}