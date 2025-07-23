#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll popcount(unsigned ll n){
    n  = (n >>  1 & 0x5555555555555555) + (n & 0x5555555555555555);
    n  = (n >>  2 & 0x3333333333333333) + (n & 0x3333333333333333);
    n  = (n >>  4 & 0x0F0F0F0F0F0F0F0F) + (n & 0x0F0F0F0F0F0F0F0F);
    n  = (n >>  8 & 0x00FF00FF00FF00FF) + (n & 0x00FF00FF00FF00FF);
    n  = (n >> 16 & 0x0000FFFF0000FFFF) + (n & 0x0000FFFF0000FFFF);
    n  = (n >> 32 & 0x00000000FFFFFFFF) + (n & 0x00000000FFFFFFFF);

    return n;
}
int main(){
    ll k;
    cin >> k;
    ll cnt = popcount(k-1);
    if (cnt % 2 == 0) cout << 0;
    else cout << 1; 
}

/*
cmp = 2, 
while (cmp <= k){
         cnt += !(k & cnt);
         cmp <<= 1; 
    }
*/
