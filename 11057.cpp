#include <iostream>
#include <string>

using namespace std;

int N;


/*
dp[i][j] : 
이전에 주어진 수가 j일때, i길이의 오르막 수 개수
*/
int dp[1001][10] = {0,};
/*
DP(L,prev_num) :
이전에 주어진 수가 prev_num일때, L길이의 오르막 수의 개수
*/
int DP(int L,int prev_num){
    if (dp[L][prev_num] != -1) {
        return dp[L][prev_num];
    }
    dp[L][prev_num] = 0;
    for (int i=prev_num;i<=9;i++){
        dp[L][prev_num] += DP(L-1,i);
    }
    dp[L][prev_num] %= 10007;
    return dp[L][prev_num];       
}

int main(){
    cin >> N;    

    for (int i=2;i<=N;i++){
        for (int j=0;j<=9;j++){
            dp[i][j] = -1;
        }
    }
    for (int j=0;j<=9;j++){
        dp[1][j] = 10 - j;
    }


    cout << DP(N,0);   
}