#include <iostream>


using namespace std;

int *dp;

int main(){
    int N;
    cin >> N;

    dp = new int[3*N+1];
    for (int i=1;i<=3*N+1;i++){
        dp[i] = -1;
    }
    dp[1] = 0;

    for (int i=1;i<=N;i++){
        if (dp[3*i] == -1 || dp[3*i] > dp[i] + 1){
            dp[3*i] = dp[i] + 1;
        }
        if (dp[2*i] == -1 || dp[2*i] > dp[i] + 1){
            dp[2*i] = dp[i] + 1;
        }
        if (dp[i+1] == -1 || dp[i+1] > dp[i] + 1){
            dp[i+1] = dp[i] + 1;
        }
    }
    cout << dp[N];
}