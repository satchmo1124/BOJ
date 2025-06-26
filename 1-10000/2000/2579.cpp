#include <iostream>

#define max(a,b) (((a) > (b)) ? (a) : (b))

using namespace std;

/*
i에서 시작해서 N까지 계단을 오를 때 얻을 수 있는 총 점수의 최댓값
*/
int stair[301] = {0,};
int DP[301][2] = {0,}; 

int N;


int Score(int i,bool once){
    if (DP[i][once] || i == N) return DP[i][once];

    DP[i][once] = stair[i];

    if (once == true) {
        if (i+2 <= N){
            DP[i][1] += Score(i+2,false);
        }
        else{
            DP[i][1] = 0;
        }
    }
    else{
        if (i+1 <= N && i+2 <= N){
            if (i==0){
                DP[i][0] += max(Score(i+1,false),Score(i+2,false));
            }
            else{
                DP[i][0] += max(Score(i+1,true),Score(i+2,false));
            }
        }
        else if (i+1 <= N && i+2 > N){
            DP[i][0] += Score(i+1,true);
        }
    }
    return DP[i][once];
}

int main(){
    cin >> N;
    for (int i=1;i<=N;i++){
        cin >> stair[i];
    }
    DP[N][0] = DP[N][1] = stair[N];
    cout << Score(0,false);
}