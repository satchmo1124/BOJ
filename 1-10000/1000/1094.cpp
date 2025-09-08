#include <bits/stdc++.h>
using namespace std;

int popcount(unsigned char n){
    n  = (n >>  1 & 0x55) + (n & 0x55);
    n  = (n >>  2 & 0x33) + (n & 0x33);
    n  = (n >>  4 & 0x0F) + (n & 0x0F);
    return n;
}
int main(){
    int X;
    cin >> X;
    cout << popcount(X);
}
