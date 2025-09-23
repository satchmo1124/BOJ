#include <bits/stdc++.h>
#define ll long long
using namespace std;

/*
Used c8216's representation from problem_id = 10830  
*/

struct matrix{
    ll arr[2][2];
};

matrix mul(matrix A,matrix B){
    matrix C;
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            C.arr[i][j] = 0;
            for (int k=0;k<2;k++){
                C.arr[i][j] += A.arr[i][k] * B.arr[k][j];
                C.arr[i][j] %= 1'000'000'007;
            }
        }
    }
    return C;
}

matrix mat_pow(matrix A,ll N){
    if (N == 1) return A;
    
    matrix half1 = mat_pow(A,N/2);
    matrix half2 = half1;

    if (N % 2) half2 = mul(half2,A);
    return mul(half1,half2);

}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll N,Q,R;
    cin >> N;

    Q = N / 4; R = N % 4;
    
    matrix F,P,out;
    F.arr[0][0] = 0; F.arr[0][1] = 1;
    F.arr[1][0] = 1; F.arr[1][1] = 2;

    P.arr[0][0] = 2; P.arr[0][1] = 3;
    P.arr[1][0] = 3; P.arr[1][1] = 5;

    if (Q > 0){
        P = mat_pow(P,Q);
        out = mul(F,P);
    }
    else{
        out = F;
    }
    for (int i=0;i<2;i++){
        for (int j=0;j<2;j++){
            if (2*i+j == R) {
                cout << out.arr[i][j];
            }
        }
    }
}