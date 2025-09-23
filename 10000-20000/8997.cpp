#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int G[26][26] = {0,}; // 1 <= N <= 25
int W[26] = {0,};
int D[26] = {0,};




int main(){
    int T;
    cin >> T;
    for (int i=0;i<T;i++){
        int N;
        cin >> N;
        for (int i=1;i<=N;i++){
            cin >> W[i] >> D[i];        
        }
        for (int i=1;i<=N;i++){
            for (int j=1;j<=N;j++){
                cin >> G[i][j];
            }
        }



    }
}
