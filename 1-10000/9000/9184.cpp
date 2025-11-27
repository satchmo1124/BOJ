#include <bits/stdc++.h>
using namespace std;

int dp[101][101][101];

int W(int a,int b,int c){
    if (dp[a][b][c]) return dp[a][b][c];

    if (a > 70 || b > 70 || c > 70){
        dp[a][b][c] = W(70,70,70);
    }
    else if (a < b && b < c){
        dp[a][b][c] = W(a,b,c-1) + W(a,b-1,c-1) - W(a,b-1,c);
    }
    else{
        dp[a][b][c] = W(a-1,b,c) + W(a-1,b-1,c) + 
        W(a-1,b,c-1) - W(a-1,b-1,c-1);
    }
    return dp[a][b][c];
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a,b,c;

    for (int i=0;i<101;i++){
        for (int j=0;j<101;j++){
            for (int k=0;k<101;k++){
                dp[i][j][k] = 1;         
            }
        }
    }
    for (int i=51;i<101;i++){
        for (int j=51;j<101;j++){
            for (int k=51;k<101;k++){
                dp[i][j][k] = 0;
            }
        }
    }

    while(true){
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a <<", " << b << ", " << c << ") = " << W(a+50,b+50,c+50) << '\n';
    }
}

