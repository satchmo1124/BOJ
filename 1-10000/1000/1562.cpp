#include <bits/stdc++.h>
#define ll long long 
using namespace std;

/*
dp[i][j][k] : 방문여부, 길이, 현재 뒷자리
*/

int main(){
    int N;
    int M = 1e9;
    cin >> N;
    
    ll dp[1024][101][10] = {0,};

    for (int k=1;k<10;k++){
        dp[1<<k][1][k] = 1;
    }
        

    for (int j = 2;j <= N; j++){
        for (int k = 0; k < 10; k++ ){
            for (int i=0;i<1024;i++){
                if (k == 0){
                    dp[i | (1 << k)][j][k] += dp[i][j-1][1];
                }
                else if (k == 9){
                    dp[i | (1 << k)][j][k] += dp[i][j-1][8];

                }
                else{
                    dp[i | (1 << k)][j][k] += dp[i][j-1][k+1];
                    dp[i | (1 << k)][j][k] += dp[i][j-1][k-1];
                }
                dp[i | (1 << k)][j][k] %= M;
            }
        }
    }
    ll res = 0;
    for (int k=0;k<10;k++){
        res += dp[1023][N][k];
        res %= M;
    }
    cout << res;
}
/*

Top-Down으로 할 경우 비트가 순서를 무시할 수 있다. 
즉 11111 이라 했을때 여기서 그 아래 level의 dp를 탐색할때 45432의 경우, 중간 4를 빼먹은, 즉 계단수가 아닌 수도 탐색할 위험이 있다. 


만약 Top-Down 했는데 안 된다면 Bottom-Up으로도 해보는 것도 나쁘지 않을듯?
*/

/*

int N;
    cin >> N;
    
    for (int i=2;i<=N;i++){
        for (int j=0;j<10;j++){
            dp[i][j] = -1;
        }
    }
    dp[1][0] = 0;
    for (int j=1;j<10;j++){
        dp[1][j] = 1;
    }

    ll res = 0;
    for (int i=0;i<10;i++){
        res += DP(N,i);
        res %= M;
    }
    cout << res;

ll DP(int len,int last_num){
    if (dp[len][last_num] != -1) return dp[len][last_num];
    dp[len][last_num] = 0;
    if (last_num == 9){
        dp[len][last_num] = DP(len-1,8);
    }
    else if (last_num == 0){
        dp[len][last_num] = DP(len-1,1);
    }
    else{
        dp[len][last_num] = DP(len-1,last_num-1) + DP(len-1,last_num+1);
    }
    dp[len][last_num] %= M;
    return dp[len][last_num];
}
*/