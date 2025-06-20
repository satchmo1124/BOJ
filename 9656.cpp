#include <iostream>

using namespace std;

bool DP[1000] = {0,};

int main(){
    int N;
    cin >> N;
    DP[1] = false;
    DP[2] = true;
    DP[3] = false;

    for (int i=4;i<=N;i++){
        if (DP[i-1] && DP[i-3] ){
            DP[i] = false;
        }
        else{
            DP[i] = true;
        }
    }
    if (DP[N]) cout << "SK";
    else cout << "CY";
}