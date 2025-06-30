#include <iostream>
#define max(a,b) ( ((a)>(b)) ? (a) : (b) ) 
using namespace std;

int L[21];
int J[21];

int N;

int dp[22][101] = {0,};



int MJ(int i,int l){
    if (dp[i][l] != -1) return dp[i][l];
    if (l-L[i] <= 0 ) {
        dp[i][l] = MJ(i+1,l);
    } 
    else{
        dp[i][l] = max(J[i] + MJ(i+1,l-L[i]), MJ(i+1,l));
    }
    return dp[i][l];
}

int main(){
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> L[i];
        
    }
     for (int i=1;i<=N;i++){
        cin >> J[i];
    }
    for (int i=1;i<=N;i++){
        for (int j=1;j<=100;j++){
            dp[i][j] = -1;
        }
    }
    cout << MJ(1,100);
}