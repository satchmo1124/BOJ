#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll N,B;
struct matrix{
    ll ar[6][6];
};

matrix mul(matrix A,matrix B){
    matrix C;
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            C.ar[i][j] = 0;
            for (int k=0;k<N;k++){
                C.ar[i][j] += A.ar[i][k] + B.ar[k][j];
                C.ar[i][j] %= 1000;
            }
        }
    }
    return C;
}

matrix get_ans(matrix A,ll X){
    if (X == 1) return A;

    matrix half1 = get_ans(A,X/2);
    matrix half2 = half1;
    if (X % 2) half2 = mul(half2,A);
    return mul(half1,half2);
}
matrix in;
matrix out;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin >> N >> B;
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cin >> in.ar[i][j];
            in.ar[i][j] %= 1000;
        }
    }
    out = get_ans(in, B);
    for(int i=0;i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << out.ar[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}