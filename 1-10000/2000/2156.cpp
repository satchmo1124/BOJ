#include <iostream>
#define max(a,b) ((a) > (b) ? (a) : (b));
using namespace std;

int v[10001] = {0,};
int dp[10001][3] = {0,};

/*
dp[i][cnt] = i번째 인덱스 전까지 연속으로 cnt번 마셨을 때 i~N까지 주어진 포도주에 대해 최대로 마실 수 있는 포도주의 양  
*/

int DP(int i,int cnt){
    if (dp[i][cnt] != -1) return dp[i][cnt];

    if (cnt == 2) {
        dp[i][cnt] = DP(i+1,0);
    }
    else{
        dp[i][cnt] = max(v[i] + DP(i+1,cnt+1),DP(i+1,0));
    }
    return dp[i][cnt];
}

int main(){
    int N;
    cin >> N;
    for (int i=1;i<=N;i++) {
        cin >> v[i];
        dp[i][0] = dp[i][1] = dp[i][2] = -1;
    }
    dp[N][0] = dp[N][1] = v[N];
    dp[N][2] = 0;

    cout << DP(1,0);
}