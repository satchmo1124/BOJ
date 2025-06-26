#include <iostream>

using namespace std;


int** G;

int main(){
    int M,N;
    cin >> M >> N;

    G = new int*[M];

    bool is_zero;

    for (int i=0;i<M;i++){
        G[i] = new int[N];
        for (int j=0;j<N;j++){
            cin >> G[i][j];
        }
    }


}