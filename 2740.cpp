#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N,M,K;
    cin >> N >> M;
    int A[100][100] = {0,};
    int B[100][100] = {0,};

    for (int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for (int j=0;j<M;j++){
        for (int k=0;k<K;k++){
            cin >> B[j][k];
        }
    }
    for (int i=0;i<N;i++){
        for (int k=0;k<K;k++){
            int res = 0;
            for (int j=0;j<M;j++){
                res += A[i][j] * B[j][k];
            }
            cout << res << " ";
        }
        cout << '\n';
    }
}