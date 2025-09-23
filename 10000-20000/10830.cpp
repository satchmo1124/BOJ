#include <bits/stdc++.h>
#define ll long long
using namespace std;

vector<vector<int>> DP(vector<vector<int>>A,int N,ll B){
    if (B == 1){
        return A;
    }
    vector<vector<int>>half = DP(A,N,B/2);


    vector<vector<int>>tmp(N,vector<int>(N,0));
    vector<vector<int>>res(N,vector<int>(N,0));

    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            for (int k=0;k<N;k++){
                tmp[i][j] += half[i][k] * half[k][j];
                tmp[i][j] %= 1000;
            }
        }
    }
    if (B % 2 != 0){
        for (int i=0;i<N;i++){
            for (int j=0;j<N;j++){
                for (int k=0;k<N;k++){
                    res[i][j] += tmp[i][k] * A[k][j];    
                    res[i][j] %= 1000;
                }
            }
        }
        return res;
    }
    return tmp;
} 

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    ll B;
    cin >> N >> B;

    vector<vector<int>>A(N,vector<int>(N,0));
    
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cin >> A[i][j];
            A[i][j] %= 1000;
        }
    }
    vector<vector<int>>res = DP(A,N,B);
    for (int i=0;i<N;i++){
        for (int j=0;j<N;j++){
            cout << res[i][j] << " ";
        }
        cout << '\n';
    }
}

