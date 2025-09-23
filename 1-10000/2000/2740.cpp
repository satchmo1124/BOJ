#include <bits/stdc++.h>
using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N,R = 1e9;
    cin >> N;

    int dp[101][10] = {0,};

    for (int i=1;i<=9;i++){
        dp[1][i] = 1;
    }

    for (int i=2;i<=N;i++){
        dp[i][0] = dp[i-1][1];

        for (int j=1;j<=8;j++){
            dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % R;
        }
        dp[i][9] = dp[i-1][8];
    }
    int res = 0;
    for (int j=0;j<=9;j++){
        res += dp[N][j];
        res %= R;
    }
    cout << res;
}
