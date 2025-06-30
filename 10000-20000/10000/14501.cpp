#include <iostream>
#define max(a,b) (((a) > (b)) ? (a) : (b))
using namespace std;

int N;


int T[16] = {0,};
int P[16] = {0,};

int dp[16] = {0,};


int DP(int n){
    if (dp[n] != -1) return dp[n];

    if (n + T[n] <= N) {
        dp[n] = max(P[n]+DP(n+T[n]),DP(n+1));
    }
    else if (n + T[n] == N+1) {
        dp[n] = max(P[n],DP(n+1));
    }
    else{
        dp[n] = DP(n+1);
    }
    return dp[n];
}

int main(){
    cin >> N;
    
    int t,p;
    for (int i=1;i<=N;i++){
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
        dp[i] = -1;
    }

    if (T[N] == 1) {
        dp[N] = P[N];
    }
    else{
        dp[N] = 0;
    }

    cout << DP(1);
}
