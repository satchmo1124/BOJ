#include <iostream>
#define ll long long 
using namespace std;

int mod;

ll Pow(int C,int n){
    if (n == 1) return C;

    ll half = Pow(C,n/2);

    if (n%2 == 0){
        return half * half %mod;
    }
    else{
        return (half * half % mod) * C % mod;
    }
}

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    mod = C;
    cout << Pow(A,B) % C;
}