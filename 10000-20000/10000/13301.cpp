#include <iostream>

#define ll long long 

using namespace std;

ll dp[81] = {0,};

int main(){
    int N;
    cin >> N;
    dp[1] = dp[2] = 1;
    for (int i=3;i<=N;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    ll res = dp[N] * 4 + dp[N-1] * 2;

    cout << res;
}